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

	/**
	 * A setter for desired user input
	 * @param NewUserInput and integer for a list of choices
	 */
	void setUserInput(int NewUserInput);

	/**
	 * Accessor method for getting user input for UI choices
	 */
	int getUserInput();
	
	/**
	 * Accessor for the artists name from metadata
	 */
	std::string getArtist();

	/**
	 * Accessor for the song tite from metadata
	 */
	std::string getSongTitle();
	
	/**
	 * Accessor for the genre from metadata
	 */
	std::string getGenre();

	/**
	 * Accessor for the track number from metadata
	 */
	std::string getTrackNumber();
	
	/**
	 * Accessor for the year from metadata
	 */
	std::string getYear();

	/**
	 * Accessor for the comments from metadata
	 */
	std::string getComments();
	
	/**
	 * UIElements default ctor
	 */
	UIElements();

	/**
	 * A simple method to let the user know processing is occuring
	 */
	void printProccesing();

	/**
	 * Prompt the user to edit the metadata "yes" or "no"
	 */
	void promptUser();

	/**
	 * If user chose to edit metadata, this overwrites previous data
	 */
	void promptUser1();
};

#endif
