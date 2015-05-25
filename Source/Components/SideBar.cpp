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
	  colourLabel{ new Label{ "ColorLabel", String{"Drawing Color"} } },
	  thicknessSlider{ new Slider{"ThicknessSlider"} },
	  thicknessLabel{ new Label{"ThicknessLabel", String{"Line Thickness"}} },
	  strokeOpacitySlider{ new Slider{"StrokeOpacitySlider"} },
	  opacityLabel{ new Label{"OpacityLabel", String{"Line Opacity"}} }
	
{
	addAndMakeVisible(colourChangeButton);
	ScopedPointer<LookAndFeel_V3> colorButtonLaF;
	colourChangeButton->setLookAndFeel(colorButtonLaF);

	addAndMakeVisible(thicknessSlider);
	thicknessSlider->setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
	thicknessSlider->setColour(Slider::thumbColourId, Colour::fromRGBA(4, 75, 120, 245));
	ScopedPointer<LookAndFeel_V3> thicknessSliderLaF;
	thicknessSlider->setLookAndFeel(thicknessSliderLaF);
	thicknessSlider->setRange(1.0, 15.0);
	thicknessSlider->setValue(defaultThickness);
	thicknessSlider->addListener(this);

	addAndMakeVisible(strokeOpacitySlider);
	strokeOpacitySlider->setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
	strokeOpacitySlider->setColour(Slider::thumbColourId, Colour::fromRGBA(4, 75, 120, 245));
	ScopedPointer<LookAndFeel_V3> opacitySliderLaF;
	strokeOpacitySlider->setLookAndFeel(opacitySliderLaF);
	strokeOpacitySlider->setRange(0.0, 1.0);
	strokeOpacitySlider->setValue(defaultOpacity);
	strokeOpacitySlider->addListener(this);

	// Labels:
	addAndMakeVisible(colourLabel);
	colourLabel->setJustificationType(Justification::centred);
	colourLabel->setFont(Font{"Franklin Gothic", 16, Font::plain});

	addAndMakeVisible(thicknessLabel);
	thicknessLabel->setJustificationType(Justification::centred);
	thicknessLabel->setFont(Font{"Franklin Gothic", 16, Font::plain});

	addAndMakeVisible(opacityLabel);
	opacityLabel->setJustificationType(Justification::centred);
	opacityLabel->setFont(Font{"Franklin Gothic", 16, Font::plain});

	// Resizer limits
	int desktopHeight = Desktop::getInstance().getDisplays().getMainDisplay().userArea.getHeight();
	constrainer.setSizeLimits(100, 400, 250, desktopHeight);

	// SideBar's resizer on the right edge
	resizerBar = new ResizableEdgeComponent(this, &constrainer, ResizableEdgeComponent::rightEdge);
	addAndMakeVisible(resizerBar);
	ScopedPointer<LookAndFeel_V3> resizerLaF;
	resizerBar->setLookAndFeel(resizerLaF);
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
	resizerBar->setBounds(getRight() - 6, 0, 6, getHeight());
	drawingCanvas.setTopLeftPosition(this->getRight(), 0);
	drawingCanvas.setSize(getParentWidth() - getWidth(), getParentHeight());

	int buttonWidth = getWidth() * 0.75;
	int buttonX = (getWidth() / 2) - (buttonWidth / 2);
	colourChangeButton->setBounds(buttonX, 60, buttonWidth, 34);
	colourLabel->setBounds(getWidth() / 2 - 60, 20, 120, 40);

	int thicknessSliderWidth = getWidth() * 0.80;
	int thicknessSliderX = (getWidth() / 2) - (thicknessSliderWidth / 2);
	thicknessSlider->setBounds(thicknessSliderX, 140, thicknessSliderWidth, 20);
	thicknessLabel->setBounds(getWidth() / 2 - 60, 100, 120, 40);

	int opacitySliderWidth = getWidth() * 0.80;
	int opacitySliderX = (getWidth() / 2) - (opacitySliderWidth / 2);
	strokeOpacitySlider->setBounds(opacitySliderX, 220, opacitySliderWidth, 20);
	opacityLabel->setBounds(getWidth() / 2 - 60, 180, 120, 40);
}

void SideBar::buttonClicked(Button* button)
{
}

void SideBar::sliderValueChanged(Slider * slider)
{
	if (thicknessSlider == slider) {
		drawingCanvas.setStrokeThickness(thicknessSlider->getValue());
		drawingCanvas.repaint();
	}
	else if (strokeOpacitySlider == slider) {
		drawingCanvas.setStrokeOpacity(strokeOpacitySlider->getValue());
		drawingCanvas.repaint();
	}
}

Colour SideBar::getColour()
{
	return colour;
}
