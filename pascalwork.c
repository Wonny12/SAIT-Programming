#include <stdio.h>
#include "pascalwork.h" 

#define COUNT 20 

int pascal[COUNT][COUNT]; 
int maxlinelen; 

int main(void) 
{ 
	int row; 
	
	calculate_pascal (); 
	maxlinelen = get_linelen(COUNT-1); 
	
	for (row = 1; row<COUNT; row++ ) { 
		print_complete_row (row); 
	} 
	for (row=COUNT-2; row>0; row-- ) {
		print_complete_row (row); 
	} 
	
	return 0; 
}    

int numlen (int num)
{ 
	int size = 0; 
	while (num > 0) { 
		num /=10; 
		size++;
	} 
	return size; 
} 

int get_linelen(int row)
{ 
	int i;
	int charcount = 0;
	for (i=0; i<=row; i++) {
		charcount += numlen(pascal[row][i]) + 1; 
	} 
	return charcount;
} 

void calculate_pascal() 
{ 
	int row, j; 
	for (row =1 ;row<COUNT; row++) { 
		if (row ==1) {
			pascal[row][0] =1;
			continue; 
		} 
		pascal[row][0] = 1;
		for (j=1; j<row; j++) { 
			pascal[row][j] = pascal[row-1][j-1] + pascal[row-1][j];
		} 
	} 
}  

void print_leading_spaces (int count) 
{ 
	while (count-- > 0) { 
		putchar(' ');
	} 
} 

void print_one_row(int row)
{ 
	int i;
	for (i=0; i<row; i++) { 
		printf("%d ", pascal[row][i]);
	} 
	printf("\n"); 
} 

void print_complete_row(int row) 
{ 
	int curlen = get_linelen (row);
	int needspaces = maxlinelen/2 -curlen/2; 
	print_leading_spaces (needspaces);
	print_one_row (row); 
} 
