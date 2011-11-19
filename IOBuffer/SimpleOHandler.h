/*
 * SimpleOHandler.h
 *
 *  Created on: Oct 28, 2011
 *      Author: cepera
 */

#ifndef SIMPLEOHANDLER_H_
#define SIMPLEOHANDLER_H_

#include "OHandler.h"
#include "Writer.h"

class SimpleOHandler: public OHandler
{

public:
	SimpleOHandler(Writer* w);
	virtual ~SimpleOHandler();

	virtual void write(char* text, int length);

private:
	Writer*	 			writer;
};

#endif /* SIMPLEOHANDLER_H_ */
