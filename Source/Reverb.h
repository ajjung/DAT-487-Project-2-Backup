/*
  ==============================================================================

    Reverb.h
    Created: 9 Dec 2016 9:20:42am
    Author:  Anthony

  ==============================================================================
*/

#ifndef REVERB_H_INCLUDED
#define REVERB_H_INCLUDED
#include "AllPass Filter.h"
#include "CombFilter.h"

class Reverberation
{
public:
	Reverberation();
	void setWet(float wet);
	void setDamp(float damp);
	void setRoomSize(float room);
	void setWidth(float width);
	void setParameters();
	void setSampleRate(const double sampleRate);
	void reset();
	void processStereo(float* const left, float* const right, const int numSamples);
	void updateDamping();
	void setDamping(const float dampingToUse, const float roomSizeToUse);
	
	
//========================================================================================
private:
	enum { numCombs = 8, numAllPasses = 4, numChannels = 2 };
	float gain;
	float m_wet, m_damping, m_roomSize, m_width;
	CombFilter comb[numChannels][numCombs];
	AllPassFilter allPass[numChannels][numAllPasses];
	LinearSmoothedValue<float> damping, feedback, dryGain, wetGain1, wetGain2;
};

#endif  // REVERB_H_INCLUDED
