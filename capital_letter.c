#include <stdio.h> 
#include <string.h> 
#include <ctype.h> 
int main (int argc, char *argv[])
{ 
	char a[100];
	char b[100];

	if(argc!=3) {
		printf("Need two parameters on comand line\n");
	} 

	strcpy (a,argv[1]);
	strcpy (b,argv[2]);
	
	if(a[0]>= 'a' && a[0]<= 'z') { 
		a[0] = toupper(a[0]);
	} 
	
	if(b[0]>= 'a' && b[0]<= 'z') {
		b[0] = toupper(b[0]); 
	} 

	printf("%s, %s\n",b,a); 
	return 0;
} 
