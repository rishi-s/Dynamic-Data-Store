/*
 * fileIO.cpp
 *
 *  Created on: 23 Jun 2021
 *      Author: rishi
 */


#include "FileInput.h"


using namespace std;

namespace DynDataStore {


	string FileIO::readDataFile(string textSource){

		ifstream file(textSource);

		// create a string variable to read each line
		string dataIn;

		// check if file data is readable and read/convert only the first line
		if (file.good() ){
			cout << "FILE OK \n";
			getline(file, dataIn);
			stringstream convertor;
			convertor >> dataIn;
			cout << dataIn << "\n";
		}
		return dataIn;
	}


} /* namespace DynDataStore */
