/*
  ==============================================================================

    AllPass Filter.h
    Created: 9 Dec 2016 9:49:11am
    Author:  Anthony

  ==============================================================================
*/

#ifndef ALLPASS_FILTER_H_INCLUDED
#define ALLPASS_FILTER_H_INCLUDED
#include "../JuceLibraryCode/JuceHeader.h"

class AllPassFilter
{
public:
	AllPassFilter()noexcept;
	void setSize(const int size);
	void clear()noexcept;
	float process(const float input)noexcept;

private:
	HeapBlock<float> buffer;
	int bufferSize, bufferIndex;

	JUCE_DECLARE_NON_COPYABLE(AllPassFilter)
};



#endif  // ALLPASS_FILTER_H_INCLUDED
