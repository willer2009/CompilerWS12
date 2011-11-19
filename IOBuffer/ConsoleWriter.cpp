/*
 * ConsoleWriter.cpp
 *
 *  Created on: Oct 28, 2011
 *      Author: cepera
 */

#include "ConsoleWriter.h"
#include <iostream>

using namespace std;

ConsoleWriter::ConsoleWriter(char* prefix, char* suffix)
{
	this->prefix = prefix;
	this->suffix = suffix;
}

ConsoleWriter::~ConsoleWriter()
{
}

bool ConsoleWriter::out(char* text, int length)
{
	cout<<prefix;
	for(int i = 0; i < length; i++)
	{
		cout<<text[i];
	}
	cout<<suffix;
	return true;
}
