#include <stdio.h>
#define WIDTH 80
#define HEIGHT 25

//How to run the code: there are two options.
// 1) gcc -> ./a.out 25
// 2) gcc -> ./a.out [any value you want], the assignment requires 5 for the value input

char array[HEIGHT][WIDTH];

int function (int x, int height) //f(x) = parameter always should be ().
{ 
	int fval;
	int w =x % (2*height-2); //modulo function, calculating from 0 again if x is over maximum bounds(scale)

	if (w <height/2) //checking if it is in quarter 1, f(x) = x
		fval = w;
	else if (w < 3*height/2) //checking if it is in quarter 2,3 ,f(x) = -x
		fval = -(w-2*height/2) - 1;
	else
		fval = w-2*height+2;
	
	return fval;
} 

int main (int argc, char *argv[]) 
{ 
	int height;
	int x,y; 
	
	if (argc==1) { //if there is only 1 argument (a.out), height =25 
		height = atoi(argv[0]); //argv[0] will be a.out, atoi converts arguments and characters to integer.
		height = 25;
	} 

	else if (argc==2) { //if there are two arguments (a.out 5), height=value input
		height = atoi(argv[1]); //a.out is argv[0], value input is argv[1] 
	} 

	for (x=0; x<HEIGHT; x++) { //print space  
		for (y=0; y<WIDTH; y++) { 
			array[x][y] = ' '; 
		} 
	} 

	for (y=0; y<WIDTH; y++) { 
		array[HEIGHT/2][y] = '-'; //it will be marking HEIGHT half and puting - signature to the centre
	} 

	for (x=0; x<WIDTH; x++) { 
		y = (HEIGHT/2)-function(x,height); //putting stars
		array[y][x] = '*';
	} 

	for (x=0; x<HEIGHT; x++) { //putchar functions, printing the actual stars 
		for (y=0; y<WIDTH; y++) { 
			putchar(array[x][y]);
		} 
	putchar ('\n'); 
	} 
} 
