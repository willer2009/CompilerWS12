/*
 * Block.h
 *
 *  Created on: Oct 24, 2011
 *      Author: cepera
 */

#ifndef BLOCK_H_
#define BLOCK_H_

class Block {
public:
	Block(unsigned int size);
	virtual ~Block();

    unsigned int getSize() const;
    char *getText() const;
    void setSize(unsigned int size);
    void setText(char *text);

    static void swap(Block* b1, Block* b2);

protected:
    unsigned int size;
    char *text;
};

#endif /* BLOCK_H_ */
