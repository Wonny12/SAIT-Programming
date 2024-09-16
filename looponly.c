#include <stdio.h>
int main()
{ 
	int number; 
	int i,j;

	printf("put your number:");
	scanf("%d", &number);
	j = number;
	
	for(i=0; i<number; i++) { 
		if(i>9) { 
			i = i-10;
			printf("%d", i);
		} 
		else { 
			printf("%d", i);
		} 
		j--; 
		if (j==0) { 
			break;
		} 
	} 
	return 0; 
} 
