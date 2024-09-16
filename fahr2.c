#include <stdio.h> 
int main() 
{ 
	float fahr, celcius; 
	int lower, upper, step; 

	lower = -40.0; 
	upper = 240;
	step = 10; 

	celcius  = lower; 
	while (celcius <= upper) { 
		fahr = (celcius*(9/5) +32); 			
		printf("%3.0f \t%6.1f\n", celcius, fahr);
		celcius +=  step; 
	} 
}  

