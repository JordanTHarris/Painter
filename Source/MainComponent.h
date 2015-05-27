/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#ifndef MAINCOMPONENT_H_INCLUDED
#define MAINCOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "Components\DrawingCanvas.h"
#include "Components\SideBar.h"

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/



class MainContentComponent : public Component
{
public:
	//==============================================================================
	MainContentComponent();
	~MainContentComponent();

	void paint(Graphics&);
	void resized();


private:
    //==============================================================================
	ScopedPointer<DrawingCanvas> drawingCanvas;
	ScopedPointer<SideBar> sideBar;

	Rectangle<int> sideBarRect;
	Rectangle<int> canvasRect;

	LookAndFeel_V3 lookAndFeelV3;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};


#endif  // MAINCOMPONENT_H_INCLUDED
