/*
 * CircBuffer.h
 *
 *  Created on: 15 Jun 2021
 *      Author: rishi
 *
 *      A class for generating and accessing a user-defined circular data buffer.
 *
 */

#ifndef CIRCBUFFER_H_
#define CIRCBUFFER_H_
#include <iostream>
#include <deque>

namespace DynDataStore{
	class CircBuffBase{
	public:
		CircBuffBase(){}
		virtual ~CircBuffBase(){}

	private:

	};

	// Declaration of dynamic buffer template class.
	template<class T>
	class CircBuffer: public CircBuffBase{


	public:

		// constructor definition with member variable initialisation
		CircBuffer():max_len(0){
		}

		// destructor definition
		~CircBuffer(){
		}

		// check buffer length
		unsigned int checkLength();

		// check maximum permitted buffer length
		unsigned int getMaxLength();

		// set maximum permitted buffer length
		void setMaxLength(unsigned int len);

		// add value to buffer
		void addValue(T val);

		// return value of specified element
		T getValue(unsigned int loc);

		// change value of specified element
		void setValue(unsigned int loc, T val);


	private:

		unsigned int max_len;				// maximum length of buffer
		std::deque<T> buffer;				// buffer deque container

	};

} /* namespace DynDataStore */

#endif /* CIRCBUFFER_H_ */
