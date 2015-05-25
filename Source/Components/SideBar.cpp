/*
  ==============================================================================

    SideBar.cpp
    Created: 24 May 2015 4:14:22am
    Author:  Jordan

  ==============================================================================
*/

#include "../../JuceLibraryCode/JuceHeader.h"
#include "SideBar.h"

//==============================================================================
SideBar::SideBar(DrawingCanvas& canvas)
	: drawingCanvas{ canvas },
	colourChangeButton{ new ColourChangeButton{canvas} },		// Access DrawingCanvas
	colourLabel{new Label{ "ColorLabel", String{"Drawing Color"} }}
{
	addAndMakeVisible(colourChangeButton);
	colourChangeButton->setLookAndFeel(new LookAndFeel_V3{});

	addAndMakeVisible(colourLabel);
	colourLabel->setJustificationType(Justification::centred);
}

SideBar::~SideBar()
{
}

void SideBar::paint (Graphics& g)
{
    g.fillAll (Colours::white);   // clear the background

	// Draw a black outline around the Sidebar
	g.setColour(Colours::black);
	g.drawRoundedRectangle(0, 0, getWidth(), getHeight(), 4.0f, 4.0f);
}

void SideBar::resized()
{
	int buttonWidth = getWidth() * 0.75;
	int buttonX = (getWidth() / 2) - (buttonWidth / 2);
	colourChangeButton->setBounds(buttonX, 60, buttonWidth, 34);
	colourLabel->setBounds(getWidth() / 2 - 60, 20, 120, 40);
}

void SideBar::buttonClicked(Button* button)
{
	if (button == colourChangeButton) {
		
	}
}

Colour SideBar::getColour()
{
	return colour;
}
