/* Created by Sariah Warren on May 4 2021
* 
*
* The user may choose to process a file by choosing one or more processors. Processors should be applied in sequence. The provided processors should include 
* normalization, noisegating, and echo. After processing, the user should be prompted for a file name and if valid, 
* anew file is created with the processed audio. The user is not allowed to save the file under thes ame name as any of the existing files.
*/

#include "processorChoice.h"
#include <iostream>
#include <fstream>
#include <string>

void ProcessorChoice::promptUserFirst(){
    using namespace std;
	//promt user to process a file
	cout << "Would you like to process a file?" << std::endl;
	cout << "1. Yes" << std::endl;
	cout << "2. No" << std::endl;
	cin >> userInput1;
	std::cin.ignore(1, '\n');
}

void ProcessorChoice::promptUserSecond(){
    using namespace std;
	//prompt user for which processes theyd like to use
    if(userInput1 == 1){
	cout << "Which processors would you like to use?" << std::endl;
	cout << "1. Normalization" << std::endl;
	cout << "2. Noisegating" << std::endl;
    cout << "3. Echo" << std::endl;
	cin >> userInput2;
	std::cin.ignore(1, '\n');
    }
}
void ProcessorChoice::promptUserThird(){
    using namespace std;
    //prompt user if they want to process file again
    if(userInput1 == 1){
    cout << "Would you like to process the file again?" << std::endl;
	cout << "1. Yes" << std::endl;
	cout << "2. No" << std::endl;
	cin >> userInput3;
	std::cin.ignore(1, '\n');

    while(userInput3 != 2) {
        promptUserSecond();
        promptUserThird();
    }

        if(userInput3 == 2){
            cout << "Please type your new filename." << std::endl;
            cin >> userInput4;
           std::cin.ignore(1, '\n');
        }

    }
    
    else if(userInput3 == 2){
        cout << "Please type your new filename." << std::endl;
        cin >> userInput4;
        std::cin.ignore(1, '\n');
    }
}

void ProcessorChoice::printProccesing() {
    //let user know it's processing
    if(userInput1 ==1){
	std::cout << "Processing..." << std::endl;
    }
}

int ProcessorChoice::getUserInput1(){
    return userInput1;
}

int ProcessorChoice::getUserInput2(){
    return userInput2;
}

int ProcessorChoice::getUserInput3(){
    return userInput3;
}

std::string ProcessorChoice::getUserInput4(){
    return userInput4;
}