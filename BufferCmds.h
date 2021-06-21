/*
 * BufferCmds.h
 *
 *  Created on: 20 Jun 2021
 *      Author: rishi
 */

#include <iostream>
#include <map>

#ifndef BUFFERCMDS_H_
#define BUFFERCMDS_H_

namespace DynDataStore {


	class BufferCmds {
	public:

		// constructor
		BufferCmds();

		// destructor;
		virtual ~BufferCmds(){}

		// return state of buffer
		bool getBufferState();

		// change state of buffer
		void setBufferState(bool state);

		// change the current operation
		void setBufferOperation(char opt);

		// change the current value
		void setBufferValue(std::string val);


		// menu lengths
		const unsigned short int numDataTypes;
		const unsigned short int numActions;

		// pointers to menu lists
		const std::string *pDataType;
		const std::string *pActionList;
		std::map<char,std::string> &refActions;

	private:
		// buffer state machine variable for interfacing
		bool bufferInit;
		char bufferOperation;
		std::string bufferValue;

	};

} /* namespace DynDataStore */

#endif /* BUFFERCMDS_H_ */
