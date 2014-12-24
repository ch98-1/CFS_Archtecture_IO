8bitCPU
=======

My CPU simulator with 8 bit instruction sets architecture.

It consists of CPU with 4 risistors of same size, and memory with 8 bit chunks.
Size of risistors in cpu are the size needed to adress all memory. 
First risistor is the strating memory adress to the next instruction to execute. 
This will increment after it is read so it will point to next instruction before first instruction executes. 
Next 2 resistors are 2 values for arethmatics used in calculation. Any Imputs and outputs are treated as adress in memory.

Risistors: Set to 0 at start.
1: Points to memory of next instruction. Increments every time it is used so it points to next instruction before this instruction executes.
2: First values used for general arithmatics. Only value accesseble to read and write.
3: Second value used for general arithmatics.
4: Number added to every memory adress.


Instruction set. (<number>, <assembly>, <description>)

0, set1, Sets r1 to value in r2.
1, set2, Sets r2 to value in memory pointed by r3.
2, set3, Sets r3 to value in r2.
3, set4, Sets r4 to value in r2.
4, get1, Sets value in r2 to value in r1.
5, get2, Sets memory pointed by r3 to r2.
6, get3, Sets r2 to value in r3.
7, get4, Sets r2 to value in r4.
8, reset, Set r1, r2, and r3 to 0.
9, add, Add values in r2 and r2 and put result in r2. If overflow occurs, r2 will be all the lower bits in the result.
10, sub, Subtract value in r3 from r2 and put result in r2. If r3 exceeds r2, r2 will be set to 0. 
11, mult, Multiplys r2 by r3 and put result in r2. If overflow occurs, r2 will be all the lower bits in the result.
12, div, Divide r2 by r3 and put result in r2. If r3 exceeds r2, r2 will be set to 0.
13, mod,  Divide r2 by r3 and put remainder in r2.
14, inc, Increment r2 by 1. If overflow occurs, r2 will be all the lower bits in the result.
15, dec, Decrement r2 by 1. If overflow occurs, r2 will be all the lower bits in the result.
16, cpy<value>, Copy value after instruction to r2.

