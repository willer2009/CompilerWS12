/*
 * ConsoleWriter.h
 *
 *  Created on: Oct 28, 2011
 *      Author: cepera
 */

#ifndef CONSOLEWRITER_H_
#define CONSOLEWRITER_H_

#include "Writer.h"

class ConsoleWriter: public Writer
{
public:
	ConsoleWriter(char* preffix = "", char* suffix = "");
	virtual ~ConsoleWriter();

	bool out(char* text, int length);

private:
	char* 		prefix;
	char* 		suffix;
};

#endif /* CONSOLEWRITER_H_ */
