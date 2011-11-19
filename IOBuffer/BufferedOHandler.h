/*
 * BufferedOHandler.h
 *
 *  Created on: Oct 28, 2011
 *      Author: cepera
 */

#ifndef BUFFEREDOHANDLER_H_
#define BUFFEREDOHANDLER_H_

#include "OHandler.h"
#include "OBlock.h"
#define BUFFER 1000

class BufferedOHandler : public OHandler
{

public:
	BufferedOHandler(Writer* writer, unsigned  int bufferSize = BUFFER);
	virtual ~BufferedOHandler();

	virtual void write(char* text, int length);

protected:
	OBlock*				block_actual;

};

#endif /* BUFFEREDOHANDLER_H_ */
