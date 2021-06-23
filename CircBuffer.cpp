/*
 * CircBuffer.cpp
 *
 *  Created on: 15 Jun 2021
 *      Author: rishi
 */


#include "CircBuffer.h"

using namespace std;

namespace DynDataStore{

	template <typename T>
	// check buffer length
	unsigned int CircBuffer<T>::checkLength(){
		return buffer.size();
	}

	template <typename T>
	// get maximum permitted buffer length
	unsigned int CircBuffer<T>::getMaxLength(){
		return max_len;
	}

	template <typename T>
	// set maximum permitted buffer length
	void CircBuffer<T>::setMaxLength(unsigned int len){
		max_len = len;
		cout << "LENGTH SET = " << len << "\n";
	}

	// add value to buffer
	template <typename T>
	void CircBuffer<T>::addValue(T val){
		// shorten the buffer (lose oldest value) if it is at full size.
		if(checkLength()==max_len) buffer.pop_front();
		// then add the new value
		buffer.push_back(val);
		cout << "VALUE ADDED = " << val << "\n";
	}

	// return value of specified element
	template <typename T>
	T CircBuffer<T>::getValue(unsigned int loc){
		if(loc>buffer.size()-1) {
			cout << "The location is out of range.\n";
		}
		return buffer.operator[](loc);
	}

	// change value of specified element
	template <typename T>
	void CircBuffer<T>::setValue(unsigned int loc, T val){
		if(loc<=max_len-1){
			if(loc<=buffer.size()-1)buffer.operator[](loc)=val;
		}
		else{
			cout << "The location is out of range.\n";
		}
	}

} /* namespace DynDataStore */





