/*
 * IOBuffer.cpp
 *
 *  Created on: Nov 8, 2011
 *      Author: cepera
 */

#include "IOBuffer.h"
#include "UnixFileReader.h"
#include "UnixFileWriter.h"

IOBuffer::IOBuffer(char *inputFileName, char *outputFileName)
{
	in = new DBuffIHandler(new UnixFileReader(inputFileName), BUFFER_SIZE);
	out = new BufferedOHandler(new UnixFileWriter(outputFileName), BUFFER_SIZE);
}

IOBuffer::~IOBuffer()
{
	delete in;
	delete out;
}

char IOBuffer::getChar()
{
	return in->getChar();
}



void IOBuffer::ungetChar(unsigned int step)
{
	in->ungetChar(step);
}



void IOBuffer::write(char *text, char *end)
{
	out->write(text, end);
}



void IOBuffer::write(char *text, char end)
{
	out->write(text, end);
}



void IOBuffer::write(char *text)
{
	out->write(text);
}



void IOBuffer::write(char *text, int length)
{
	out->write(text, length);
}

void IOBuffer::write(char ch)
{
	out->write(ch);
}





