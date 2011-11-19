/*
 * BufferedOHandler.cpp
 *
 *  Created on: Oct 28, 2011
 *      Author: cepera
 */

#include "BufferedOHandler.h"
#include <iostream>
using namespace std;

BufferedOHandler::BufferedOHandler(Writer *writer, unsigned int bufferSize)
{
	block_actual = new OBlock(writer, bufferSize);
}



BufferedOHandler::~BufferedOHandler()
{
	block_actual->flush();
	delete block_actual;
}

void BufferedOHandler::write(char *text, int length)
{
	int free = 0;
	while( (free = block_actual->getFreeSpace()) < length )
	{
		block_actual->add(text, free);
		block_actual->flush();
		text += free;
		length -= free;
	}
	block_actual->add(text, length);
}

