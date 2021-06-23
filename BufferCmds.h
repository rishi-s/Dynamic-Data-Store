/*
 * BufferCmds.h
 *
 *  Created on: 20 Jun 2021
 *      Author: rishi
 *
 *      A class for interfacing between menu commands and circular buffers.
 */

#include <iostream>
#include <map>
#include "CircBuffer.h"
#include "FileInput.h"

#ifndef BUFFERCMDS_H_
#define BUFFERCMDS_H_

namespace DynDataStore {

	class BufferCmds {
	public:

		// constructor definition with member variable initialisation
		BufferCmds(FileIO &handler):bufferOperation('x'),bufferValue(""),fileHandling(handler){
		}

		// destructor;
		virtual ~BufferCmds(){}

		// get the current operation
		char getBufferOperation();

		// set the current operation
		void setBufferOperation(char opt);

		// get the current value
		std::string getBufferValue();

		// set the current value
		void setBufferValue(std::string val);

		// setup instantiated buffer
		void setupBuffer();

		// interact with an instantiated buffer
		void applyBufferOperation();


	private:
		// variables to store input operation/action commands
		char bufferOperation;
		std::string bufferValue;

		// instance of FileIO class
		FileIO &fileHandling;

	};


} /* namespace DynDataStore */

#endif /* BUFFERCMDS_H_ */
