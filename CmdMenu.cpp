/*
 * CmdMenu.cpp
 *
 *  Created on: 18 Jun 2021
 *      Author: rishi
 */


#include "CmdMenu.h"
using namespace std;

namespace DynDataStore {

	// constructor that prints menu options
	CmdMenu::CmdMenu(const unsigned int len, std::string optionList[], std::string text):numOptions(len) {
		instructions = "";
		// populate custom menu list
		for(unsigned int i=0; i<numOptions; i++){
			menu = menu + std::to_string(i) + " : " + optionList[i] + "\n";
		}
		//generate menu
		printMenu();
	}

	void CmdMenu::printMenu() {
		cout << instructions << "\n";
		cout << menu << "\n";
		parseInput();
	}

	void CmdMenu::parseInput() {
		string input;
		cin >> input;
		char action = input.at(0);
		char separator = input.at(1);
		string value = input;
		value.erase(0,2);
		if(separator==':'){
			if(int(action-48)>=0 && int(action-48)<numOptions){
				cout << "Loading buffer for " << action << " of " << value << " elements.\n";
				outOption=action;
				outValue=value;
			}

			else{
				cout << "Invalid action. Please use select from the following options. \n";
				printMenu();
			}
		}

		else{
			cout << "Invalid format. Please use the syntax <#>:<$$$$$> . \n";
			printMenu();
		}
	}
}

