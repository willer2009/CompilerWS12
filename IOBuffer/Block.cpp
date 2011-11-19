/*
 * Block.cpp
 *
 *  Created on: Oct 24, 2011
 *      Author: cepera
 */

#include "Block.h"
#include <stdlib.h>

Block::Block(unsigned int size)
{
	this->size = size;
	this->text = new char;
	posix_memalign((void**)this->text, sizeof(char), size * sizeof(char));
}

Block::~Block()
{
	delete[] text;
}

unsigned int Block::getSize() const
{
    return size;
}

char *Block::getText() const
{
    return text;
}

void Block::setSize(unsigned int size)
{
    this->size = size;
}

void Block::setText(char *text)
{
    this->text = text;
}

void Block::swap(Block* b1, Block* b2)
{
	char* temp = b1->getText();
	b1->setText(b2->getText());
	b2->setText(temp);
}

