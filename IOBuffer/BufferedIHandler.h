/*
 * BufferedHandler.h
 *
 *  Created on: Oct 21, 2011
 *      Author: cepera
 */

#ifndef BUFFEREDHANDLER_H_
#define BUFFEREDHANDLER_H_

#include "IHandler.h"
#include "IBlock.h"
#define BUFFER 1000

class BufferedIHandler: public IHandler
{

public:
	BufferedIHandler(Reader* reader,unsigned  int bufferSize = BUFFER);
	virtual ~BufferedIHandler();

protected:
	unsigned int		bufferSize;
	IBlock*				block_actual;

	char getChar(unsigned int position);
	virtual char getChar(unsigned int block_number, unsigned  int block_position);

};

#endif /* BUFFEREDHANDLER_H_ */
