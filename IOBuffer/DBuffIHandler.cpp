/*
 * DBufferedHandler.cpp
 *
 *  Created on: Oct 21, 2011
 *      Author: cepera
 */
#include "DBuffIHandler.h"
#include <iostream>
using namespace std;

DBuffIHandler::DBuffIHandler(Reader* loader, unsigned int bufferSize)
												: BufferedIHandler(loader, bufferSize / 2)
{
	block_loaded = new IBlock(loader, this->bufferSize);
	block_loaded->loadNext(1);
}

DBuffIHandler::~DBuffIHandler()
{
//	delete block_loaded;
}

char DBuffIHandler::getChar(unsigned int block_number, unsigned int block_position)
{
	if(block_actual->getNumber() != block_number)
	{
		if(block_loaded->getNumber() != block_number)
		{
			//load block
			cout<<"Lade einen neuen Teil!\n";
			block_loaded->loadNext(block_number);
		}
		IBlock::swap(block_actual, block_loaded);
	}
	return block_actual->getText()[block_position];
}
