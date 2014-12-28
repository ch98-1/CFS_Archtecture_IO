//Copyright (C) 2014-2015  Corwin Hansen
#ifndef MEMORY_H//include protection
	#define MEMORY_H

//Memory for the cpu to use
#include <string.h> //for simpler memory handling

#define word 4 //maximum size of one word (4 byte or 36 bit by default)
#define memsize 65535 //size of memory (2^16 - 1 byte by default)

unsigned char mem[memsize];//Memory

union registers{//register union
	unsigned long int i;//integer
	unsigned char b[word];//byte
};

void run();//run program

#endif