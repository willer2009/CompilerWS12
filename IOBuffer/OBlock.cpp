/*
 * OBlock.cpp
 *
 *  Created on: Oct 28, 2011
 *      Author: cepera
 */

#include "OBlock.h"
#include <iostream>
using namespace std;


OBlock::OBlock(Writer* writer, unsigned int size): Block(size)
{
	this->writer =  writer;
	freeSpace = size;
}

OBlock::~OBlock()
{
	delete writer;
}

void OBlock::flush()
{
	writer->out(text, size - freeSpace);
	freeSpace = size;
}

void OBlock::add(char *text, int length)
{
	int position = size - freeSpace;
	for(int i = 0 ; i < length ; i++)
	{
		this->text[position + i] = text[i];
	}
	freeSpace -= length;
}



unsigned int OBlock::getFreeSpace() const
{
	return freeSpace;
}



void OBlock::swap(OBlock *b1, OBlock *b2)
{
}



