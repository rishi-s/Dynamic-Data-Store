/*
 * CircBuffer.cpp
 *
 *  Created on: 15 Jun 2021
 *      Author: rishi
 */


#include "CircBuffer.h"

using namespace std;


// check buffer length
template <typename T>
unsigned int CircBuffer<T>::checkLength(){
	return buffer.size();
}

// add value to buffer
template <typename T>
void CircBuffer<T>::addValue(T val){
	// shorten the buffer (lose oldest value) if it is at full size.
	if(checkLength()>=max_len) buffer.pop_front();
	// then add the new value
	buffer.push_back(val);
}

// return value of specified element
template <typename T>
T CircBuffer<T>::getValue(unsigned int loc){
	if(loc>max_len) {
		cout << "The location is out of the buffer range.\n";
	}
	return buffer.operator[](loc);
}

// change value of specified element
template <typename T>
void CircBuffer<T>::setValue(unsigned int loc, T val){
	if(loc<=max_len){
		buffer.operator[](loc)=val;
	}
	else{
		cout << "The location is out of the buffer range.\n";
	}
}







