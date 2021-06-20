/*
 * CircBuffer.h
 *
 *  Created on: 15 Jun 2021
 *      Author: rishi
 *
 *      A class for generating and accessing a user-defined circular data buffer.
 */

#ifndef CIRCBUFFER_H_
#define CIRCBUFFER_H_
#include <iostream>
#include <deque>


// Declaration of dynamic buffer template class.
template<class T>
class CircBuffer {


public:

	// constructor definition with member variable initialisation
	CircBuffer(unsigned int len):max_len(len){
		std::cout <<"Buffer constructed\n";
	}

	// destructor definition
	virtual ~CircBuffer(){
		std::cout <<"Buffer destroyed\n";
	}


	/*
	 * 	Accessors and mutators:
	 */

	// check buffer length
	unsigned int checkLength();

	// add value to buffer
	void addValue(T val);

	// return value of specified element
	T getValue(unsigned int loc);

	// change value of specified element
	void setValue(unsigned int loc, T val);



private:

	/*
	* 	Class variables
	*/

	const unsigned int max_len;				// maximum length of buffer
	std::deque<T> buffer;					// buffer deque container

};

#endif /* CIRCBUFFER_H_ */
