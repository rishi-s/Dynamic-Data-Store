/*
 * CmdMenu.cpp
 *
 *  Created on: 18 Jun 2021
 *      Author: rishi
 */


#include "CmdMenu.h"
using namespace std;

namespace DynDataStore {

	// constructor that creates menu options and refers to buffer interface instance
	CmdMenu::CmdMenu(BufferCmds &interface): mainOptions(5), actionOptions(4), bufferInterface(interface) {

		// define generic menu instruction
		instructions = "Enter a menu option and value using the format <#>:<%%%%%>. \n";

		// populate custom option menu
		mainMenu = "Pick a data type option and state the buffer size (e.g. '2:1024'): \n";
		for(unsigned int i=0; i<mainOptions; i++){
			mainMenu = mainMenu + to_string(i) + " - " + bufferInterface.pDataType[i] + "\n";
		}

		// populate custom action menu
		actionMenu = "Pick an action and provide the required parameter: \n";
		for(unsigned int i=0; i<actionOptions; i++){
			actionMenu = actionMenu + bufferInterface.pActionList[i] + "\n";
				}

		//generate menu
		printMenu();

	}

	// return current menu options depending on buffer instantiation state
	void CmdMenu::printMenu() {

		// print the generic instruction
		cout << instructions << "\n";

		// print and enable either the main or action menu options
		if(bufferInterface.getBufferState()){
			cout << actionMenu << "\n";
		}
		else{
			cout << mainMenu << "\n";
			parseMainInput();
		}
	}

	// interpret incoming text for the main menu functionality
	void CmdMenu::parseMainInput() {

		// read the command line input
		string input;
		cin >> input;

		// extract value/argument parameters
		char option = input.at(0);
		int optionNo = int(option-48);
		char separator = input.at(1);
		string value = input;
		value.erase(0,2);

		// check syntax
		if(separator==':' && stoi(value)>0){
			// check the value is in range
			if(optionNo>=0 && optionNo<mainOptions){
				cout << "Loading buffer for " << bufferInterface.pDataType[optionNo] << " of " << value << " elements.\n \n";
				bufferInterface.setBufferState(true);
				bufferInterface.setBufferOperation(option);
				bufferInterface.setBufferValue(value);
				printMenu();
			}
			// handle incorrect menu value
			else{
				cout << "**Invalid action. Please use select from the following options.** \n \n";
				printMenu();
			}
		}
		// handle incorrect syntax
		else{
			cout << "**Invalid format. Please use the syntax <#>:<$$$$$> . \n \n";
			printMenu();
		}
	}


} /* namespace DynDataStore */

