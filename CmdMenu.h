/*
 * CmdMenu.h
 *
 *  Created on: 18 Jun 2021
 *      Author: rishi
 */

#ifndef CMDMENU_H_
#define CMDMENU_H_
#include <iostream>
#include "BufferCmds.h"

namespace DynDataStore {
	class CmdMenu {

	public:

		// constructor that refers to buffer interface instance
		CmdMenu(BufferCmds &interface);

		// destructor
		virtual ~CmdMenu(){}

		// runs menu TUI until terminal is exited
		void runMenu();

		// return current menu options
		void printMenu();

		// get text input from terminal
		void getInput();

		// interpret incoming text for main menu
		void parseMainInput(char opt, int numOpt, std::string val, int numVal);

		// interpret incoming text for actions menu
		void parseActionInput(char opt, int numOpt, std::string val, int numVal);

		// helper function for buffer interfacing
		void pushToBufferInterface(char opt, std::string val);


	private:

		// text to explain menu functions
		std::string mainMenu;
		std::string actionMenu;

		// menu lengths
		const unsigned short int mainOptions;
		const unsigned short int actionOptions;

		// reference to buffer interface instance
		BufferCmds & bufferInterface;


	};
} /* namespace DynDataStore */

#endif /* CMDMENU_H_ */
