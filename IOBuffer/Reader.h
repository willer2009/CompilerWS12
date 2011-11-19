/*
 * Loader.h
 *
 *  Created on: Oct 21, 2011
 *      Author: cepera
 */

#ifndef LOADER_H_
#define LOADER_H_

#define ERROR -1

class Reader {
public:
	virtual ~Reader();
	/**
	    -1  	for error,
	    10 		for end-of-file,
        else 	normal char
	 */
	virtual void fill(char* ptr, unsigned int position, unsigned int length) = 0;

protected:
	unsigned int 			length;

	void fillErrors(char* ptr, unsigned int position, unsigned int length, char end = (char)ERROR );

};

#endif /* LOADER_H_ */
