/*
 * TextHandler.h
 *
 *  Created on: Oct 21, 2011
 *      Author: cepera
 */

#ifndef TEXTHANDLER_H_
#define TEXTHANDLER_H_


class IHandler
{

public:
	IHandler();
	virtual ~IHandler();

	/**
		returns:
			(int) == 10 	end-of-file
			(int) == -1		error
			else			normal character
	 */
	char getChar();
	void ungetChar(unsigned int step = 1);

protected:
	virtual char getChar(unsigned int position){return 0;};

private:
	unsigned int					pointer;

};


#endif /* TEXTHANDLER_H_ */
