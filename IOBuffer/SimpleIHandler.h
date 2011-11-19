/*
 * SimpleHandler.h
 *
 *  Created on: Oct 21, 2011
 *      Author: cepera
 */

#ifndef SIMPLEHANDLER_H_
#define SIMPLEHANDLER_H_

#include "IHandler.h"
#include "Reader.h"

class SimpleIHandler :public IHandler
{

public:
	SimpleIHandler(Reader* reader);
	virtual ~SimpleIHandler();

	char getChar(unsigned int position);

private:
	Reader*			reader;

};

#endif /* SIMPLEHANDLER_H_ */
