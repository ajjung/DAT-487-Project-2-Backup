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
	AllPassFilter();
	void setSize(const int size);
	void clear();
	float process(const float input);

private:
	HeapBlock <float> buffer;
	int bufferSize, bufferIndex;
};



#endif  // ALLPASS_FILTER_H_INCLUDED
