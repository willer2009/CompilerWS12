/*
 * ArrayLoader.cpp
 *
 *  Created on: Oct 21, 2011
 *      Author: cepera
 */

#include "ArrayReader.h"
#include <iostream>
using namespace std;


ArrayReader::~ArrayReader()
{
	delete[] array;
}

ArrayReader::ArrayReader(char* array)
{
	this->array = array;
	this->length = getLength(array);
}

void ArrayReader::fill(char* ptr, unsigned int position, unsigned int length)
{
	if(position >= this->length)
	{
		fillErrors(ptr, 0, length);
	}
	else
	{
		for(unsigned int i = 0; i < length; i++)
		{
			char ch = array[position + i];
			if(ch == '\0')
			{
				ptr[i] = (char)10;
				if(++i < length)
				{
					fillErrors(ptr, i, length - i);
				}
				break;
			}
			ptr[i] = ch;
		}
	}
}


unsigned int ArrayReader::getLength(char* array)
{
	unsigned int size = 0;
	for(;array[size] != '\0';size++){}
	return ++size;
}

