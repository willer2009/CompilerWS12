/*
 * UnixFileLoader.cpp
 *
 *  Created on: Oct 22, 2011
 *      Author: cepera
 */

#include "UnixFileReader.h"
#include <stdio.h>
#include <fcntl.h>
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
using namespace std;


UnixFileReader::UnixFileReader(char* file)
{
	// fDescr = open(file, O_DIRECT| O_DIRECT);
	 fDescr = open(file, O_RDONLY);
	 if ( fDescr < 0)
	 {
		cout<<"File \""<<file<< "\" not found!"<<endl;
	 }

	 struct stat* st = new struct stat;
	 stat(file, st);
	 length = st->st_size;
}

UnixFileReader::~UnixFileReader()
{
	close(fDescr);
}

void UnixFileReader::fill(char* ptr, unsigned int position, unsigned int length)
{
	if(position >= this->length)
	{
		fillErrors(ptr, 0, length);
	}
	else
	{
		lseek(fDescr, position, SEEK_SET);
		int bytes_read = read(fDescr, ptr, length * sizeof(char));
		if(bytes_read < 0)
		{
			fillErrors(ptr, 0, length);
		}
		else if(bytes_read != length)
		{
			fillErrors(ptr, bytes_read, length - bytes_read);
		}
	}
}
