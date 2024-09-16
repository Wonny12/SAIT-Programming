#include <stdio.h> 
//the table showing the values of fahr, celsius
int main()
{ 
	float fahr, celsius;
	int lower, upper, step;

	lower = 240.0; 
	upper = -40.0;
	step = 10;

	celsius = lower;
	printf("+-------+---------+\n"); 
	printf("|Celsius|Fahrenheit|\n");
	while (celsius >= upper) { 
		printf("+-------+---------+\n");
		fahr = ((9.0/5.0)*celsius+32);
		printf("|  %3.0f  | %6.1f  |\n", celsius, fahr); 
		celsius -= step;
	} 
	printf("+-------+---------+\n");
} 
