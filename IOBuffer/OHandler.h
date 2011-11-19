/*
 * OHandler.h
 *
 *  Created on: Oct 28, 2011
 *      Author: cepera
 */

#ifndef OHANDLER_H_
#define OHANDLER_H_

class OHandler
{
public:
	virtual ~OHandler();


	void write(char* text, char* end);
	void write(char* text, char end);
	void write(char* text);
	void write(char ch);
	virtual void write(char* text, int length){};

private:
	int getSize(char* text, char* end);
	int getSize(char* text, char end);
};

#endif /* OHANDLER_H_ */
