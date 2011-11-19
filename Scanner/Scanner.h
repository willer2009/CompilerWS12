/*
 * Scanner.h
 *
 *  Created on: 06.11.2011
 *      Author: sylvain
 */

#ifndef SCANNER_H_
#define SCANNER_H_
#include "../Automat/Automat.h"
#include "../IOBuffer/IOBuffer.h"
#include "../Symtable/Symtable.h"

class Scanner {
public:
	Scanner(char* inputFile, char* outpurFile);
	virtual ~Scanner();

	void start();

private:
	Automat*			automat;
	IOBuffer*	 		buffer;
};

#endif /* SCANNER_H_ */
