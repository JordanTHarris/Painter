/*
  ==============================================================================

    DrawingCanvas.cpp
    Created: 24 May 2015 3:53:08am
    Author:  Jordan

  ==============================================================================
*/

#include "../../JuceLibraryCode/JuceHeader.h"
#include "DrawingCanvas.h"

//==============================================================================
DrawingCanvas::DrawingCanvas()
{
	setSize(getParentWidth(), getParentHeight());
}

DrawingCanvas::~DrawingCanvas()
{
}

void DrawingCanvas::paint(Graphics& g)
{
	g.fillAll(Colours::white);

	// Draw a black outline around the Sidebar
	g.setColour(Colours::black);
	g.drawRoundedRectangle(0, 0, getWidth(), getHeight(), 4.0f, 4.0f);

	g.setColour(drawColour);
	g.strokePath(path, PathStrokeType(5));
}

void DrawingCanvas::resized()
{
	
}

void DrawingCanvas::mouseDown(const MouseEvent & event)
{
	if (event.mods.isLeftButtonDown()) {
		xPos = event.position.getX();
		yPos = event.position.getY();
		path.startNewSubPath(xPos, yPos);
		path.lineTo(xPos, yPos);
		repaint();
	}
	else if (event.mods.isRightButtonDown()) {
		path.clear();
		repaint();
	}
}

void DrawingCanvas::mouseDrag(const MouseEvent & event)
{
	if (event.mods.isLeftButtonDown()) {
		xPos = event.position.getX();
		yPos = event.position.getY();
		path.lineTo(xPos, yPos);
		repaint();
	}
	else if (event.mods.isRightButtonDown()) {
		path.clear();
	}
}

void DrawingCanvas::setColour(Colour colour)
{
	drawColour = colour;
}
