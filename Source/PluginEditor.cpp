/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
OtowabiKagurasuzuAudioProcessorEditor::OtowabiKagurasuzuAudioProcessorEditor (OtowabiKagurasuzuAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (613, 175);
}

OtowabiKagurasuzuAudioProcessorEditor::~OtowabiKagurasuzuAudioProcessorEditor()
{
}

//==============================================================================
void OtowabiKagurasuzuAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    /*
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    g.setColour (Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Hello World!", getLocalBounds(), Justification::centred, 1);
    */
    
    g.fillAll (Colours::black);

	Image image_bg = ImageCache::getFromMemory(BinaryData::OtowabiKagurasuzu_png,BinaryData::OtowabiKagurasuzu_pngSize);
	g.drawImageWithin(image_bg,
		0, 0, 613, 90,
		RectanglePlacement::centred,
false);

    g.setColour (Colours::white);
    g.setFont (15.0f);
    //drawFittedText (const String &text, int x, int y, int width, int height, 
    // Justification justificationFlags, int maximumNumberOfLines, float minimumHorizontalScale=0.0f)
    g.drawFittedText ("OtowabiKagurasuzu ver1.0.0 - Key Map", 10, 95, 600, 30,
        Justification::left, 1, 1);
    
    g.drawFittedText ("C2 : one shot ff", 10, 110, 150, 30,
        Justification::left, 1, 1);
    g.drawFittedText ("C#2 : one shot f", 160, 110, 150, 30,
        Justification::left, 1, 1);
    g.drawFittedText ("D2 : one shot mf", 310, 110, 150, 30,
        Justification::left, 1, 1);
        
    g.drawFittedText ("D#2 : one shot mp", 10, 125, 150, 30,
        Justification::left, 1, 1);
    g.drawFittedText ("E2 : one shot p", 160, 125, 150, 30,
        Justification::left, 1, 1);
    g.drawFittedText ("F2 : one shot pp", 310, 125, 150, 30,
        Justification::left, 1, 1);
        
    g.drawFittedText ("C3 : long f", 10, 140, 150, 30,
        Justification::left, 1, 1);
    g.drawFittedText ("C#3 : long mf", 160, 140, 150, 30,
        Justification::left, 1, 1);
    g.drawFittedText ("D3 : long mp", 310, 140, 150, 30,
        Justification::left, 1, 1);
}


void OtowabiKagurasuzuAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
