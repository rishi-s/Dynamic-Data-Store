/*
 * CmdMenu.h
 *
 *  Created on: 18 Jun 2021
 *      Author: rishi
 */

#ifndef CMDMENU_H_
#define CMDMENU_H_
#include <iostream>

namespace DynDataStore {
	class CmdMenu {

	public:

		// constructor that prints menu options
		CmdMenu(unsigned int len, std::string optionList[], std::string text);

		// destructor
		virtual ~CmdMenu(){}

		// return menu options
		void printMenu();

		// interprets incoming text
		void parseInput();

		// return follow-up prompt
		bool nextPrompt();


	private:
		// text to explain menu function
		std::string instructions;
		std::string menu;

		// menu length
		const unsigned short int numOptions;

		// output option integer
		unsigned short int outOption;

		// output value string
		std::string outValue;


	};
}
#endif /* CMDMENU_H_ */
