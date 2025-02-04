#pragma once

#include "ofMain.h"

//Include the ofxMidi library so that the application can have MIDI functionality
#include "ofxMidi.h"

//Set the max amount of notes/circles we can display at any time
#define MAX_NUM_OF_NOTES 3

//Structure that stores information for a single note/circle
typedef struct
{
    ofPoint pos;
    int time_counter;
    int note_num;
    int note_vel;
    
} NoteData;

//===========================================================================
//The main openFrameworks class,
//configured to listen for incoming MIDI messages

class ofApp :   public ofBaseApp,

public ofxMidiListener
{
    
public:
    
    //Main openFrameworks functions
    void setup();
    void update();
    void draw();
    void exit();
    void keyPressed(int key);
    
    ofVideoPlayer edenClip;
    ofVideoPlayer edenClip1;
    ofVideoPlayer edenClip2;
    
    
    //ofTexture mirrorTexture;
    //unsigned char * videoMirror;
    
    ofImage edenFlower;
    
    //MIDI input callback function
    void newMidiMessage(ofxMidiMessage& eventArgs);
    
    
private:
    
    //Array that stores information for each note/circle being displayed
    NoteData noteData[MAX_NUM_OF_NOTES];
    
    //Variable for storing the apps background colour
    int backgroundColour;
    
    //Object that handles the MIDI input
    ofxMidiIn midiIn;
    
    //Flag that sets whether we're currently displaying the apps instructions
    bool showingInstructions;
};
