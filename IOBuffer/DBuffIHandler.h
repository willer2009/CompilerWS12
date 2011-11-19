/*
 * DBufferedHandler.h
 *
 *  Created on: Oct 18, 2011
 *      Author: cepera
 */

#ifndef DBUFFEREDHANDLER_H_
#define DBUFFEREDHANDLER_H_

#include "BufferedIHandler.h"
#include "IBlock.h"

class DBuffIHandler: public BufferedIHandler
{

protected:
	IBlock*		block_loaded;

public:
	DBuffIHandler(Reader* loader, unsigned int bufferSize = BUFFER);
	virtual ~DBuffIHandler();

protected:
	virtual char getChar(unsigned int block_number, unsigned int block_position);
	void swap(IBlock* b1, IBlock* b2);
};

#endif /* DBUFFEREDHANDLER_H_ */
