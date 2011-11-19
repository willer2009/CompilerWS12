/*
 * UnixFileLoader.h
 *
 *  Created on: Oct 22, 2011
 *      Author: cepera
 */

#ifndef UNIXFILELOADER_H_
#define UNIXFILELOADER_H_

#include "Reader.h"

class UnixFileReader: public Reader
{

public:
	UnixFileReader(char* file);
	virtual ~UnixFileReader();

	void fill(char* ptr, unsigned int position, unsigned int length);

private:
	int 		fDescr;
};

#endif /* UNIXFILELOADER_H_ */
