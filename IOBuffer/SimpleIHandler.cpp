/*
 * SimpleHandler.cpp
 *
 *  Created on: Oct 21, 2011
 *      Author: cepera
 */
#include "Reader.h"
#include "SimpleIHandler.h"
#include <iostream>
using namespace std;


SimpleIHandler::SimpleIHandler(Reader* reader)
{
	this->reader = reader;
}

SimpleIHandler::~SimpleIHandler()
{
	delete reader;
}

char SimpleIHandler::getChar(unsigned int position)
{
	char* ch = new char[1];
	reader->fill(ch, position, 1);
	return *ch;
}



