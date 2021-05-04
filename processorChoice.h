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
};

#endif