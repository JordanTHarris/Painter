/*
  ==============================================================================

    ColourChangeButton.h
    Created: 24 May 2015 5:02:30am
    Author:  Jordan

  ==============================================================================
*/

#ifndef COLOURCHANGEBUTTON_H_INCLUDED
#define COLOURCHANGEBUTTON_H_INCLUDED

#include "../../JuceLibraryCode/JuceHeader.h"
#include "DrawingCanvas.h"

//==============================================================================
/*
*/
class ColourChangeButton : public TextButton,
						   public ChangeListener
{
public:
	ColourChangeButton(DrawingCanvas& panel)
		: TextButton{},
		  drawingCanvas{ panel }
	{
		setSize(10, 24);
		changeWidthToFitText();

		colour = Colours::black;
		setColour(TextButton::buttonColourId, colour);	// set initial button color
		drawingCanvas.setColour(colour);			// set drawing color to initial color
		drawingCanvas.repaint();					// repaint to set graphics to init color
	}

	void clicked() override
	{
		// Create new ColourSelector when the button is clicked.
		ColourSelector* colourSelector = new ColourSelector();
		colourSelector->setName("Drawing Color");
		colourSelector->setCurrentColour(findColour(TextButton::buttonColourId));
		colourSelector->addChangeListener(this);
		colourSelector->setColour(ColourSelector::backgroundColourId, Colours::transparentBlack);
		colourSelector->setSize(300, 400);

		CallOutBox::launchAsynchronously(colourSelector, getScreenBounds(), nullptr);


	}

	/** When the ColourSelector changes color, set the color of the TextButton
		to the ColourSelector's color. Also, set the color of the drawing panel's
		Graphic (path) and trigger a repaint to paint that color.
	*/
	void changeListenerCallback(ChangeBroadcaster* source) override
	{
		if (ColourSelector* cs = dynamic_cast <ColourSelector*> (source)) {
			setColour(TextButton::buttonColourId, cs->getCurrentColour());
			colour = cs->getCurrentColour();
			drawingCanvas.setColour(colour);
			drawingCanvas.repaint();
		}
		
	}

	Colour getColour()
	{
		return colour;
	}

private:
	Colour colour;

	DrawingCanvas& drawingCanvas;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ColourChangeButton)
};


#endif  // COLOURCHANGEBUTTON_H_INCLUDED
