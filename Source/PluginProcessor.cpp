/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
ReverbAudioProcessor::ReverbAudioProcessor() : m_knob1(0),
m_knob2(0),
m_knob3(0),
m_knob4(0),
m_knob5(0),
m_knob6(0),
m_knob7(0)
{
	m_fFeedback = 0;
	m_fWetLevel = 0;
	m_fGain = 0;

	m_fGain = m_knob1;
	m_fDelayTime = m_knob2;
	m_fFeedback = m_knob3;
	m_fDamping = m_knob4;
	m_fRoomSize = m_knob5;
	m_fWidth = m_knob6;
	m_fWetLevel = m_knob7;

	PDelayL = PreDelay();
	PDelayL.setMaxDelay(m_sampleRate, 0.500);
	PDelayL.setDelayTime(m_sampleRate, m_fDelayTime);
	PDelayL.setGainLevel(m_fGain);
	PDelayL.setFeedback(m_fFeedback);
	PDelayL.setPlayheads();

	PDelayR = PreDelay();
	PDelayR.setMaxDelay(m_sampleRate, 0.500);
	PDelayR.setDelayTime(m_sampleRate, m_fDelayTime);
	PDelayR.setGainLevel(m_fGain);
	PDelayR.setFeedback(m_fFeedback);
	PDelayR.setPlayheads();
	
	Reverb1.setSampleRate(m_sampleRate);
	Reverb1.setDamp(m_fDamping);
	Reverb1.setRoomSize(m_fRoomSize);
	Reverb1.setWidth(m_fWidth);
	Reverb1.setWetDryMix(m_fWetLevel);
	Reverb1.setParameters();
}

ReverbAudioProcessor::~ReverbAudioProcessor()
{
}

//==============================================================================
const String ReverbAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

int ReverbAudioProcessor::getNumParameters()
{
	return totalNumParams;
}

float ReverbAudioProcessor::getParameter(int index)
{
	switch (index) {
	case knob1Param: return m_knob1;
	case knob2Param: return m_knob2;
	case knob3Param: return m_knob3;
	case knob4Param: return m_knob4;
	case knob5Param: return m_knob5;
	case knob6Param: return m_knob6;
	case knob7Param: return m_knob7;
	default: return 0.0;
	}
}

void ReverbAudioProcessor::setParameter(int index, float newValue)
{
	switch (index) {
		//Gain Knob
	case knob1Param: m_knob1 = newValue;
		m_fGain = m_knob1;

		PDelayL.setGainLevel(m_fGain);
		PDelayR.setGainLevel(m_fGain); break;

		//Delay Time Knob
	case knob2Param: m_knob2 = newValue;
		m_fDelayTime = m_knob2;

		PDelayL.setDelayTime(m_sampleRate, m_fDelayTime);
		PDelayL.setPlayheads();

		PDelayR.setDelayTime(m_sampleRate, m_fDelayTime);
		PDelayR.setPlayheads(); break;

		//Feedback Knob
	case knob3Param: m_knob3 = newValue;
		m_fFeedback = m_knob3;

		PDelayL.setFeedback(m_fFeedback);
		PDelayR.setFeedback(m_fFeedback); break;

		//Damping Knob
	case knob4Param: m_knob4 = newValue;
		m_fDamping = m_knob4;

		Reverb1.setDamp(m_fDamping); break;

		//Roomsize Knob
	case knob5Param: m_knob5 = newValue;
		m_fRoomSize = m_knob5;

		Reverb1.setRoomSize(m_fRoomSize); break;

		//Width Knob    
	case knob6Param: m_knob6 = newValue;
		m_fWidth = m_knob6;

		Reverb1.setWidth(m_fWidth); break;

		//Wet Dry Mix Knob
	case knob7Param: m_knob7 = newValue;
		m_fWetLevel = m_knob7;

		Reverb1.setWetDryMix(m_fWetLevel); break;

	default: break;
	}
}

const String ReverbAudioProcessor::getParameterName(int index)
{
	switch (index){
	case knob1Param: return "Gain";
	case knob2Param: return "Delay Time";
	case knob3Param: return "Feedback";
	case knob4Param: return "Damping";
	case knob5Param: return "Room Size";
	case knob6Param: return "Width";
	case knob7Param: return "Wet / Dry Mix";
	default: return String::empty;
}
}

const String ReverbAudioProcessor::getParameterText(int index)
{
	return String(getParameter(index), 2);
}

bool ReverbAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool ReverbAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

double ReverbAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int ReverbAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int ReverbAudioProcessor::getCurrentProgram()
{
    return 0;
}

void ReverbAudioProcessor::setCurrentProgram (int index)
{
}

const String ReverbAudioProcessor::getProgramName (int index)
{
    return String();
}

void ReverbAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void ReverbAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
	m_sampleRate = sampleRate;
	m_fGain = m_knob1;
	m_fDelayTime = m_knob2;
	m_fFeedback = m_knob3;
	m_fDamping = m_knob4;
	m_fRoomSize = m_knob5;
	m_fWidth = m_knob6;
	m_fWetLevel = m_knob7;

	PDelayL.setMaxDelay(m_sampleRate, 0.500);
	PDelayL.setDelayTime(m_sampleRate, m_fDelayTime);
	PDelayL.setGainLevel(m_fGain);
	PDelayL.setFeedback(m_fFeedback);
	PDelayL.prepareToPlay();
	PDelayL.setPlayheads();

	PDelayR.setMaxDelay(m_sampleRate, 0.500);
	PDelayR.setDelayTime(m_sampleRate, m_fDelayTime);
	PDelayR.setGainLevel(m_fGain);
	PDelayR.setFeedback(m_fFeedback);
	PDelayR.prepareToPlay();
	PDelayR.setPlayheads();

	Reverb1.setSampleRate(m_sampleRate);
	Reverb1.setDamp(m_fDamping);
	Reverb1.setRoomSize(m_fRoomSize);
	Reverb1.setWidth(m_fWidth);
	Reverb1.setWetDryMix(m_fWetLevel);
	Reverb1.setParameters();
}

void ReverbAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool ReverbAudioProcessor::setPreferredBusArrangement (bool isInput, int bus, const AudioChannelSet& preferredSet)
{
    // Reject any bus arrangements that are not compatible with your plugin

    const int numChannels = preferredSet.size();

   #if JucePlugin_IsMidiEffect
    if (numChannels != 0)
        return false;
   #elif JucePlugin_IsSynth
    if (isInput || (numChannels != 1 && numChannels != 2))
        return false;
   #else
    if (numChannels != 1 && numChannels != 2)
        return false;

    if (! AudioProcessor::setPreferredBusArrangement (! isInput, bus, preferredSet))
        return false;
   #endif

    return AudioProcessor::setPreferredBusArrangement (isInput, bus, preferredSet);
}
#endif

void ReverbAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
	const int totalNumInputChannels = getTotalNumInputChannels();
	int N = getTotalNumOutputChannels();
	int bufsize = buffer.getNumSamples();
	float* channelDataL = buffer.getWritePointer(0);
	float* channelDataR = buffer.getWritePointer(1);

	for (int channel = 0; channel < totalNumInputChannels; ++channel){
		float* channelData = buffer.getWritePointer(channel);


		for (int n = 0; n<buffer.getNumSamples(); ++n){
			if (channel == 0)
				channelData[n] = PDelayL.process(channelData[n]);

			else if (channel == 1)
				channelData[n] = PDelayR.process(channelData[n]);
		}
	}

	Reverb1.processStereo(channelDataL, channelDataR, bufsize);

	for (int i = getNumInputChannels(); i < getNumOutputChannels(); ++i)
		buffer.clear(i, 0, buffer.getNumSamples());
}

//==============================================================================
bool ReverbAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* ReverbAudioProcessor::createEditor()
{
    return new ReverbAudioProcessorEditor (*this);
}

//==============================================================================
void ReverbAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void ReverbAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new ReverbAudioProcessor();
}
