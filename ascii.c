#include <stdio.h>

int main()
{ 
	int a;
	printf("Enter your name here: "); 
	scanf("%d", &a); 
	while ((a = getchar()) != '\n' && a !=EOF) { 
		printf("%c\t %d\t 0x%x\t\n", a,a,a); 
	} 
	return 0; 
} 
