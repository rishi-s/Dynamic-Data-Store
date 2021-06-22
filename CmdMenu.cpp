/*
 * CmdMenu.cpp
 *
 *  Created on: 18 Jun 2021
 *      Author: rishi
 */


#include "CmdMenu.h"
#include "BufferCmds.h"


using namespace std;

namespace DynDataStore {

	// string containers for menu display
	const string dataTypes[5]={"Integer","Float","Double","String","Char"};
	const string actionList[4]={
		"a – add value to buffer (e.g. 'a:897', or 'a:0.8967', or 'a:Kansas_City')", \
		"r – read contents of existing .csv file into buffer using filepath (e.g. 'r:./ThisData')", \
		"p - print specified element from buffer (e.g. 'p:2296')", \
		"s – save buffer to .csv file using given filename (e.g. 's:MyData')"
	};
	std::map<char,string> actions;


	// constructor definition that creates menu options
	CmdMenu::CmdMenu(BufferCmds &interface): mainOptions(5), actionOptions(4), bufferInterface(interface),\
			bufferInit(false), refActions(actions) {
		pDataType=dataTypes;
		pActionList=actionList;

		// populate custom option menu
		mainMenu = "Enter a data type option and state the buffer size.\n"
				"Use the format <#>:<##########> (e.g. '2:1024' for buffer of 1024 doubles): \n";
		for(unsigned int i=0; i<mainOptions; i++){
			mainMenu = mainMenu + to_string(i) + " - " + pDataType[i] + "\n";
		}

		// populate custom action menu
		actionMenu = "Pick an action for the current buffer and provide the required parameter.\n"
				"Use the format <@>:<%%%%%%%%%%>: \n";
		for(unsigned int i=0; i<actionOptions; i++){
			actionMenu = actionMenu + pActionList[i] + "\n";
		}

		//generate menu
		printMenu();
	}


	// return current menu options depending on buffer instantiation state
	void CmdMenu::printMenu() {

		// print and enable either the main or action menu options
		if(bufferInit){
			cout << actionMenu << "\n";
		}
		else{
			cout << mainMenu << "\n";
		}
		getInput();
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
			if(bufferInit){
				parseActionInput(option, numericOpt, value, numericVal);
			}
			else{
				parseMainInput(option, numericOpt, value, numericVal);
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
			cout << "Loading buffer for " << pDataType[numOpt] << " of " << numVal << " elements.\n \n";
			bufferInit=true;
			printMenu();
		}

		// handle incorrect menu value
		else{
			cout << "***Invalid option. Please choose from the following options.*** \n \n";
			printMenu();
		}
	}


	// interpret incoming text for actions menu
	void CmdMenu::parseActionInput(char opt, int numOpt, string val, int numVal) {

		// map for input character actions
		actions['a']="***Adding value to buffer***";
		actions['r']="***Reading .csv file to buffer***";
		actions['p']="***Printing element from buffer***";
		actions['s']="***Saving buffer to .csv file***";

		// check the option number and value are in range
		if(actions.count(opt)>0){
			cout << actions[opt] << "\n";
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

