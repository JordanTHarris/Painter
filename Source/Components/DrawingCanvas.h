/*
  ==============================================================================

    DrawingCanvas.h
    Created: 24 May 2015 3:53:08am
    Author:  Jordan

  ==============================================================================
*/

#ifndef DRAWINGPANEL_H_INCLUDED
#define DRAWINGPANEL_H_INCLUDED

#include "../../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class DrawingCanvas    : public Component
{
public:
    DrawingCanvas();
    ~DrawingCanvas();

	void paint(Graphics&);
	void resized();

	void mouseDown(const MouseEvent& event);
	void mouseDrag(const MouseEvent& event);

	void setColour(Colour colour);

private:
	Path path;
	float xPos;
	float yPos;

	Colour drawColour;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DrawingCanvas)
};


#endif  // DRAWINGPANEL_H_INCLUDED
