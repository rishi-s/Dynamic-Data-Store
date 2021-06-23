/*
 * fileIO.h
 *
 *  Created on: 23 Jun 2021
 *      Author: rishi
 *
 *      Class for loading .csv text data into a circular buffer.
 *      NOTE: Loads only the first line (row) of a standard .csv file.
 */

#ifndef FILEINPUT_H_
#define FILEINPUT_H_

#include <iostream>
#include <fstream>
#include <sstream>

namespace DynDataStore {


	class FileIO {
	public:

		// constructor
		FileIO(){}

		// destructor
		virtual ~FileIO(){}


		// read file
		std::string readDataFile(std::string textSource);


	private:


	};
} /* namespace DynDataStore */

#endif /* FILEINPUT_H_ */
