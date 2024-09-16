#include <stdio.h> 
#define ROWS 10 
int main () 
{ 
	int starcount; 
	int starnumbers;

	for (starcount=1; starcount<=ROWS; starcount++) { 
		for (starnumbers=1; starnumbers<=starcount; starnumbers++) { 
			printf("*");
		} 
		printf("\n"); 
	} 	
	return 0; 
}
