/*
  ==============================================================================

    AllPass Filter.cpp
    Created: 9 Dec 2016 9:49:11am
    Author:  Anthony

  ==============================================================================
*/

#include "AllPass Filter.h"

AllPassFilter::AllPassFilter()noexcept : bufferSize(0), bufferIndex(0)
{
}

void AllPassFilter::setSize(const int size)
{
	if (size != bufferSize)
	{
		bufferIndex = 0;
		buffer.malloc((size_t)size);
		bufferSize = size;
	}

	clear();
}

void AllPassFilter::clear()noexcept
{
	buffer.clear((size_t)bufferSize);
}

float AllPassFilter::process(const float input)noexcept
{
	const float bufferedValue = buffer[bufferIndex];
	float temp = input + (bufferedValue * 0.5f);
	buffer[bufferIndex] = temp;
	bufferIndex = (bufferIndex + 1) % bufferSize;
	return bufferedValue - input;
}