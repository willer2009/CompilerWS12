/*
 * OHandler.cpp
 *
 *  Created on: Oct 28, 2011
 *      Author: cepera
 */

#include "OHandler.h"

OHandler::~OHandler(){}

void OHandler::write(char *text, char* end)
{
	write(text, getSize(text, end));
}

void OHandler::write(char *text, char end)
{
	write(text, getSize(text, end));
}

void OHandler::write(char *text)
{
	write(text, getSize(text, '\0'));
}

void OHandler::write(char ch)
{
	write(&ch, 1);
}

int OHandler::getSize(char *text, char* end)
{
	int size = getSize(end, '\0');
	for(int i = 0; i < 1000 ; i++)
	{
		for(int j = 0; j < size && text[i + j] == end[j] ; j++)
		{
			if(j == size-1)
			{
				return i;
			}
		}
	}
	return getSize(text, '\0'); // <- fail
}

int OHandler::getSize(char *text, char ch)
{
	int i = 0;
	while(text[i] != ch)
	{
		i++;
	}
	return i;
}
