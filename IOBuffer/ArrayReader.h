/*
 * ArrayLoader.h
 *
 *  Created on: Oct 21, 2011
 *      Author: cepera
 */

#ifndef ARRAYLOADER_H_
#define ARRAYLOADER_H_

#include "Reader.h"

class ArrayReader :public Reader
{
public:
	ArrayReader(char* aray);
	~ArrayReader();

	void fill(char* ptr, unsigned int position, unsigned int length);

private:
	char* 					array;

	unsigned int getLength(char* array);

};

#endif /* ARRAYLOADER_H_ */
