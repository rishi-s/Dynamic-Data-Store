#include <iostream>
#include "CircBuffer.h"
#include "CmdMenu.h"
#include "BufferCmds.h"



using namespace std;




int main(int argc, char **argv) {
	DynDataStore::BufferCmds interface;
	DynDataStore::CmdMenu menu(interface);
	DynDataStore::CircBuffer<int> newBuffer(100);
	cin.get();
	cin.get();
	return 0;
}

