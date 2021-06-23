#include <iostream>
#include "CircBuffer.h"
#include "CmdMenu.h"
#include "BufferCmds.h"
#include "FileInput.h"



using namespace std;



int main(int argc, char **argv) {
	DynDataStore::FileIO files;
	DynDataStore::BufferCmds interface(files);
	DynDataStore::CmdMenu bufferMenu(interface);

	return 0;
}


