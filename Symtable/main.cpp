/*

 * main.cpp
 *
 *  Created on: 22.10.2011
 *      Author: sylvain

#include "Symtable.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>

using namespace std;

int main()
{

	Symtable systab;
	TType::TType t = TType::IDENTIFIER;
	char test[20] = "test";
//	int c;
	int c1;
	int n = 0;
	while(n < 10000000){
		srand ( time(NULL) );
		c1 = rand() % 20;

		for (int i = 0; i < c1 - 1;i++){
			if(i == c1 - 1){
				test[c1 - 1] = '\0';
			}else{
				test[i] = (rand() % (122 - 97)) + 97;
			}
		}
		systab.insert(test, t);
		n++;
		cout << n << endl;
	}
	return 0;
}


*/
