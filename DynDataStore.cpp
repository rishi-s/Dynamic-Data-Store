#include <iostream>
#include "CircBuffer.h"
#include "CmdMenu.h"
#include "BufferCmds.h"



using namespace std;

int main(int argc, char **argv) {
	DynDataStore::BufferCmds interface;
	DynDataStore::CmdMenu bufferMenu(interface);

	/*PROBLEM: Need to initialise CircBuffBase base class so that a buffer
	 * can be instantiated perpetually for the duration of the program.
	 * Allocating a shared pointer to the base class is successful.
	 * However, then  assigning/casting the address of a templated class
	 * is proving difficult! Test lines below.
	 * Any pointers appreciated (ha ha!).
	 */
	shared_ptr<DynDataStore::CircBuffBase> *ptr;
	//ptr = DynDataStore::CircBuffer<int>(1024); // ERROR - incompatible type
	//ptr = dynamic_cast<DynDataStore::CircBuffer<int>(1024)>; // ERROR casting syntax for templated class problematic?
	return 0;
}


