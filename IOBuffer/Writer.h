/*
 * Writer.h
 *
 *  Created on: Oct 28, 2011
 *      Author: cepera
 */

#ifndef WRITER_H_
#define WRITER_H_

class Writer
{
public:
	virtual ~Writer();

	virtual bool out(char* text, int length)=0;
};

#endif /* WRITER_H_ */
