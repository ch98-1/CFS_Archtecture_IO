CFS_Archtecture
===============
Copyright (C) 2014-2015  Corwin Hansen  

##Corwins' Fairly Small Architecture##
  
It consists of CPU with 8 registers of same size, and memory with 8 bit /1 byte chunks.  
Size of registers in cpu are the size needed to adress all memory.   
First register is the strating memory adress to the next instruction to execute.   
This will increment after it is read so it will point to next instruction before first instruction executes.  
This only matters in instruction 0 and 6 (set1 and get1) so register1 can increment after instruction on anything else.  
Next 2 registers are 2 values for arethmatics used in calculation.  
Registers 4 and 5 is used to set a bound to accessible memory. Registers 6 is the size in bytes that will be read or written from memory.  
Register 7 will have last error code from reset. Risister 8 is number of operation from reset.  
There is no port io so imput and output will all be done by memory mapped io.  
Endianness depends on implementation.

Registers: Set to reset value at start.  
1: Points to memory of next instruction. Increments every time it is used so it points to next instruction before this instruction executes.  
2: First values used for general arithmatics. Can be used to read from or write to memory.  
3: Second value used for general arithmatics. Can be used to read from memory.  
4: Number added to every memory adress.  
5: Maximum memory adress. 0 means no adress max.  
6: Word size to read from memory in byte.  
7: Last error code. Can only be read. Resets when read.  
8: Number of operations from start or last time reset. Can only be read. Reset only by reset operation.  
  
  
Instruction set: 

hex, assembly, description  
0x00, set1, Sets r1 to value in r2.  
0x01, set2, Sets r2 to value in memory pointed by r3, and move value that was in r2 to r3.  
0x02, set3, Sets r3 to value in r2.  
0x03, set4, Sets r4 to value in r2.  
0x04, set5, Sets r5 to value in r2.  
0x05, set6, Sets r6 to value in r2.  
0x06, get1, Sets value in r2 to value in r1.  
0x07, get2, Sets memory pointed by r3 to r2.  
0x08, get3, Sets r2 to value in r3.  
0x09, get4, Sets r2 to value in r4.  
0x0A, get5, Sets r2 to value in r5.  
0x0B, get6, Sets r2 to value in r6.  
0x0C, get7, Sets r2 to value in r7, then set r7 to 0.  
0x0D, get8, Sets r2 to value in r8.  
0x0E, reset, Set r1, r2, r3, r4, r7 and r8 to 0, r6 to Maximum word size, and r5 to maximum memory addressable.  
0x0F, add, Add values in r2 and r3 and put result in r2. If overflow occurs, r2 will be all the lower bits in the result.  
0x10, sub, Subtract value in r3 from r2 and put result in r2. If r3 exceeds r2, r2 will be set to 0.   
0x11, mult, Multiplys r2 by r3 and put result in r2. If overflow occurs, r2 will be all the lower bits in the result.  
0x12, div, Divide r2 by r3 and put result in r2. If r3 exceeds r2, r2 will be set to 0.  
0x13, mod,  Divide r2 by r3 and put remainder in r2.  
0x14, inc, Increment r2 by 1. If overflow occurs, r2 will be all the lower bits in the result.  
0x15, dec, Decrement r2 by 1. If overflow occurs, r2 will be all the lower bits in the result.  
0x16, cpy (value), Copy value after instruction to r3.  
0x17, cmp, Compare r2 and r3 and put 1 in larger value and 0 in smaller. Both becomes 0 if it were equal.  
0x18, if, If r2 is true(1 or bigger), set r1 to r3. If not, do nothing (r1 increments by instruction length like usual).  
0x19, and, do bitwise and on r2 and r3 then return result in r2.  
0x1A, or, do bitwise or on r2 and r3 and return result in r2.  
0x1B, xor, do bitwise xor on r2 and r3 and return result in r2.  
0x1C, not, do bitwise not on r2 and return result in r2.  
0x1D, sftr, do bitwise right shift on r2 by 1 and return result on r2.  
0x1E, sftl, do bitwise left shift on r2 by 1 and return result on r2.  
0x1F, nop, no operation. just increments r1 like usual.  
  
Error code list:  
  
0: No error yet.   
1: Memory out of bound. Trying to access memory greater then r5.  
2: Arithmatic overflow, or too big of a value to hold in r2.  
3: Unidentified instruction  

Memory Mapped IO: 
Max word size is 4 byte.  
Memory is 50 megabyte or 52428800 byte.  
(memory represented in int)  
0 - 52198299:general memory. 
52121500 - 52428699 : screen memory for 320 * 240 rgba color screen. Overwrites last screen.  Color is written in abgr order with 1 byte each.  
52428700 - 52428703: last character in keybord input in ascii/unicode. Reset to 0 after reading. 3 more bits at end for ease in 32 bit mode.  
52428704 - 52428711: x and y of mouse movement.
52428712 - 52428719: x and y of mouse wheel movement.
52428720 - 52428727: right and reft of mouse button.
52428799 :End CPU if not 0.  