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
	colourChangeButton->setLookAndFeel(&lookAndFeelV3);

	addAndMakeVisible(thicknessSlider);
	thicknessSlider->setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
	thicknessSlider->setColour(Slider::thumbColourId, Colour::fromRGBA(4, 75, 120, 245));
	thicknessSlider->setLookAndFeel(&lookAndFeelV3);
	thicknessSlider->setRange(1.0, 15.0);
	thicknessSlider->setValue(defaultThickness);
	thicknessSlider->addListener(this);

	addAndMakeVisible(strokeOpacitySlider);
	strokeOpacitySlider->setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
	strokeOpacitySlider->setColour(Slider::thumbColourId, Colour::fromRGBA(4, 75, 120, 245));
	strokeOpacitySlider->setLookAndFeel(&lookAndFeelV3);
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
	resizerBar->setLookAndFeel(&lookAndFeelV3);

	// Initial size and position
	sideBarRect.setBounds(0, 0, 160, getParentHeight());	
	setBounds(sideBarRect);
}

SideBar::~SideBar()
{
}

void SideBar::paint (Graphics& g)
{
    g.fillAll (Colours::white);   // clear the background

	// Draw a black outline around the Sidebar
	g.setColour(Colours::black);
	g.drawRoundedRectangle(0, 0, (float)getWidth(), (float)getHeight(), 4.0f, 4.0f);
}

void SideBar::resized()
{
	// Set sideBarRect to new bounds and apply that to SideBar.
	// Take's the height from MainComponent and everything else from itself.
	sideBarRect.setBounds(getX(), getY(), getWidth(), getParentHeight());
	setBounds(sideBarRect);

	resizerBar->setBounds(getRight() - 8, 0, 8, getHeight());
	// Resize DrawingCanvas accordingly as SideBar is resized
	drawingCanvas.setTopLeftPosition(sideBarRect.getRight(), 0);
	drawingCanvas.setSize(getParentWidth() - sideBarRect.getWidth(), getParentHeight());
	repaint();

	int buttonWidth = (int)(getWidth() * 0.75);
	int buttonX = (getWidth() / 2) - (buttonWidth / 2);
	colourChangeButton->setBounds(buttonX, 60, buttonWidth, 34);
	colourLabel->setBounds(getWidth() / 2 - 60, 20, 120, 40);

	int thicknessSliderWidth = (int)(getWidth() * 0.80);
	int thicknessSliderX = (getWidth() / 2) - (thicknessSliderWidth / 2);
	thicknessSlider->setBounds(thicknessSliderX, 140, thicknessSliderWidth, 20);
	thicknessLabel->setBounds(getWidth() / 2 - 60, 100, 120, 40);

	int opacitySliderWidth = (int)(getWidth() * 0.80);
	int opacitySliderX = (getWidth() / 2) - (opacitySliderWidth / 2);
	strokeOpacitySlider->setBounds(opacitySliderX, 220, opacitySliderWidth, 20);
	opacityLabel->setBounds(getWidth() / 2 - 60, 180, 120, 40);
}


void SideBar::sliderValueChanged(Slider * slider)
{
	if (thicknessSlider == slider) {
		drawingCanvas.setStrokeThickness((float)thicknessSlider->getValue());
		drawingCanvas.repaint();
	}
	else if (strokeOpacitySlider == slider) {
		drawingCanvas.setStrokeOpacity((float)strokeOpacitySlider->getValue());
		drawingCanvas.repaint();
	}
}

Colour SideBar::getColour()
{
	return colour;
}
