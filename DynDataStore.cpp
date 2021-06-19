#include <iostream>
#include "CircBuffer.h"
#include "CmdMenu.h"


using namespace std;


int main(int argc, char **argv) {
	string newArr[5]={"Integer","Float","String","Char","Double"};
	DynDataStore::CmdMenu menu(5,newArr," to create a new buffer with one of the following data types.");
	CircBuffer<int> newBuff(10);
	cin.get();
	return 0;
}
