//Created by Brennan Galvin on 5/3/2021
//Header for object that stores values for user input and functions to print basic elements

#ifndef UIElements_H
#define UIElements_H

#include <string>
class UIElements {
private:
	std::string artist;
	std::string songTitle;
	std::string genre;
	std::string trackNumber;
 	std::string year;
	std::string comments;
	
	int userInput;
public:
	void setUserInput(int NewUserInput);
	int getUserInput();
	
	std::string getArtist();
	std::string getSongTitle();
	std::string getGenre();
	std::string getTrackNumber();
	std::string getYear();
	std::string getComments();
	
	
	UIElements();
	void printProccesing();
	void promptUser();
	void promptUser1();
};

#endif
