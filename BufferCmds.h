/*
 * BufferCmds.h
 *
 *  Created on: 20 Jun 2021
 *      Author: rishi
 */

#ifndef BUFFERCMDS_H_
#define BUFFERCMDS_H_

namespace DynDataStore {

	class BufferCmds {
	public:
		BufferCmds();
		virtual ~BufferCmds();

		// return state of buffer
		bool getBufferState();

		// change state of buffer
		void setBufferState(bool state);

		// buffer state machine variable for interfacing
		bool bufferInit;
	};

} /* namespace DynDataStore */

#endif /* BUFFERCMDS_H_ */
