#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

FILE *fp;

#define BUFSIZE 16

char fname[80] = "text.txt";
int buf[BUFSIZE];
int main (int argc, char *argv[])
{
  int bytecount;
  size_t rv;
  int i;
  /*char *file_name; 
  int opt_bitcount = 32;
  int opt_decimal = 0;
  
  for (i=1; i<argc-2; i++) {
        if (strcmp(argv[i],"-32")==0)
                opt_bitcount = 32;
        else if (strcmp(argv[i],"-16")==0)
                        opt_bitcount = 16;
        else if (strcmp(argv[i], "-d")==0)
                        opt_decimal = 1;
        else {
                fprintf(stderr, "invalid option %s\n", argv[i]);
                exit(-1);
        }
  }*/  
  strcpy(fname, argv[argc-1]);  
  fp = fopen (fname,"r");
  if ( fp == NULL )
    {
      fprintf (stderr, "ERROR: fopen failed (%d, %s)\n", errno, strerror (errno));
    }

  bytecount = 0;
  while (1)
    {
      rv = fread (buf, 1, BUFSIZE, fp);
      if ( rv<0 )
	{
	  fprintf (stderr, "ERROR: fread failed (%d, %s)\n", errno, strerror (errno));
	  exit (-1);
	}
      if ( rv == 0 )
	break;
      int *p = (int *) buf;
      short *q = (short *) buf; 
      fprintf (stdout, "[%08x]: ", bytecount);
      bytecount += rv; 
      for ( i=0 ; i<rv/4; i++ )
	{
	  int *p = (int *) buf;
	  fprintf (stdout, "%08x ", *p);
	  p++;
	}
      printf("\n"); 

      fprintf (stdout, "[%04x]: ", bytecount);
      bytecount += rv;
      for ( i=0 ; i<rv/2; i++ )
        {
          fprintf (stdout, "%04x ", *q);
          q++;
        }
      printf("\n");

      /*for ( i=rv ; i<BUFSIZE ; i++ )
	fprintf (stdout, "   ");
      for ( i=0 ; i<rv ; i++ )
	{
	  if ( buf[i] >= 0x20 && buf[i] < 0x7f )
	    putchar(buf[i]);
	  else
	    putchar(' ');
	}*/ 
    }
  putchar ('\n');
}

