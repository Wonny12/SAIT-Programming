#include <stdio.h>
#define COUNT 17

int main(void)
{ 
	int loop,loop2,num;
	int space;
	num = 1;

	for (loop=0; loop<COUNT; loop++) {
		for (space=loop; space<COUNT; space++)
			printf(" ");
	
		for (loop2=0; loop2<=loop; loop2++) { 
			if (loop2==0 || loop==0) 
				num = 1;
			else 
				num = num*(loop-loop2+1)/loop2;
			
			printf("%d ", num);
		} 
		printf("\n");
	} 
}
