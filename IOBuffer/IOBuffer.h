/*
 * IOBuffer.h
 *
 *  Created on: Nov 8, 2011
 *      Author: cepera
 */

#ifndef IOBUFFER_H_
#define IOBUFFER_H_

#define BUFFER_SIZE 20

#include "DBuffIHandler.h"
#include "BufferedOHandler.h"

class IOBuffer
{

public:
	IOBuffer(char* inputFileName, char* outputFileName);
	virtual ~IOBuffer();

	char getChar();
	void ungetChar(unsigned int step = 1);

	void write(char* text, char* end);
	void write(char* text, char end);
	void write(char* text);
	void write(char ch);
	void write(char* text, int length);

private:
	IHandler*		in;
	OHandler*	out;
};

#endif /* IOBUFFER_H_ */
