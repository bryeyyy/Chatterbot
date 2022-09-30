#include "voice.h"
#include <iostream>
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <fstream>
using namespace std;

/*
	The following function textually and audibly communicates a phrase.
	The open source eSpeak speech synthesizer is used to create the audible message.
	If the eSpeak exe is not located in the directory, no audible message will be heard.
*/
void Voice::say(string phrase){
    string command = "espeak \"" + phrase + "\"";    // Concat the phrase to the command
    const char* charCommand = command.c_str();    // Convert to a const char*
    cout << phrase << endl;    // Textually output phrase
    system(charCommand);    // Send the command to cmd to execute espeak with the phrase an argument
}
