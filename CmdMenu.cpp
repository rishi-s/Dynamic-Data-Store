/*
 * CmdMenu.cpp
 *
 *  Created on: 18 Jun 2021
 *      Author: rishi
 */


#include "CmdMenu.h"
using namespace std;

namespace DynDataStore {

	// constructor that creates menu options
	CmdMenu::CmdMenu(unsigned short int numOps,std::string mainList[],unsigned short int numActs,std::string actionList[], BufferCmds &interface): \
			mainOptions(numOps), actionOptions(numActs), bufferInterface(interface){
		// define generic menu instruction
		instructions = "Enter a menu option and value using the format <#>:<%%%%%>. \n";
		// populate custom option menu
		mainMenu = "Pick a data type option and state the buffer size (e.g. '2:1024'): \n";
		for(unsigned int i=0; i<mainOptions; i++){
			mainMenu = mainMenu + std::to_string(i) + " - " + mainList[i] + "\n";
		}
		// populate custom action menu
		actionMenu = "Pick an action and provide the required parameter: \n";
		for(unsigned int i=0; i<actionOptions; i++){
			actionMenu = actionMenu + actionList[i] + "\n";
				}
		//generate menu
		printMenu();
	}

	// return current menu options depending on menu option/action state
	void CmdMenu::printMenu() {
		//
		cout << instructions << "\n";
		if(bufferInterface.getBufferState()){
			cout << actionMenu << "\n";

		}
		else{
			cout << mainMenu << "\n";
			parseMainInput();
		}
	}

	// interpret incoming text
	void CmdMenu::parseMainInput() {
		// read the command line input
		string input;
		cin >> input;
		// extract value/argument parameters
		char action = input.at(0);
		char separator = input.at(1);
		string value = input;
		value.erase(0,2);
		// check syntax
		if(separator==':'){
			// check value
			if(int(action-48)>=0 && int(action-48)<mainOptions){
				cout << "Loading buffer for " << action << " of " << value << " elements.\n";
				outOption=action;
				outValue=value;
				bufferInterface.setBufferState(true);
				printMenu();
			}
			// handle incorrect menu value
			else{
				cout << "Invalid action. Please use select from the following options. \n";
				printMenu();
			}
		}
		// handle incorrect syntax
		else{
			cout << "Invalid format. Please use the syntax <#>:<$$$$$> . \n";
			printMenu();
		}

	}
}

