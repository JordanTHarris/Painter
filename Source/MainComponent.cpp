/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"


//==============================================================================
MainContentComponent::MainContentComponent()
	: drawingCanvas{new DrawingCanvas{}},
	  sideBar{new SideBar{*drawingCanvas }}
{
	//drawingPanel = new DrawingPanel{};
	addAndMakeVisible(drawingCanvas);
	
	//sideBar = new SideBar{*drawingPanel};
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
	drawingCanvas->setBounds(getWidth() / 5, 0, getWidth() - getWidth() / 5, getHeight());
	sideBar->setBounds(0, 0, getWidth() / 5, getHeight());
}







