#include <stdio.h>
#define MAXMUL 5 
#define SEPERATOR() "+-----+-----+-----+-----+-----+"
int main()
{ 
	int row, col;
	row = 1;

	printf("$ multirect$\n");
	
	printf("%s\n", SEPERATOR());
	printf("|     |  1 |  2 |  3  |  4 |  5 |\n");
	
	while (row<MAXMUL) { 
		printf("%s\n", SEPERATOR());
		printf("|");
		printf("  %d ", row);

		for (col=1; col<=MAXMUL; col++) { 
			int cand = row*col;
	
			printf("| %2.0d ", cand);
		}

		printf("|\n");
		row++;
	}
	printf("%s\n", SEPERATOR());
	return 0; 
} 
	
