/*
 * CmdMenu.cpp
 *
 *  Created on: 18 Jun 2021
 *      Author: rishi
 */


#include "CmdMenu.h"
using namespace std;

namespace DynDataStore {


	// constructor definition that creates menu options
	CmdMenu::CmdMenu(BufferCmds &interface): mainOptions(5), actionOptions(4), bufferInterface(interface) {

		// populate custom option menu
		mainMenu = "Enter a data type option and state the buffer size.\n"
				"Use the format <#>:<##########> (e.g. '2:1024' for buffer of 1024 doubles): \n";
		for(unsigned int i=0; i<mainOptions; i++){
			mainMenu = mainMenu + to_string(i) + " - " + bufferInterface.pDataType[i] + "\n";
		}

		// populate custom action menu
		actionMenu = "Pick an action for the current buffer and provide the required parameter.\n"
				"Use the format <@>:<%%%%%%%%%%>: \n";
		for(unsigned int i=0; i<actionOptions; i++){
			actionMenu = actionMenu + bufferInterface.pActionList[i] + "\n";
				}

		//generate menu
		printMenu();
		runMenu();
	}


	// return current menu options depending on buffer instantiation state
	void CmdMenu::printMenu() {

		// print and enable either the main or action menu options
		if(bufferInterface.getBufferState()){
			cout << actionMenu << "\n";
		}
		else{
			cout << mainMenu << "\n";
			//parseMainInput(option, separator, value);
		}
	}


	// runs menu TUI until terminal is exited
	void CmdMenu::runMenu(){
		while(true){
			getInput();
		}
	}


	// get text input from terminal
	void CmdMenu::getInput(){

		// read command line input
		string input;
		cin >> input;

		// extract parameters and convert to required types
		char option = input.at(0);				//first char
		int numericOpt = int(option-48);		//first char as int
		char separator = input.at(1);			//":" separator
		string value = input;
		value.erase(0,2);						//additional argument
		int numericVal = atoi(value.c_str());	//additional argument at int


		// check syntax
		if(separator==':'){
			// check buffer state and parse input values accordingly
			if(!bufferInterface.getBufferState()){
				parseMainInput(option, numericOpt, value, numericVal);
			}
			else{
				parseActionInput(option, numericOpt, value, numericVal);
			}
		}
		// handle incorrect syntax
		else{
			cout << "**Invalid format. Please use the correct syntax. \n \n";
			printMenu();
		}
	}


	// interpret incoming text for main menu
	void CmdMenu::parseMainInput(char opt, int numOpt, string val, int numVal) {

		// check the option number and value are in range
		if(numOpt>=0 && numOpt<mainOptions && numVal>0){
			cout << "Loading buffer for " << bufferInterface.pDataType[numOpt] << " of " << numVal << " elements.\n \n";
			bufferInterface.setBufferState(true);
			pushToBufferInterface(opt, val);
		}

		// handle incorrect menu value
		else{
			cout << "***Invalid option. Please choose from the following options.*** \n \n";
			printMenu();
		}
	}


	// interpret incoming text for actions menu
	void CmdMenu::parseActionInput(char opt, int numOpt, string val, int numVal) {

		// check the option number and value are in range
		if(bufferInterface.refActions.count(opt)>0){
			cout << bufferInterface.refActions[opt] << "\n";
			pushToBufferInterface(opt, val);
		}

		// handle incorrect menu value
		else{
			cout << "***Invalid action. Please choose from the following actions.*** \n \n";
			printMenu();
		}
	}


	// helper function for buffer interfacing
	void CmdMenu::pushToBufferInterface(char opt, string val){
		bufferInterface.setBufferOperation(opt);
		bufferInterface.setBufferValue(val);
		printMenu();
	}


} /* namespace DynDataStore */

