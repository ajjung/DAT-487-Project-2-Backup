/*
  ==============================================================================

    Reverb.h
    Created: 9 Dec 2016 9:20:42am
    Author:  Anthony

  ==============================================================================
*/

#ifndef REVERB_H_INCLUDED
#define REVERB_H_INCLUDED
#include "../JuceLibraryCode/JuceHeader.h"
#include "AllPass Filter.h"
#include "CombFilter.h"

class Reverberation
{
public:
	Reverberation();
	void setWetDryMix(float wet);
	void setDamp(float damp);
	void setRoomSize(float room);
	void setWidth(float width);
	void setParameters();
	void setSampleRate(const double sampleRate);
	void reset();
	void processStereo(float* const left, float* const right, const int numSamples)noexcept;
	void updateDamping()noexcept;
	void setDamping(const float dampingToUse, const float roomSizeToUse)noexcept;
	
//========================================================================================
private:

	enum { numCombs = 8, numAllPasses = 4, numChannels = 2 };

	float gain;
	float m_wetDryMix, m_damping, m_roomSize, m_width;
	CombFilter comb[numChannels][numCombs];
	AllPassFilter allPass[numChannels][numAllPasses];
	LinearSmoothedValue<float> damping, feedback, dryGain, wetGain1, wetGain2;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Reverberation)
};

#endif  // REVERB_H_INCLUDED
