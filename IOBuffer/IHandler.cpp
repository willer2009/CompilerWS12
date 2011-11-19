/*
 * Loader.cpp
 *
 *  Created on: Oct 21, 2011
 *      Author: cepera
 */

#include "IHandler.h"



IHandler::IHandler()
{
	this->pointer = -1;
}

IHandler::~IHandler()
{
}

char IHandler::getChar()
{
	return getChar(++pointer);
}

void IHandler::ungetChar(unsigned int step)
{
	pointer -= step;
}



