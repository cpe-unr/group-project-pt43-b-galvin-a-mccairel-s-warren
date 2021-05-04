#ifndef PROCESSOR_CHOICE_H
#define PROCESSOR_CHOICE_H
#include "wav.h"
#include "Processor.h"

class ProcessorChoice
{
    int userInput1;
    int userInput2;
    int userInput3;
    std::string userInput4;

public:
    /**
     * Prompt the user if they would like to edit/process the audio buffer
     * "yes" or "no"
     */
    void promptUserFirst();

    /**
     * Prompt the user if they would like to echo, normalize, or noisegate the audio
     * "yes" or "no"
     */
    void promptUserSecond();

    /**
     * Prompt the user if they would like to edit/process again
     * "yes" or "no"
     */
    void promptUserThird();

    /**
     * Let's the user know processing is occuring
     */
    void printProccesing();

    /** Accessor method for user input for audio processing */
    int getUserInput1();

    /** Accessor method for user input for audio processing */
    int getUserInput2();
    
    /** Accessor method for user input for audio processing */
    int getUserInput3();

    /** Accessor method for renaming the file, gets the desired name
     * 
     * @return the new file name for the altered audio file
     */
    std::string getUserInput4();
};
#endif