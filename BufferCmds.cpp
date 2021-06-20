/*
 * BufferCmds.cpp
 *
 *  Created on: 20 Jun 2021
 *      Author: rishi
 */

#include "BufferCmds.h"

namespace DynDataStore {

BufferCmds::BufferCmds():bufferInit(false) {
	// TODO Auto-generated constructor stub

}

BufferCmds::~BufferCmds() {
	// TODO Auto-generated destructor stub
}


// return state of buffer
bool BufferCmds::getBufferState(){
	return bufferInit;
}

// change state of buffer
void BufferCmds::setBufferState(bool state){
	bufferInit=state;
}

// buffer state machine variable for interfacing
bool bufferInit;

} /* namespace DynDataStore */
