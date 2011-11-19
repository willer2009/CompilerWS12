/*
 * Block.cpp
 *
 *  Created on: Oct 23, 2011
 *      Author: cepera
 */

#include "IBlock.h"

IBlock::IBlock(Reader* loader,unsigned int size): Block(size)
{
	this->loader = loader;
}

IBlock::~IBlock()
{
	delete loader;
}

void IBlock::loadNext(unsigned int number)
{
	//delete[] block->text;
	this->number = number;
	loader->fill(text, number * size, size);
}

unsigned int IBlock::getNumber() const
{
    return number;
}

void IBlock::swap(IBlock* b1, IBlock* b2 )
{
	Block::swap(b1, b2);

	int temp = b1->number;
	b1->number = b2->number;
	b2->number = temp;
}


