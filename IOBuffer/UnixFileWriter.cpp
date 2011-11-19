/*
 * UnixFileWriter.cpp
 *
 *  Created on: Oct 28, 2011
 *      Author: cepera
 */
#include <iostream>
#include "UnixFileWriter.h"
#include <fcntl.h>
#include <unistd.h>
using namespace std;


UnixFileWriter::UnixFileWriter(char *file)
{
//	fDescr = open(file, O_CREAT);
	fDescr = open(file, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
}

UnixFileWriter::~UnixFileWriter()
{
	close(fDescr);
}

bool UnixFileWriter::out(char *text, int length)
{
	return write(fDescr, text, length * sizeof(char) ) >= 0;
}



