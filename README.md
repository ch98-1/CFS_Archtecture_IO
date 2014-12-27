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

Registers: Set to reset value at start.  
1: Points to memory of next instruction. Increments every time it is used so it points to next instruction before this instruction executes.  
2: First values used for general arithmatics. Can be used to read from or write to memory.  
3: Second value used for general arithmatics. Can be used to read from memory.  
4: Number added to every memory adress.  
5: Maximum memory adress. 0 means no adress max.  
6: Word size to read from memory in byte.  
7: Last error code. Can only be read. Resets when read.  
8: Number of operations from start or last time reset. Can only be read. Reset only by reset operation.  
  
  
Instruction set. 

hex, assembly, description  
0, set1, Sets r1 to value in r2.  
1, set2, Sets r2 to value in memory pointed by r3, and move value that was in r2 to r3.  
2, set3, Sets r3 to value in r2.  
3, set4, Sets r4 to value in r2.  
4, set5, Sets r5 to value in r2.  
5, set6, Sets r6 to value in r2.  
6, get1, Sets value in r2 to value in r1.  
7, get2, Sets memory pointed by r3 to r2.  
8, get3, Sets r2 to value in r3.  
9, get4, Sets r2 to value in r4.  
10, get5, Sets r2 to value in r5.  
11, get6, Sets r2 to value in r6.  
12, get7, Sets r2 to value in r7, then set r7 to 0.  
13, get8, Sets r2 to value in r8.  
14, reset, Set r1, r2, r3, r4, r7 and r8 to 0, r6 to Maximum word size, and r5 to maximum memory addressable.  
15, add, Add values in r2 and r3 and put result in r2. If overflow occurs, r2 will be all the lower bits in the result.  
16, sub, Subtract value in r3 from r2 and put result in r2. If r3 exceeds r2, r2 will be set to 0.   
17, mult, Multiplys r2 by r3 and put result in r2. If overflow occurs, r2 will be all the lower bits in the result.  
18, div, Divide r2 by r3 and put result in r2. If r3 exceeds r2, r2 will be set to 0.  
19, mod,  Divide r2 by r3 and put remainder in r2.  
20, inc, Increment r2 by 1. If overflow occurs, r2 will be all the lower bits in the result.  
21, dec, Decrement r2 by 1. If overflow occurs, r2 will be all the lower bits in the result.  
22, cpy<value>, Copy value after instruction to r3.  
23, cmp, Compare r2 and r3 and put 1 in larger value and 0 in smaller. Both becomes 0 if it were equal.  
24, if, If r2 is true(1 or bigger), set r1 to r3. If not, do nothing (r1 increments by instruction length like usual).  
25, and, do bitwise and on r2 and r3 then return result in r2.  
26, or, do bitwise or on r2 and r3 and return result in r2.  
27, xor, do bitwise xor on r2 and r3 and return result in r2.  
28, not, do bitwise not on r2 and return result in r2.  
29, sftr, do bitwise right shift on r2 by 1 and return result on r2.  
30, sftl, do bitwise left shift on r2 by 1 and return result on r2.  
31, nop, no operation. just increments r1 like usual.  
  
Error code list:  
  
0: No error yet.   
1: Memory out of bound. Trying to access memory greater then r5.  
2: Arithmatic overflow, or too big of a value to hold in r2.  
3: Unidentified instruction  