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
	strokeThickness = defaultThickness;
	strokeOpacity = defaultOpacity;

	// Initial size and position
	//canvasRect.setBounds(160, 0, getParentWidth() - 160, getParentHeight()); 
	//setBounds(canvasRect);
}

DrawingCanvas::~DrawingCanvas()
{
}

void DrawingCanvas::paint(Graphics& g)
{
	g.fillAll(Colours::white);

	// Draw a black outline around the Sidebar
	g.setColour(Colours::black);
	g.drawRoundedRectangle(0, 0, (float)getWidth(), (float)getHeight(), 4.0f, 4.0f);

	g.setColour(drawColour);
	g.setOpacity(strokeOpacity);
	g.strokePath(path, PathStrokeType(strokeThickness, PathStrokeType::curved, PathStrokeType::rounded));
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
		path.lineTo(xPos, yPos + 1);		// Add 1 to draw when called
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

void DrawingCanvas::setStrokeThickness(float thickness)
{
	strokeThickness = thickness;
}

void DrawingCanvas::setStrokeOpacity(float opacity)
{
	strokeOpacity = opacity;
}
