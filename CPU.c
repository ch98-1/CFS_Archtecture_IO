//Copyright (C) 2014-2015  Corwin Hansen
#include "Memory.h"


//became Little-endian in x86-64 system running windows 8.1
void run(){//starts infinate loop until last byte in memory are more then 1 or r1 + r4 reaches the maximum memory readable.
	union registers r1, r2, r3, r4, r5, r6, r7, r8;//declare all registers
	r1.i = 0, r2.i = 0, r3.i = 0, r4.i = 0, r5.i = memsize - 1, r6.i = word, r7.i = 0, r8.i = 0;//initialise all 8 registers to there starting values
	while (1){//infinate loop
		switch (mem[r4.i + r1.i]){//for new adress
		case 0:
			r1.i = r2.i;//set r1 to r2
			break;
		case 1:
			r1.i += 1;//increment next instruction pointer by 1
			unsigned long int r2cpy = r2.i;//get copy of r2
			if (r4.i + r3.i >= r5.i){//if memory is out of bounds
				r7.i = 1;//set out of bounds error
				break;
			}
			memmove(r2.b, mem + r4.i + r3.i, r6.i);//copy value pointed by r3 to r2
			r3.i = r2cpy;//move old copy of r2 to r3
			break;
		case 2:
			r1.i += 1;//increment next instruction pointer by 1
			r3.i = r2.i;//set r3 to r2
			break;
		case 3:
			r1.i += 1;//increment next instruction pointer by 1
			r4.i = r2.i;//set r4 to r2
			break;
		case 4:
			r1.i += 1;//increment next instruction pointer by 1
			r5.i = r2.i;//set r5 to r2
			break;
		case 5:
			r1.i += 1;//increment next instruction pointer by 1
			r6.i = r2.i;//set r6 to r2
			break;
		case 6:
			r1.i += 1;//increment next instruction pointer by 1
			r2.i = r1.i;//set r2 to r1
			break;
		case 7:
			r1.i += 1;//increment next instruction pointer by 1
			if (r4.i + r3.i >= r5.i){//if memory is out of bounds
				r7.i = 1;//set out of bounds error
				break;
			}
			memmove(mem + r4.i + r3.i, r2.b,  r6.i);//copy value in r2 to memory pointed by r3
			break;
		case 8:
			r1.i += 1;//increment next instruction pointer by 1
			r2.i = r3.i;//set r2 to r3
			break;
		case 9:
			r1.i += 1;//increment next instruction pointer by 1
			r2.i = r4.i;//set r2 to r4
			break;
		case 10:
			r1.i += 1;//increment next instruction pointer by 1
			r2.i = r5.i;//set r2 to r5
			break;
		case 11:
			r1.i += 1;//increment next instruction pointer by 1
			r2.i = r6.i;//set r2 to r6
			break;
		case 12:
			r1.i += 1;//increment next instruction pointer by 1
			r2.i = r7.i;//set r2 to r7
			r7.i = 0;//set r7 to 0
			break;
		case 13:
			r1.i += 1;//increment next instruction pointer by 1
			r2.i = r8.i;//set r2 to r8
			break;
		case 14:
			r1.i += 1;//increment next instruction pointer by 1
			r1.i = 0, r2.i = 0, r3.i = 0, r4.i = 0, r5.i = memsize - 1, r6.i = word, r7.i = 0, r8.i = 0;//initialise all 8 registers to there starting values
			break;
		case 15:
			r1.i += 1;//increment next instruction pointer by 1
			if (r2.i > r2.i + r3.i) r7.i = 2;//arithmatic overflow if this equation becomes true
			r2.i += r3.i;//add r3
			break;
		case 16:
			r1.i += 1;//increment next instruction pointer by 1
			if (r2.i < r2.i - r3.i) r7.i = 2;//arithmatic overflow if this equation becomes true
			r2.i -= r3.i;//subtract r3
			break;
		case 17:
			r1.i += 1;//increment next instruction pointer by 1
			if (r2.i * r3.i / r3.i != r2.i) r7.i = 2;//arithmatic overflow if this equation becomes true
			r2.i *= r3.i;//multiply by r3
			break;
		case 18:
			r1.i += 1;//increment next instruction pointer by 1
			r2.i /= r3.i;//divide by r3
			break;
		case 19:
			r1.i += 1;//increment next instruction pointer by 1
			r2.i = r2.i%r3.i;//do modulo operation by r3
			break;
		case 20:
			r1.i += 1;//increment next instruction pointer by 1
			if (r2.i > r2.i + 1) r7.i = 2;//arithmatic overflow if this equation becomes true
			r2.i++;//increment
			break;
		case 21:
			r1.i += 1;//increment next instruction pointer by 1
			if (r2.i < r2.i - 1) r7.i = 2;//arithmatic overflow if this equation becomes true
			r2.i--;//decrement
			break;
		case 22:
			r1.i += 1 + r6.i;//increment next instruction pointer by 1 + current word size
			if (r4.i + r1.i >= r5.i){//if memory is out of bounds
				r7.i = 1;//set out of bounds error
				break;
			}
			memmove(r3.b, mem + r4.i + r1.i - r6.i, r6.i);//copy value after instruction to r3
			break;
		case 23:
			r1.i += 1;//increment next instruction pointer by 1
			if (r2.i > r3.i){//if r2 was bigger
				r2.i = 1;//set r2 to 1
				r3.i = 0;//set r3 to 0
			}
			else if (r2.i < r3.i){//if r3 was bigger
				r2.i = 0;//set r2 to 0
				r3.i = 1;//set r3 to 1
			}
			else {//if both were equal
				r2.i = 0;//set both to 0
				r3.i = 0;
			}
			break;
		case 24:
			r1.i += 1;//increment next instruction pointer by 1
			if (r2.i) r1.i = r3.i;//if r2 were true, set r1 to r3
			break;
		case 25:
			r1.i += 1;//increment next instruction pointer by 1
			r2.i &= r3.i;//bitwise and
			break;
		case 26:
			r1.i += 1;//increment next instruction pointer by 1
			r2.i |= r3.i;//bitwise or
			break;
		case 27:
			r1.i += 1;//increment next instruction pointer by 1
			r2.i ^= r3.i;//bitwise xor
			break;
		case 28:
			r1.i += 1;//increment next instruction pointer by 1
			r2.i = ~r2.i;//bitwise not
			break;
		case 29:
			r1.i += 1;//increment next instruction pointer by 1
			r2.i >>= 1;//right shift by 1
			break;
		case 30:
			r1.i += 1;//increment next instruction pointer by 1
			r2.i <<= 1;//left shift by 1
			break;
		case 31:
			r1.i += 1;//increment next instruction pointer by 1
			break;
		default://default, unidentified instruction error
			r7.i = 3;//set error to 3
			break;
		}
		if (r4.i + r1.i >= memsize) break;//memory pointer out of bounds
		if (mem[memsize - 1]) break;//written in last byte of memory
	}
}

