#include <stdio.h> 
#define COUNT 80 
unsigned long long fibo[COUNT];  

int digit_count (unsigned long long x) { 
		int n; 
		if(x<10) n=1; 
		else if(x<100) n=2;
		else if(x<1000) n=3; 
		else if(x<10000) n=4; 
		else if(x<100000) n=5; 
		else if(x<1000000) n=6; 
		else if(x<10000000) n=7; 
		else if(x<100000000) n=8; 
		else if(x<1000000000) n=9; 
		else if(x<10000000000) n=10; 
		else if(x<100000000000) n=11; 
		else if(x<1000000000000) n=12; 
		else if(x<10000000000000) n=13; 
		else if(x<100000000000000) n=14; 
		else if(x<1000000000000000) n=15; 
		else if(x<10000000000000000) n=16;
		else if(x<100000000000000000) n=17;
		else if(x<1000000000000000000) n=18; 	
		else n = 19;
		return n; 
} 

void main () 
{
	int cal, sum=0, n; 

	for(cal=0; cal<COUNT; cal++) { 
	
		if (cal==0) { 
			fibo[cal]=1;
		}	
		else if (cal==1) { 
			fibo[cal]=1; 
		} 
	
		else if (cal>=2) {  
			fibo[cal]= fibo[cal-1]+fibo[cal-2]; 
		} 
		printf("%llu ", fibo[cal]); 
		n = digit_count(fibo[cal]);
		sum += n+1; 
		if ( sum > 80 ) { 
			printf("\n"); 
			sum = 0;
		}
	} 
} 
 
	
		  

	

			 
			
		
