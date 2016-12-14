/*
  ==============================================================================

    AllPass Filter.cpp
    Created: 9 Dec 2016 9:49:11am
    Author:  Anthony

  ==============================================================================
*/

#include "AllPass Filter.h"

AllPassFilter::AllPassFilter() : bufferSize(0), bufferIndex(0)
{
}

// Allocate buffer based on input buffer size
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

// Reset buffer
void AllPassFilter::clear()
{
	buffer.clear((size_t)bufferSize);
}

// Process input buffer through all pass
float AllPassFilter::process(const float input)
{
	const float bufferedValue = buffer[bufferIndex];
	float temp = input + (bufferedValue * 0.5f);
	buffer[bufferIndex] = temp;
	bufferIndex = (bufferIndex + 1) % bufferSize;
	return bufferedValue - input;
}