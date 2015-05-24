/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"


//==============================================================================
MainContentComponent::MainContentComponent()
{
    setSize (800, 600);
}

MainContentComponent::~MainContentComponent()
{
}

void MainContentComponent::paint (Graphics& g)
{
    g.fillAll (Colours::black);

	g.setColour(Colours::red);
	g.strokePath(path, PathStrokeType(5));
}

void MainContentComponent::resized()
{
    // This is called when the MainContentComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
}

void MainContentComponent::mouseDown(const MouseEvent & event)
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

void MainContentComponent::mouseDrag(const MouseEvent & event)
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
