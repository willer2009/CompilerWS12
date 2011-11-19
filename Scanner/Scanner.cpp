/*
 * Scanner.cpp
 *
 *  Created on: 06.11.2011
 *      Author: sylvain
 */

#include "Scanner.h"
#include <iostream>
#include "../GlobalTypes/Token.h"

using namespace std;

Scanner::Scanner(char* input, char* output)
{
	buffer = new IOBuffer(input, output);
	automat = new Automat(buffer);
}

Scanner::~Scanner()
{
	delete buffer;
	delete automat;
}

void Scanner::start()
{
	Token* t;
//	while( t != 0)
//	{
//		cout<< t->getLexem() << endl;
//		t = automat->searchLexem();
//	}
	for(int i =0; i < 4; i++)
	{
		t = automat->searchLexem();
		//cout<< (bool)(t == 0) << "   ";
		//cout<< t->getLexem() << endl;
		buffer->write(t->getLexem());
		buffer->write((char)10);
	}
}



