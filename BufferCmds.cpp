/*
 * BufferCmds.cpp
 *
 *  Created on: 20 Jun 2021
 *      Author: rishi
 */


#include "BufferCmds.h"
#include "CircBuffer.h"

using namespace std;

namespace DynDataStore {

const std::string dataTypes[5]={"Integer","Float","Double","String","Char"};
const std::string actionList[4]={
	"a – add value to buffer (e.g. 'a:897', or 'a:0.8967', or 'a:Kansas_City')", \
	"r – read contents of existing .csv file into buffer using filepath (e.g. 'r:./ThisData')", \
	"p - print element(s) separated by commas (e.g. 'p:1,4,17,32,803,2296')", \
	"s – save buffer to .csv file using given filename (e.g. 's:MyData')"
};
std::map<char,string> actions;

	// constructor with member variable initialisation
	BufferCmds::BufferCmds():numDataTypes(5),numActions(4),refActions(actions),bufferInit(false){
		pDataType=dataTypes;
		pActionList=actionList;
		actions['a']="***Adding value to buffer***";
		actions['r']="***Reading .csv file to buffer***";
		actions['p']="***Printing element from buffer***";
		actions['s']="***Saving buffer to .csv file***";
	}


	// return state of buffer
	bool BufferCmds::getBufferState(){
		return bufferInit;
	}

	// change state of buffer
	void BufferCmds::setBufferState(bool state){
		bufferInit=state;
	}

	// set the current operation
	void BufferCmds::setBufferOperation(char opt){
		bufferOperation=opt;
	}

	// set the current value
	void BufferCmds::setBufferValue(string val){
		bufferValue=val;
	}



} /* namespace DynDataStore */
