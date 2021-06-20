#include <iostream>
#include "CircBuffer.h"
#include "CmdMenu.h"



using namespace std;



	const unsigned short int numDataTypes=5;
	const unsigned short int numActions=5;

	string dataTypes[numDataTypes]={"Integer","Float","String","Char","Double"};
	string actionList[numActions]={"a – add vale to buffer (e.g. 'a:897', or 'a:0.8983774', or 'a:Kansas_City')", \
									"r – read file contents into using given filepath (e.g. 'r:./ThisData')", \
									"p - print element(s) separated by commas (e.g. 'p:1,4,17,32,803,2296')", \
									"s – save buffer to .csv format using given filename (e.g. 's:MyData')", \
									"q – close the buffer and quit t (e.g. 'q:')"};


	int main(int argc, char **argv) {
		DynDataStore::BufferCmds interface;
		DynDataStore::CmdMenu menu(numDataTypes,dataTypes,numActions,actionList, interface);
		CircBuffer<int> newBuff(10);
		cin.get();
		return 0;
	}

