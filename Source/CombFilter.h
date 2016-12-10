/*
  ==============================================================================

    CombFilter.h
    Created: 9 Dec 2016 9:49:19am
    Author:  Anthony

  ==============================================================================
*/

#ifndef COMBFILTER_H_INCLUDED
#define COMBFILTER_H_INCLUDED
#include "../JuceLibraryCode/JuceHeader.h"

class CombFilter
{
public:
	CombFilter();
	void setSize(const int size);
	void clear();
	float process(const float input, const float damp, const float feedbackLevel);

private:
	HeapBlock<float> buffer;
	int bufferSize, bufferIndex;
	float last;
};



#endif  // COMBFILTER_H_INCLUDED
