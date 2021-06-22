/*
 * BufferCmds.cpp
 *
 *  Created on: 20 Jun 2021
 *      Author: rishi
 */


#include "BufferCmds.h"


using namespace std;

namespace DynDataStore {


	// get the current operation
	char BufferCmds::getBufferOperation(){
		return bufferOperation;
	}

	// set the current operation
	void BufferCmds::setBufferOperation(char opt){
		bufferOperation=opt;
	}

	// set the current value
	string BufferCmds::getBufferValue(){
		return bufferValue;
	}

	// set the current value
	void BufferCmds::setBufferValue(string val){
		bufferValue=val;
	}

	// interact with an instantiated buffer
	void BufferCmds::applyBufferOperation(){
		int size=atoi(bufferValue.c_str());
		switch(bufferOperation){
			case 'a':{

				break;
			}
			case 'r':{

				break;
			}
			case 'p':{

				break;
			}
			case 's':{

				break;
			}
			default:{
				cout << "***ERROR: buffer not instantiated.***";
				break;
			}

		}

	}


} /* namespace DynDataStore */
