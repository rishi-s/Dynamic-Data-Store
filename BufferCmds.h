/*
 * BufferCmds.h
 *
 *  Created on: 20 Jun 2021
 *      Author: rishi
 */

#include <iostream>
#include <map>
#include "CircBuffer.h"

#ifndef BUFFERCMDS_H_
#define BUFFERCMDS_H_

namespace DynDataStore {


	class BufferCmds {
	public:


		// constructor definition with member variable initialisation
		BufferCmds():bufferOperation('x'),bufferValue(""){}

		// destructor;
		virtual ~BufferCmds(){}

		// get the current operation
		char getBufferOperation();

		// change the current operation
		void setBufferOperation(char opt);

		// change the current value
		std::string getBufferValue();

		// change the current value
		void setBufferValue(std::string val);

		// interact with an instantiated buffer
		void applyBufferOperation();


	private:
		char bufferOperation;
		std::string bufferValue;

	};

} /* namespace DynDataStore */

#endif /* BUFFERCMDS_H_ */
