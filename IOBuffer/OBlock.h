/*
 * OBlock.h
 *
 *  Created on: Oct 28, 2011
 *      Author: cepera
 */

#ifndef OBLOCK_H_
#define OBLOCK_H_

#include "Block.h"
#include "Writer.h"

class OBlock: public Block
{

public:
	OBlock(Writer* writer,unsigned int size);
	virtual ~OBlock();

	virtual void flush();
	virtual void add(char* text, int length);
    unsigned int getFreeSpace() const;

    static void swap(OBlock* b1, OBlock* b2);

protected:
    Writer *			writer;
    unsigned int 		freeSpace;
};

#endif /* OBLOCK_H_ */
