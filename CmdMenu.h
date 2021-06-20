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

		// constructor that creates menu options
		CmdMenu(unsigned short int numOps,std::string mainList[],unsigned short int numActs,std::string actionList[], BufferCmds &interface);

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

		// output data
		unsigned short int outOption;
		std::string outValue;

		BufferCmds & bufferInterface;


	};
}
#endif /* CMDMENU_H_ */
