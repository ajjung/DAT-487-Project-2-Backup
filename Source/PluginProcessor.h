/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#ifndef PLUGINPROCESSOR_H_INCLUDED
#define PLUGINPROCESSOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "PreDelay.h"
#include "Reverb.h"

//==============================================================================
/**
*/
class ReverbAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    ReverbAudioProcessor();
    ~ReverbAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool setPreferredBusArrangement (bool isInput, int bus, const AudioChannelSet& preferredSet) override;
   #endif

    void processBlock (AudioSampleBuffer&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

	int getNumParameters() override;
	float getParameter(int index) override;
	void setParameter(int index, float newValue) override;
	const String getParameterName(int index) override;
	const String getParameterText(int index) override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

	enum Parameters{
		knob1Param,
		knob2Param,
		knob3Param,
		knob4Param,
		knob5Param,
		knob6Param,
		knob7Param,
		totalNumParams
	};

private:

	// raw Vars
	float m_knob1;
	float m_knob2;
	float m_knob3;
	float m_knob4;
	float m_knob5;
	float m_knob6;
	float m_knob7;

	float m_sampleRate;
	//cooked variables
	float m_fGain;
	float m_fDelayTime;
	float m_fFeedback;
	float m_fDamping;
	float m_fRoomSize;
	float m_fWidth;
	float m_fWetLevel;

	PreDelay PDelayL;
	PreDelay PDelayR;
	Reverberation Reverb1;
	//Reverb Reverb1;
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ReverbAudioProcessor)
};


#endif  // PLUGINPROCESSOR_H_INCLUDED
