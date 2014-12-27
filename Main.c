//Copyright (C) 2014-2015  Corwin Hansen
#include <stdio.h>//input and output
#include <stdlib.h>//standard stuff
#include "Memory.h"//Memory


int main(int argc, char *argv[]){
	if (argc != 2){//if not right amount of argument
		printf("usage:\n %s <file>\n", argv[0]);//print out usage of this program
		exit(EXIT_FAILURE);//end of program
	}
	FILE *fp = fopen(argv[1], "r");//open file at first argument
	if (fp == NULL){//if file could not be opend
		printf("could not open file %s\n", argv[1]);//warn user that file could not be opened
		exit(EXIT_FAILURE);//end of program
	}
	memset(mem, 0, memsize);//clear memory
	fread(mem, 1, memsize, fp);//read starting memory from file
	printf("Read file in to memory\n Starting cpu...\n");//notify user that it is done reading from file
	run();//run cpu
	printf("cpu ended\n Starting to write to file...\n");//notify user that it is done running cpu and are now going to write to file
	fp = fopen(argv[1], "w");
	fwrite(mem, 1, memsize, fp);//write end result memory to file
	printf("finished writing to file\n");//notify user that it has finished writing to file
	exit(EXIT_SUCCESS);//end of program
}
