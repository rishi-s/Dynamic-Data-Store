/*
 * BufferCmds.h
 *
 *  Created on: 20 Jun 2021
 *      Author: rishi
 */

#include <iostream>

#ifndef BUFFERCMDS_H_
#define BUFFERCMDS_H_

namespace DynDataStore {


	class BufferCmds {
	public:
		BufferCmds();
		virtual ~BufferCmds();

		// return state of buffer
		bool getBufferState();

		// change state of buffer
		void setBufferState(bool state);

		// change state of buffer
		void setBufferOperation(char opt);

		// change state of buffer
		void setBufferValue(std::string val);


		// menu lengths
		const unsigned short int numDataTypes;
		const unsigned short int numActions;
		enum Format {kInteger, kFloat, kDouble, kString, kChar} dTypes;
		// pointers to menu lists
		const std::string *pDataType;
		const std::string *pActionList;


	private:
		// buffer state machine variable for interfacing
		bool bufferInit;
		char bufferOperation;
		std::string bufferValue;

	};

} /* namespace DynDataStore */

#endif /* BUFFERCMDS_H_ */
