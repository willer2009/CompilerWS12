/*
 * Main.cpp
 *
 *  Created on: Nov 16, 2011
 *      Author: cepera
 */
#include "Scanner.h"
#include <iostream>

using namespace std;

int main()
{
	Scanner* s = new Scanner("input.txt", "output.txt");
	s->start();
	delete s;
	return 0;
}
