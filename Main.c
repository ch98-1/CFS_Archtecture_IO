//Copyright (C) 2014-2015  Corwin Hansen
#include <stdio.h>//input and output
#include <stdlib.h>//standard stuff
#include "Memory.h"//Memory
#include "SDL.h"//SDL


int main(int argc, char *argv[]){
#if SIZE_MAX < 52428800 //if memory maximum is less then 50 MB 
	printf("Could not allocate 50MB of memory");//warning
	exit(EXIT_FAILURE);
#endif

	unsigned int x = 1;//set x as 1 in this memory for endianness checking
	if ((unsigned int)(((char *)&x)[0])){//if this was one
		printf("This machene will run in Little-Endian\n");//it is Little-Endian
	}
	else{///if it was not It is Big-Endian
		printf("This machene will run in Big-Endian\n");//it is Big-Endian
	}
	
	if (argc == 2){
		FILE *fp = fopen(argv[1], "rb");//open file at first argument as binary file for reading
		if (fp == NULL){//if file could not be opend
			printf("could not open file %s\n", argv[1]);//warn user that file could not be opened
			exit(EXIT_FAILURE);//end of program
		}
		memset(mem, 0, memsize);//clear memory
		fread(mem, 1, memsize, fp);//read starting memory from file
		printf("Read file in to memory\n Starting cpu...\n");//notify user that it is done reading from file
		//run things
		SDL_Init(SDL_INIT_VIDEO);//start SDL

		window = SDL_CreateWindow(//create window named CFS_Archtecture that is 320 by 240
			"CFS_Archtecture",                  // window title
			SDL_WINDOWPOS_UNDEFINED,           // initial x position
			SDL_WINDOWPOS_UNDEFINED,           // initial y position
			320,                               // width, in pixels
			240,                               // height, in pixels
			0				                  // no special flags
			);



		run();//run cpu
		while (1){//screen mouce, and keybord update for memory mapped io
			//Memory mapped IO
			//0 - 52198299:general memory.
			//52121500 - 52428699 : screen memory for 320 * 240 rgba color screen.Overwrites last screen.
			//52428700 - 52428703 : last character in keybord input in ascii.Reset to 0 after reading. 3 more bits at end for ease in 32 bit mode.
			//52428704 - 52428711 : x and y of mouce.
			//52428799 : End CPU if not 0.



			if (mem[memsize - 1]) break;//written in last byte of memory
		}




		SDL_Quit();//end of running SDL
		//end of run
		printf("cpu ended\n Starting to write to file...\n");//notify user that it is done running cpu and are now going to write to file
		fp = fopen(argv[1], "wb");//open file for writing in binary
		fwrite(mem, 1, memsize, fp);//write end result memory to file
		printf("finished writing to file\n");//notify user that it has finished writing to file
		exit(EXIT_SUCCESS);//end of program
	}
	else if(argc == 3){//compile assembly for Whatever Endianness that c compiler works with, with 4 byte long characters
		FILE *fp = fopen(argv[1], "r");//open file at first argument for reading as text file(assembly file)
		if (fp == NULL){//if file could not be opend
			printf("could not open file %s\n", argv[1]);//warn user that file could not be opened
			exit(EXIT_FAILURE);//end of program
		}
		FILE *rf = fopen(argv[2], "wb");//open file at second argument for writing as binary file(result)
		unsigned char buffer[2048];//2048 byte long buffer
		while (fscanf(fp, "%s", buffer) != EOF) {//keep reading until end of file is reached
			if (strcmp(buffer, "set1") == 0){//instruction in assembly
				buffer[0] = 0;//instruction number
				fwrite(buffer, 1, 1, rf);//write buffer
			}
			else if (strcmp(buffer, "set2") == 0){//instruction  in assembly
				buffer[0] = 1;//instruction number
				fwrite(buffer, 1, 1, rf);//write buffer
			}
			else if (strcmp(buffer, "set3") == 0){//instruction  in assembly
				buffer[0] = 2;//instruction number
				fwrite(buffer, 1, 1, rf);//write buffer
			}
			else if (strcmp(buffer, "set4") == 0){//instruction  in assembly
				buffer[0] = 3;//instruction number
				fwrite(buffer, 1, 1, rf);//write buffer
			}
			else if (strcmp(buffer, "set5") == 0){//instruction  in assembly
				buffer[0] = 4;//instruction number
				fwrite(buffer, 1, 1, rf);//write buffer
			}
			else if (strcmp(buffer, "set6") == 0){//instruction  in assembly
				buffer[0] = 5;//instruction number
				fwrite(buffer, 1, 1, rf);//write buffer
			}
			else if (strcmp(buffer, "get1") == 0){//instruction  in assembly
				buffer[0] = 6;//instruction number
				fwrite(buffer, 1, 1, rf);//write buffer
			}
			else if (strcmp(buffer, "get2") == 0){//instruction  in assembly
				buffer[0] = 7;//instruction number
				fwrite(buffer, 1, 1, rf);//write buffer
			}
			else if (strcmp(buffer, "get3") == 0){//instruction  in assembly
				buffer[0] = 8;//instruction number
				fwrite(buffer, 1, 1, rf);//write buffer
			}
			else if (strcmp(buffer, "get4") == 0){//instruction  in assembly
				buffer[0] = 9;//instruction number
				fwrite(buffer, 1, 1, rf);//write buffer
			}
			else if (strcmp(buffer, "get5") == 0){//instruction  in assembly
				buffer[0] = 10;//instruction number
				fwrite(buffer, 1, 1, rf);//write buffer
			}
			else if (strcmp(buffer, "get6") == 0){//instruction  in assembly
				buffer[0] = 11;//instruction number
				fwrite(buffer, 1, 1, rf);//write buffer
			}
			else if (strcmp(buffer, "get7") == 0){//instruction  in assembly
				buffer[0] = 12;//instruction number
				fwrite(buffer, 1, 1, rf);//write buffer
			}
			else if (strcmp(buffer, "get8") == 0){//instruction  in assembly
				buffer[0] = 13;//instruction number
				fwrite(buffer, 1, 1, rf);//write buffer
			}
			else if (strcmp(buffer, "reset") == 0){//instruction  in assembly
				buffer[0] = 14;//instruction number
				fwrite(buffer, 1, 1, rf);//write buffer
			}
			else if (strcmp(buffer, "add") == 0){//instruction  in assembly
				buffer[0] = 15;//instruction number
				fwrite(buffer, 1, 1, rf);//write buffer
			}
			else if (strcmp(buffer, "sub") == 0){//instruction  in assembly
				buffer[0] = 16;//instruction number
				fwrite(buffer, 1, 1, rf);//write buffer
			}
			else if (strcmp(buffer, "mult") == 0){//instruction  in assembly
				buffer[0] = 17;//instruction number
				fwrite(buffer, 1, 1, rf);//write buffer
			}
			else if (strcmp(buffer, "div") == 0){//instruction  in assembly
				buffer[0] = 18;//instruction number
				fwrite(buffer, 1, 1, rf);//write buffer
			}
			else if (strcmp(buffer, "mod") == 0){//instruction  in assembly
				buffer[0] = 19;//instruction number
				fwrite(buffer, 1, 1, rf);//write buffer
			}
			else if (strcmp(buffer, "inc") == 0){//instruction  in assembly
				buffer[0] = 20;//instruction number
				fwrite(buffer, 1, 1, rf);//write buffer
			}
			else if (strcmp(buffer, "dec") == 0){//instruction  in assembly
				buffer[0] = 21;//instruction number
				fwrite(buffer, 1, 1, rf);//write buffer
			}
			else if (strcmp(buffer, "cpy") == 0){//instruction  in assembly
				buffer[0] = 22;//instruction number
				union registers num;//number to get from 
				fscanf(fp, "%lu", &num.i);//read next number
				memmove(buffer + 1, num.b, word);//copy number after one read on buffer to buffer
				fwrite(buffer, 1, 1 + word, rf);//write buffer
			}
			else if (strcmp(buffer, "cmp") == 0){//instruction  in assembly
				buffer[0] = 23;//instruction number
				fwrite(buffer, 1, 1, rf);//write buffer
			}
			else if (strcmp(buffer, "if") == 0){//instruction  in assembly
				buffer[0] = 24;//instruction number
				fwrite(buffer, 1, 1, rf);//write buffer
			}
			else if (strcmp(buffer, "and") == 0){//instruction  in assembly
				buffer[0] = 25;//instruction number
				fwrite(buffer, 1, 1, rf);//write buffer
			}
			else if (strcmp(buffer, "or") == 0){//instruction  in assembly
				buffer[0] = 26;//instruction number
				fwrite(buffer, 1, 1, rf);//write buffer
			}
			else if (strcmp(buffer, "xor") == 0){//instruction  in assembly
				buffer[0] = 27;//instruction number
				fwrite(buffer, 1, 1, rf);//write buffer
			}
			else if (strcmp(buffer, "not") == 0){//instruction  in assembly
				buffer[0] = 28;//instruction number
				fwrite(buffer, 1, 1, rf);//write buffer
			}
			else if (strcmp(buffer, "sftr") == 0){//instruction  in assembly
				buffer[0] = 29;//instruction number
				fwrite(buffer, 1, 1, rf);//write buffer
			}
			else if (strcmp(buffer, "sftl") == 0){//instruction  in assembly
				buffer[0] = 30;//instruction number
				fwrite(buffer, 1, 1, rf);//write buffer
			}
			else if (strcmp(buffer, "nop") == 0){//instruction  in assembly
				buffer[0] = 31;//instruction number
				fwrite(buffer, 1, 1, rf);//write buffer
			}
		}
		exit(EXIT_SUCCESS);//end of program
	}
	printf("usage:\n %s <file> to run that memory.\n %s <asembly_text_file> <result>", argv[0]);//print out usage of this program
	exit(EXIT_FAILURE);//end of program
}
