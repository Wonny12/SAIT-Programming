#include <stdio.h> 
#define COUNT 80 
unsigned long long fibo[COUNT];

int digit_count (unsigned long long x) { //80 chars
	int n;
	if(x<10) n=1;
	else if (x<100) n=2;
	else if (x<1000) n=3;
	else if (x<10000) n=4;
	else if (x<100000) n=5;
	else if (x<1000000) n=6;
	else if (x<10000000) n=7;
	else if (x<100000000) n=8;
	else if (x<1000000000) n=9;
	else if (x<10000000000) n=10;
	else if (x<100000000000) n=11;
	else if (x<1000000000000) n=12;
	else if (x<10000000000000) n=13;
	else if (x<100000000000000) n=14;
	else if (x<1000000000000000) n=15;
	else if (x<10000000000000000) n=16;
	else if (x<100000000000000000) n=17;
	else if (x<1000000000000000000) n=18;
	else n = 19; 
	return n; 
} 

void main() 
{ 
	int i, sum=0, n;
	for (i=0; i<COUNT; i++) {
		if (i==0) { 
			fibo[i]=1;
		} 
		else if (i==1) {
			fibo[i]=1;
		}
		else if (i>=2) { 
			fibo[i]= fibo[i-1]+fibo[i-2];
		}
		printf("%llu ", fibo[i]);
		n = digit_count(fibo[i]); 
		if (sum+n+1 > 80) { 
			printf("\n");
			sum = 0;
		} 
		printf("%llu ", fibo[i]); 
		sum += n+1; 
	} 
} 
