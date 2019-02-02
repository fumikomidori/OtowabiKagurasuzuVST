/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "../JuceLibraryCode/JuceHeader.h"

    //OtoSynth synth; 
    double hostSampleRate;
    Synthesiser synth;
    SynthesiserSound::Ptr sound;
    AudioFormatManager audioFormatManager;

//==============================================================================
OtowabiKagurasuzuAudioProcessor::OtowabiKagurasuzuAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{
    int maxNumVoices = 16;
    for (int i = 0; i < maxNumVoices; ++i){
        synth.addVoice (new SamplerVoice());
    }

    audioFormatManager.registerBasicFormats();
    
    // for mac

    loadNewSample(BinaryData::suzu_one_01_wav, BinaryData::suzu_one_01_wavSize, 48, 1, 48, "suzu_one_01_wav");
    loadNewSample(BinaryData::suzu_one_02_wav, BinaryData::suzu_one_02_wavSize, 49, 1, 49, "suzu_one_02_wav");
    loadNewSample(BinaryData::suzu_one_03_wav, BinaryData::suzu_one_03_wavSize, 50, 1, 50, "suzu_one_03_wav");
    loadNewSample(BinaryData::suzu_one_04_wav, BinaryData::suzu_one_04_wavSize, 51, 1, 51, "suzu_one_04_wav");
    loadNewSample(BinaryData::suzu_one_05_wav, BinaryData::suzu_one_05_wavSize, 52, 1, 52, "suzu_one_05_wav");
    loadNewSample(BinaryData::suzu_one_06_wav, BinaryData::suzu_one_06_wavSize, 53, 1, 53, "suzu_one_06_wav");

    loadNewSample(BinaryData::suzu_long_01_aiff, BinaryData::suzu_long_01_aiffSize, 60, 1, 60, "suzu_long_01_aiff");
    loadNewSample(BinaryData::suzu_long_02_aiff, BinaryData::suzu_long_02_aiffSize, 61, 1, 61, "suzu_long_02_aiff");
    loadNewSample(BinaryData::suzu_long_03_aiff, BinaryData::suzu_long_03_aiffSize, 62, 1, 62, "suzu_long_03_aiff");
    
    // for windows
    /*
    loadNewSampleFromFile("OtowabiKagurasuzuSamples/suzu_one_02.wav", 49, 1, 49, "suzu_one_02_wav");
    loadNewSampleFromFile("OtowabiKagurasuzuSamples/suzu_one_03.wav", 50, 1, 50, "suzu_one_03_wav");
    loadNewSampleFromFile("OtowabiKagurasuzuSamples/suzu_one_04.wav", 51, 1, 51, "suzu_one_04_wav");
    loadNewSampleFromFile("OtowabiKagurasuzuSamples/suzu_one_05.wav", 52, 1, 52, "suzu_one_05_wav");
    loadNewSampleFromFile("OtowabiKagurasuzuSamples/suzu_one_06.wav", 53, 1, 53, "suzu_one_06_wav");
    
    loadNewSampleFromFile("OtowabiKagurasuzuSamples/suzu_long_01.wav", 60, 1, 60, "suzu_long_01_wav");
    loadNewSampleFromFile("OtowabiKagurasuzuSamples/suzu_long_02.wav", 61, 1, 61, "suzu_long_02_wav");
    loadNewSampleFromFile("OtowabiKagurasuzuSamples/suzu_long_03.wav", 62, 1, 62, "suzu_long_03_wav");
     */
    
}

OtowabiKagurasuzuAudioProcessor::~OtowabiKagurasuzuAudioProcessor()
{
}

//==============================================================================
const String OtowabiKagurasuzuAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool OtowabiKagurasuzuAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool OtowabiKagurasuzuAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

double OtowabiKagurasuzuAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int OtowabiKagurasuzuAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int OtowabiKagurasuzuAudioProcessor::getCurrentProgram()
{
    return 0;
}

void OtowabiKagurasuzuAudioProcessor::setCurrentProgram (int index)
{
}

const String OtowabiKagurasuzuAudioProcessor::getProgramName (int index)
{
    return {};
}

void OtowabiKagurasuzuAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void OtowabiKagurasuzuAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
    
    hostSampleRate = sampleRate;
    synth.setCurrentPlaybackSampleRate (sampleRate);
}

void OtowabiKagurasuzuAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool OtowabiKagurasuzuAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void OtowabiKagurasuzuAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    /*

    const int totalNumInputChannels  = getTotalNumInputChannels();
    const int totalNumOutputChannels = getTotalNumOutputChannels();

    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // This is here to avoid people getting screaming feedback
    // when they first compile a plugin, but obviously you don't need to keep
    // this code if your algorithm always overwrites all the output channels.
    for (int i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());
    */
    /*
    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        float* channelData = buffer.getWritePointer (channel);

        // ..do something to the data...
    }
    */
    
    synth.renderNextBlock (buffer, midiMessages, 0, buffer.getNumSamples());
}

//==============================================================================
bool OtowabiKagurasuzuAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* OtowabiKagurasuzuAudioProcessor::createEditor()
{
    return new OtowabiKagurasuzuAudioProcessorEditor (*this);
}

//==============================================================================
void OtowabiKagurasuzuAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void OtowabiKagurasuzuAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
void OtowabiKagurasuzuAudioProcessor::loadNewSample
(const void* data, int dataSize, int note, int noteChange, int baseNote, const String& name){
    
    MemoryInputStream* soundBuffer = new MemoryInputStream (data, static_cast<std::size_t> (dataSize), false);
    ScopedPointer<AudioFormatReader> formatReader;
    
    if(name.indexOf("_aiff") > 0){
        formatReader = audioFormatManager.findFormatForFileExtension("aiff")->createReaderFor (soundBuffer, true);
    }else if(name.indexOf("_wav") > 0){
        formatReader = audioFormatManager.findFormatForFileExtension("wav")->createReaderFor (soundBuffer, true);
    }else{
        formatReader = audioFormatManager.findFormatForFileExtension("wav")->createReaderFor (soundBuffer, true);
    }
    
    if (formatReader == nullptr){
        return;
    }
    
    BigInteger midiNotes;
    midiNotes.setRange (note, noteChange, true);
    
    SynthesiserSound::Ptr newSound = new SamplerSound (name, *formatReader, midiNotes, baseNote, 0.0, 0.0, 10.0);
    //synth.removeSound (0);
    sound = newSound;
    synth.addSound (sound);
}

void OtowabiKagurasuzuAudioProcessor::loadNewSampleFromFile
(const String& filePath, int note, int noteChange, int baseNote, const String& name){
    
    File file = File::getCurrentWorkingDirectory().getChildFile (filePath);

    ScopedPointer<AudioFormatReader> formatReader = audioFormatManager.createReaderFor (file.createInputStream());
    if (formatReader == nullptr){
        return;
    }
    BigInteger midiNotes;
    midiNotes.setRange (note, noteChange, true);
    
    SynthesiserSound::Ptr newSound = new SamplerSound (name, *formatReader, midiNotes, baseNote, 0.0, 0.0, 10.0);
    //synth.removeSound (0);
    sound = newSound;
    synth.addSound (sound);
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new OtowabiKagurasuzuAudioProcessor();
}



