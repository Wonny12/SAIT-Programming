#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	char *first_block; 

	//first_block = (char *)malloc(100);
	
	char *second_block; 
	
	//second_block = (char *)malloc(100);
	
	char *third_block;

	//third_block = (char *)malloc(100); 

	first_block = (char *)malloc(100);
	
	second_block = (char *)malloc(100);

	third_block = (char *)malloc(100); 

	strcpy(second_block, argv[1]); 
	
	free(second_block); 
} 
