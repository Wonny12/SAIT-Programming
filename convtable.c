#include <stdio.h>
int main()
{ 
	int number = 0; 
	int i; 

	for(i=0; i<=256; i++) { 
		printf("%d %X\n" , number, number);
		number++; 
	} 
	return 0;
} 
