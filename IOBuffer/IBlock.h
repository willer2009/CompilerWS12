/*
 * Block.h
 *
 *  Created on: Oct 23, 2011
 *      Author: cepera
 */

#ifndef IBLOCK_H_
#define IBLOCK_H_

#include "Reader.h"
#include "Block.h"

class IBlock: public Block
{
public:
	IBlock(Reader* loader,unsigned int size);
	virtual ~IBlock();

	virtual void loadNext(unsigned int number);;
    unsigned int getNumber() const;

    static void swap(IBlock* b1, IBlock* b2);

protected:
    Reader *			loader;
    unsigned int 		number;
};

#endif /* BLOCK_H_ */
