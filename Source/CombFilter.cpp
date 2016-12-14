/*
  ==============================================================================

    CombFilter.cpp
    Created: 9 Dec 2016 9:49:19am
    Author:  Anthony

  ==============================================================================
*/

#include "CombFilter.h"

CombFilter::CombFilter() : bufferSize(0), bufferIndex(0), last(0)
{
}

// Set buffer size based on input buffer size
void CombFilter::setSize(const int size)
{
	if (size != bufferSize)
	{
		bufferIndex = 0;
		buffer.malloc((size_t)size);
		bufferSize = size;
	}

	clear();
}

// Reset buffer
void CombFilter::clear()
{
	last = 0;
	buffer.clear((size_t)bufferSize);
}

// Process Comb filter 
float CombFilter::process(const float input, const float damp, const float feedbackLevel)
{
	const float output = buffer[bufferIndex];
	last = (output * (1.0f - damp)) + (last * damp);

	float temp = input + (last * feedbackLevel);
	buffer[bufferIndex] = temp;
	bufferIndex = (bufferIndex + 1) % bufferSize;
	return output;
}