/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#ifndef MAINCOMPONENT_H_INCLUDED
#define MAINCOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"


//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainContentComponent   : public Component
{
public:
	//==============================================================================
	MainContentComponent();
	~MainContentComponent();

	void paint(Graphics&);
	void resized();

	void mouseDown(const MouseEvent& event);
	void mouseDrag(const MouseEvent& event);

private:
	Path path;
	float xPos;
	float yPos;

	OwnedArray<Path> paths;
	ScopedPointer<ColourSelector> colorSelector;
	ScopedPointer<Slider> thicknessSlider;

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};


#endif  // MAINCOMPONENT_H_INCLUDED
