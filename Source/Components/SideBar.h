/*
  ==============================================================================

    SideBar.h
    Created: 24 May 2015 4:14:22am
    Author:  Jordan

  ==============================================================================
*/

#ifndef SIDEBAR_H_INCLUDED
#define SIDEBAR_H_INCLUDED

#include "../../JuceLibraryCode/JuceHeader.h"
#include "ColourChangeButton.h"
#include "DrawingCanvas.h"

//==============================================================================
/*
*/
class SideBar    : public Component,
				   public Button::Listener
{
public:
    SideBar(DrawingCanvas& panel);
    ~SideBar();

    void paint (Graphics&);
    void resized();
	void buttonClicked(Button* button);

	Colour getColour();


private:
	/** Button that opens a ColourSelector and calls setColour() when the color
		changes. setColour() changes the colour of the Graphics object that draws
		the Path.
	*/
	ScopedPointer<ColourChangeButton> colourChangeButton;

	ScopedPointer<Slider> thicknessSlider;


	ScopedPointer<Label> colourLabel;
	Colour colour;

	DrawingCanvas& drawingCanvas;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SideBar)
};


#endif  // SIDEBAR_H_INCLUDED
