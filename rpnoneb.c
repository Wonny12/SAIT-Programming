#include <stdio.h> 
#include <string.h>
float stack[100];
int n  = 0;

void push_stack (float num) 
{ 
	stack[n] = num; 
	n++;
} 

float pop_stack()
{ 
	n--;
	return stack[n];
} 

void display_stack(int argvcount)
{ 
	int i;
	if (argvcount == 2) {
		printf(" %10.6f : ",stack[n-1]);
	} 

	else { 
		printf ("[");
		for (i=0; i<n; i++) { 
			printf(" %.1f ", stack[i]);
		} 
		printf(" ] : ");
	} 
} 

int main (int argc, char *argv[]) 
{ 
	char a[100] = "";
	float result, opd1, opd2; 
	while (1) { 
		display_stack(argc);
		gets(a); 
	
		if ((strcmp(a,"q") ==0)) { 
			break;
		} 

		else if ((strcmp(a,"+")== 0)) { 
			opd2 = pop_stack();
			opd1 = pop_stack();
			result = opd1 + opd2;
			push_stack(result);
		} 
		else if ((strcmp(a,"-")== 0)) { 
			opd2 = pop_stack();
			opd1 = pop_stack();
			result = opd1 - opd2;
			push_stack(result);
		} 
		else if ((strcmp(a,"/")== 0)) { 
			opd2 = pop_stack();
			opd1 = pop_stack();
			result = opd1/opd2;
			push_stack(result);
		} 
		else if ((strcmp(a,"*")== 0)) { 
			opd2 = pop_stack();
			opd1 = pop_stack();
			result = opd1*opd2;
			push_stack(result);
		} 
		else { 
			push_stack(atoi(a));
		} 
	} 
	return 0;
} 
