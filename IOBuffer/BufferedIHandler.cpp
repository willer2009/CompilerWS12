/*
 * BufferedHandler.cpp
 *
 *  Created on: Oct 21, 2011
 *      Author: cepera
 */

#include "BufferedIHandler.h"
#include <iostream>
using namespace std;

BufferedIHandler::BufferedIHandler(Reader* loader, unsigned int bufferedSize)
{
	this->bufferSize = bufferedSize;
	block_actual = new IBlock(loader, this->bufferSize);
	block_actual->loadNext(0);
}

BufferedIHandler::~BufferedIHandler()
{
	delete block_actual;
}

char BufferedIHandler::getChar(unsigned int position)
{
	return getChar(position / bufferSize, position % bufferSize);
}

char BufferedIHandler::getChar(unsigned int block_number, unsigned int block_position)
{
	if(block_actual->getNumber() != block_number)
	{
		//load block
		cout<<"Lade einen neuen Teil! \n";
		block_actual->loadNext(block_number);
	}
	return block_actual->getText()[block_position];
}
