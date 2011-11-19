/*
 * SimpleOHandler.cpp
 *
 *  Created on: Oct 28, 2011
 *      Author: cepera
 */

#include "SimpleOHandler.h"

SimpleOHandler::SimpleOHandler(Writer* w)
{
	this->writer = w;
}

SimpleOHandler::~SimpleOHandler()
{
	delete[] writer;
}

void SimpleOHandler::write(char* text, int length)
{
	writer->out(text, length);
}
