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
    void promptUserFirst();
    void promptUserSecond();
    void promptUserThird();
    void printProccesing();
    int getUserInput1();
    int getUserInput2();
    int getUserInput3();
    std::string getUserInput4();
};
#endif