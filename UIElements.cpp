#include "UIElements.h"
#include <iostream>
#include <istream>

void UIElements::printProccesing() {

	std::cout << "Processing..." << std::endl;
	}

//asks user if they want to edit metaData
void UIElements::promptUser() {
	using namespace std;
	//promt user at end for meta data
	cout << "Would you like to edit the Meta Data?" << std::endl;
	cout << "1. Yes" << std::endl;
	cout << "2. No" << std::endl;
	cin >> userInput;
	std::cin.ignore(1, '\n');
	}
//promts user for metadata
void UIElements::promptUser1() {
	
	std::cout << "Artist?: "; 
	std::getline( std::cin, artist);
	
	std::cout << "Title?: ";
	std::getline( std::cin, songTitle);
	
	std::cout << "Year?: ";
	std::getline( std::cin, year);
	
	std::cout << "Track number: ";
	std::getline( std::cin, trackNumber);
	
	std::cout << "Genre?: "; 
	std::getline( std::cin, genre);

	std::cout << "Comments?: " ;
	std::getline( std::cin, comments);
	}

//Getters and setters
int UIElements::getUserInput() {

	return userInput;
	}
	
std::string UIElements::getYear() {

	return year;
	}
	
std::string UIElements::getTrackNumber() {

	return trackNumber;
	}
	
std::string UIElements::getArtist() {

	return artist;
}

std::string UIElements::getGenre() {


	return genre;
	}
std::string UIElements::getSongTitle() {

	return songTitle;

}
std::string UIElements::getComments() {

	return comments;
}
	
void UIElements::setUserInput(int newUserInput) {

	userInput = newUserInput;
	
	}
	

