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
	const Rectangle<int> sideBarRect = sideBar->sideBarRect;
	const int sideBarWidth = sideBarRect.getWidth();
	const int sideBarHeight = sideBarRect.getHeight();
	drawingCanvas->setSize(getWidth() - sideBarWidth,
						   getHeight() - sideBarHeight);
}

void MainContentComponent::paint (Graphics& g)
{
    g.fillAll (Colours::black);
}

void MainContentComponent::resized()
{
	//sideBar->setBounds(0, 0, 160, getHeight());
	//drawingCanvas->setBounds(160, 0, getWidth() - 160, getHeight());

	// Update SideBar, when in turn updates DrawingCanvas
	sideBar->resized();
}

