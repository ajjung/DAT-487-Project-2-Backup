/*
  ==============================================================================

    CombFilter.cpp
    Created: 9 Dec 2016 9:49:19am
    Author:  Anthony

  ==============================================================================
*/

#include "CombFilter.h"

CombFilter::CombFilter() noexcept: bufferSize(0), bufferIndex(0), last(0)
{
}

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

void CombFilter::clear()noexcept
{
	last = 0;
	buffer.clear((size_t)bufferSize);
}

float CombFilter::process(const float input, const float damp, const float feedbackLevel)noexcept
{
	const float output = buffer[bufferIndex];
	last = (output * (1.0f - damp)) + (last * damp);

	float temp = input + (last * feedbackLevel);
	buffer[bufferIndex] = temp;
	bufferIndex = (bufferIndex + 1) % bufferSize;
	return output;
}