/*
 * BufferCmds.cpp
 *
 *  Created on: 20 Jun 2021
 *      Author: rishi
 */

#include <sstream>
#include <fstream>
#include "BufferCmds.h"
#include "CircBuffer.cpp"

using namespace std;

namespace DynDataStore {

	// instantiate and initialise required buffers
	DynDataStore::CircBuffer<char> charBuff;
	DynDataStore::CircBuffer<int> intBuff;
	DynDataStore::CircBuffer<float> floatBuff;
	DynDataStore::CircBuffer<double> doubleBuff;
	DynDataStore::CircBuffer<string> stringBuff;

	//simple state machine to assign active buffer
	int activeBuffer;

	// variables for storing input values
	char charVal;
	int intVal;
	float floatVal;
	double doubleVal;

	// get the current operation
	char BufferCmds::getBufferOperation(){
		return bufferOperation;
	}

	// set the current operation
	void BufferCmds::setBufferOperation(char opt){
		bufferOperation=opt;
	}

	// get the current value
	string BufferCmds::getBufferValue(){
		return bufferValue;
	}

	// set the current value
	void BufferCmds::setBufferValue(string val){
		bufferValue=val;
	}


	// setup instantiated buffer
	void BufferCmds::setupBuffer(){

		//update related cast variables according to inputs
		activeBuffer=(int)(bufferOperation-48);
		intVal=atoi(bufferValue.c_str());

		// set maximum buffer size according to input operation and value
		switch(bufferOperation){
			case '0':{
				charBuff.setMaxLength(intVal);
				cout << "Created char buffer of " << intVal << " elements.\n";
				break;
			}
			case '1':{
				intBuff.setMaxLength(intVal);
				cout << "Created integer buffer of " << intVal << " elements.\n";
				break;
			}
			case '2':{
				floatBuff.setMaxLength(intVal);
				cout << "Created float buffer of " << intVal << " elements.\n";
				break;
			}
			case '3':{
				doubleBuff.setMaxLength(intVal);
				cout << "Created double buffer of " << intVal << " elements.\n";
				break;
			}
			case '4':{
				stringBuff.setMaxLength(intVal);
				cout << "Created string buffer of " << intVal << " elements.\n";
				break;
			}
			default:{
				cout << "***ERROR: buffer not instantiated.***";
				break;
			}
		}
	}


	// interact with an instantiated buffer
	void BufferCmds::applyBufferOperation(){

		// update cast variables according to current inputs
		charVal=(bufferValue[0]);
		intVal=atoi(bufferValue.c_str());
		floatVal=atof(bufferValue.c_str());
		doubleVal=floatVal;

		// apply the corresponding data type and operation
		switch(bufferOperation){
			case 'a':{		// ADD ELEMENT
				if(activeBuffer==0)charBuff.addValue(charVal);
				else if(activeBuffer==1)intBuff.addValue(intVal);
				else if(activeBuffer==2)floatBuff.addValue(floatVal);
				else if(activeBuffer==3)doubleBuff.addValue(doubleVal);
				else if(activeBuffer==4)stringBuff.addValue(bufferValue);
				break;
			}
			case 'r':{		// READ FILE

				// read the named file
				cout << "Reading file content from " << bufferValue << ".\n";
				string textInput = fileHandling.readDataFile(bufferValue);

				// delimit incoming string using stringstream and cast outputs
				stringstream iss(textInput);
				string newValue;
				while(getline(iss,newValue,',')){
					if (iss.bad()) break;
					stringstream convertor(newValue);
					convertor >> newValue;
					if(activeBuffer==0)charBuff.addValue(newValue[0]);
					else if(activeBuffer==1)intBuff.addValue(atoi(newValue.c_str()));
					else if(activeBuffer==2)floatBuff.addValue(atof(newValue.c_str()));
					else if(activeBuffer==3)doubleBuff.addValue(atof(newValue.c_str()));
					else if(activeBuffer==4)stringBuff.addValue(newValue);
				}
				break;
			}
			case 'p':{		// PRINT ELEMENT
				if(activeBuffer==0)cout << "Element " << intVal << " is: " << \
						charBuff.getValue(intVal) << ".\n";
				else if(activeBuffer==1)cout << "Element " << intVal << " is: " << \
						intBuff.getValue(intVal) << ".\n";
				else if(activeBuffer==2)cout << "Element " << intVal << " is: " << \
						floatBuff.getValue(intVal) << ".\n";
				else if(activeBuffer==3)cout << "Element " << intVal << " is: " << \
						doubleBuff.getValue(intVal) << ".\n";
				else if(activeBuffer==4)cout << "Element " << intVal << " is: " << \
						stringBuff.getValue(intVal) << ".\n";
				break;
			}
			case 's':{		// WRITE FILE
				ofstream dataOutput(bufferValue);
				if(activeBuffer==0){
					for(unsigned int i=0; i<charBuff.checkLength(); i++){
						dataOutput<< charBuff.getValue(i) << ",";
					}
				};
				if(activeBuffer==1){
					for(unsigned int i=0; i<intBuff.checkLength(); i++){
						dataOutput<< intBuff.getValue(i) << ",";
					}
				};
				if(activeBuffer==2){
					for(unsigned int i=0; i<floatBuff.checkLength(); i++){
						dataOutput<< floatBuff.getValue(i) << ",";
					}
				};
				if(activeBuffer==3){
					for(unsigned int i=0; i<doubleBuff.checkLength(); i++){
						dataOutput<< doubleBuff.getValue(i) << ",";
					}
				};
				if(activeBuffer==4){
					for(unsigned int i=0; i<stringBuff.checkLength(); i++){
						dataOutput<< stringBuff.getValue(i) << ",";
					}
				};
				cout << "Writing file content to " << bufferValue << ".\n";
				break;
			}
			default:{
				cout << "***ERROR: operation not completed.***";
				break;
			}

		}
	}

} /* namespace DynDataStore */
