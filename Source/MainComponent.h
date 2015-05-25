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
	
	void timerCallback();

private:
	ScopedPointer<DrawingCanvas> drawingCanvas;
	ScopedPointer<SideBar> sideBar;

	ScopedPointer<ColourSelector> colorSelector;
	ScopedPointer<Slider> thicknessSlider;

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};


#endif  // MAINCOMPONENT_H_INCLUDED
