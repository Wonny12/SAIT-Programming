#include <stdio.h> 
int main (void) 
{ 
  int i=0; 
  char *mystring = "Hello World!\n"; 

  while (mystring[i] != '\0') 
    putchar(mystring[i++]);
     
 
 return 0;
} 
