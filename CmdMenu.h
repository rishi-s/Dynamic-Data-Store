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

		// constructor that creates menu options and refers to buffer interface instance
		CmdMenu(BufferCmds &interface);

		// destructor
		virtual ~CmdMenu(){}

		// return current menu options
		void printMenu();

		// interpret incoming text for main menu
		void parseMainInput();

		// interpret incoming text for actions menu
		void parseActionInput();


	private:

		// text to explain menu functions
		std::string instructions;
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
