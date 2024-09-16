#include <stdio.h> 
#include <stdlib.h> 
int fact_r(int n) 
{ 
	if (n>1) 
		return n*fact_r(n-1); 
	else 
		return 1; 
} 
int number = 0;

int main (int argc, char *argv[])
{ 
	
	if ( argc<2 ) { 
		printf("Not enough params\n"); 
		exit (-1); 
	} 
	number = strtol (argv[1], NULL, 10); 
	
	if ( argc>=2) { 
		int outlier;
		outlier = fact_r(number); 
		printf("%d\n", outlier);
	} 
} 
		
	//printf("Factorial of %d is %d\n", number,   ); 
	  
