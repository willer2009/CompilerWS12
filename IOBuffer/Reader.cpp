/*
 * Loader.cpp
 *
 *  Created on: Oct 21, 2011
 *      Author: cepera
 */

#include "Reader.h"
#include <iostream>
using namespace std;

Reader::~Reader() {}

void Reader::fillErrors(char* ptr, unsigned int position, unsigned int length, char end)
{
	for(unsigned int i = 0; i < length; i++)
	{
		ptr[position + i] = end;
	}
}
