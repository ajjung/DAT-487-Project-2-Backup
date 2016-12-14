/*
  ==============================================================================

    Reverb.cpp
    Created: 9 Dec 2016 9:20:42am
    Author:  Anthony

  ==============================================================================
*/

#include "Reverb.h"

Reverberation::Reverberation() : m_wet(0),
m_damping(0),
m_roomSize(0),
m_width(0)
{
}

void Reverberation::setWet(float wet)
{
	m_wet = wet * .01;
}

void Reverberation::setDamp(float damp)
{
	m_damping = damp * .01;
}

void Reverberation::setRoomSize(float room)
{
	m_roomSize = room * .01;
}

void Reverberation::setWidth(float width)
{
	m_width = width * .01;
}

void Reverberation::setParameters()
{
	const float wet = m_wet;
	dryGain.setValue((1.0f - m_wet));
	wetGain1.setValue(0.5f * wet * (1.0f + m_width));
	wetGain2.setValue(0.5f * wet * (1.0f - m_width));

	updateDamping();
}

// Adjust coefficients calculated at 44.1khz to new sample rate
void Reverberation::setSampleRate(const double sampleRate)
{
	static const short combTunings[] = { 1116, 1188, 1277, 1356, 1422, 1491, 1557, 1617 }; // (at 44100Hz)
	static const short allPassTunings[] = { 556, 441, 341, 225 };
	const int stereoSpread = 23;
	const int intSampleRate = (int)sampleRate;

	for (int i = 0; i < numCombs; ++i)
	{
		comb[0][i].setSize((intSampleRate * combTunings[i]) / 44100);
		comb[1][i].setSize((intSampleRate * (combTunings[i] + stereoSpread)) / 44100);
	}

	for (int i = 0; i < numAllPasses; ++i)
	{
		allPass[0][i].setSize((intSampleRate * allPassTunings[i]) / 44100);
		allPass[1][i].setSize((intSampleRate * (allPassTunings[i] + stereoSpread)) / 44100);
	}

	const double smoothTime = 0.01;
	damping.reset(sampleRate, smoothTime);
	feedback.reset(sampleRate, smoothTime);
	dryGain.reset(sampleRate, smoothTime);
	wetGain1.reset(sampleRate, smoothTime);
	wetGain2.reset(sampleRate, smoothTime);
}

// Clear reverb buffer
void Reverberation::reset()
{
	for (int j = 0; j < numChannels; ++j)
	{
		for (int i = 0; i < numCombs; ++i)
			comb[j][i].clear();

		for (int i = 0; i < numAllPasses; ++i)
			allPass[j][i].clear();
	}
}

// Process incoming blocks of data into comb and allpass filters
void Reverberation::processStereo(float* const left, float* const right, const int numSamples)
{
	setParameters();
	for (int i = 0; i < numSamples; ++i)
	{
		const float input = (left[i] + right[i]) * 0.007f;
		float outL = 0, outR = 0;

		const float damp = damping.getNextValue();
		const float feedbck = feedback.getNextValue();

		for (int j = 0; j < numCombs; ++j)
		{
			outL += comb[0][j].process(input, damp, feedbck);
			outR += comb[1][j].process(input, damp, feedbck);
		}

		for (int j = 0; j < numAllPasses; ++j)
		{
			outL = allPass[0][j].process(outL);
			outR = allPass[1][j].process(outR);
		}

		const float dry = dryGain.getNextValue();
		const float wet1 = wetGain1.getNextValue();
		const float wet2 = wetGain2.getNextValue();

		left[i] = outL * wet1 + outR * wet2 + left[i] * dry;
		right[i] = outR * wet1 + outL * wet2 + right[i] * dry;
	}
}

// Update new parameters
void Reverberation::updateDamping()
{
	const float roomScaleFactor = 0.28f;
	const float roomOffset = 0.7f;
	const float dampScaleFactor = 0.4f;

	setDamping(m_damping * dampScaleFactor, m_roomSize * roomScaleFactor + roomOffset);
}

// Update damping based on parameters
void Reverberation::setDamping(const float dampingToUse, const float roomSizeToUse)
{
	damping.setValue(dampingToUse);
	feedback.setValue(roomSizeToUse);
}