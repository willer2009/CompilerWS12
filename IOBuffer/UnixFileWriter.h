/*
 * UnixFileWriter.h
 *
 *  Created on: Oct 28, 2011
 *      Author: cepera
 */

#ifndef UNIXFILEWRITER_H_
#define UNIXFILEWRITER_H_

#include "Writer.h"


class UnixFileWriter: public Writer {
public:
	UnixFileWriter(char* file);
	virtual ~UnixFileWriter();

	bool out(char* text, int length);

private:
	int 		fDescr;
};

#endif /* UNIXFILEWRITER_H_ */
