#include <stdio.h>                             // A statement to get functions of stdio and then provide it to the compiler 
                                               // 
#define COUNT 20                               // Giving a value of 20 to COUNT  
                                               // 
int pascal[COUNT][COUNT];                      // An array named pascal which has COUNT value as its size
                                               // 
                                               // 
int numlen (int num)                           // A function which will be used in order to calculate the length of the numbers
{                                              // 
  int size = 0;                                // Setting up the integer 'size' and giving a value of 0 on integer 'size'  
  while ( num > 0 )                            // A while loop statement which means "when a value of int num is bigger than zero" 
    {                                          // 
      num /=10;                                // it means  num = num/10.  
      size++;                                  // it means size = size+1. So, size is getting +1
    }                                          // 
  return size;                                 // Returning the loop to the value of 'size' and its value is 0  
}                                              // 
                                               // 
int get_linelen(int row)                       // A function which will be used in order to calculate the length of the lines 
{                                              // 
  int i;                                       // Setting up the integer 'i' 
  int charcount = 0;                           // Setting up the integer 'charcount' and provide a value of 0 to it
  for ( i=0 ; i<=row ; i++ )                   // A for loop statement which means "a value of
    charcount += numlen(pascal[row][i]) + 1;   // it means charcount = charcount + numlen(pascal[row][i]) +1
  return charcount;                            // Returning the loop to the value of 'charcount' 
}                                              // 
                                               // 
void generate_data()                           // A void function which will not return any values and it will used in order to calculate the data  
{                                              // 
  int row,j;                                   // The declaration of integer 'row' and 'j'   
  for ( row=1 ; row<=COUNT ; row++)            // For loop statement and its condition is that row should has a value of 1, row is less than or equal to a value 
					       // of COUNT and row is getting bigger with  a value of 1 
    {                                          // 
      if ( row == 1 )                          // If statement which meanus " when  'row'  is equal to 1 
        {                                      // 
          pascal[row][0] = 1;                  // The array of pascal which becomes a value of 1 when it has a value of row and 0 inside. 
          continue;                            // 
        }                                      // 
      pascal[row][0] = 1;                      // The array of pascal which becomes a value of 1 when it has a value of row and 0 inside.  
      for ( j=1 ; j<row ; j++ )                // 
        {                                      // 
          pascal[row][j] = pascal[row-1][j-1]  // 
            + pascal[row-1][j];                // 
        }                                      // 
    }                                          // 
}                                              // 
                                               // 
void print_one_row(int row, int maxlinelen)    // 
{                                              // 
  int i;                                       // 
  int curlen = get_linelen(row);               // 
  int needspaces = maxlinelen/2 - curlen/2;    // 
  while (needspaces-->0)                       // 
    putchar(' ');                              // 
  for ( i=0 ; i<row ; i++ )                    // 
    printf ("%d ", pascal[row][i]);            // 
  printf("\n");                                // 
}                                              // 
                                               // 
int                                            // 
main(void)                                     // 
{                                              // 
  int row,i,j;                                 // 
  int maxlinelen;                              // 
  generate_data();                             // 
                                               // 
                                               // 
  maxlinelen=get_linelen(COUNT-1);             // 
  for ( row=1 ; row<COUNT ; row++ )            // 
    print_one_row(row, maxlinelen);            // 
                                               // 
  for ( row=COUNT-2 ; row>=1 ; row-- )         // 
    print_one_row(row, maxlinelen);            // 
                                               // 
                                               // 
}                                              // 
