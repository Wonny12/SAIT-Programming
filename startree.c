#include <stdio.h> 
#define ROWS 15 
#define TRUNK_HEIGHT 10 
#define TRUNK_WIDTH 4 

int main () 
{ 
	int starcount, starnumbers; 
	int treespace, treecount; 
	for (starcount=1; starcount<=ROWS; starcount++) { 
		for (starnumbers=starcount; starnumbers<=ROWS; starnumbers++) { 
			printf(" "); 
		}	
		
		for (starnumbers=1; starnumbers<=(starcount*2-1); starnumbers++) 		{ 
			printf("*"); 	

		} 
	printf("\n"); 
	} 	 

	for (treespace=0; treespace<TRUNK_HEIGHT; treespace++) { 
		for (treecount=0; treecount<=(TRUNK_HEIGHT+2); treecount++) { 
			printf(" "); 
		} 
		
		for (treecount=0; treecount<=TRUNK_WIDTH; treecount++) { 
			printf("H"); 
		} 
		printf("\n"); 
	} 

	return 0; 
} 

		
