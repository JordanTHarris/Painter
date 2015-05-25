/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"


//==============================================================================
MainContentComponent::MainContentComponent()
	: drawingCanvas{ new DrawingCanvas{} },
	  sideBar{ new SideBar{*drawingCanvas} }
{

	addAndMakeVisible(drawingCanvas);
	addAndMakeVisible(sideBar);
	
    setSize (800, 600);
}

MainContentComponent::~MainContentComponent()
{
}

void MainContentComponent::paint (Graphics& g)
{
    g.fillAll (Colours::black);
}

void MainContentComponent::resized()
{
	sideBar->setBounds(0, 0, 160, getHeight());
	drawingCanvas->setBounds(160, 0, getWidth() - 160, getHeight());
}

