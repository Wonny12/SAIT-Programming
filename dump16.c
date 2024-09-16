#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

FILE *fp;

#define BUFSIZE 16

char fname[80] = "text.txt";
short buf[BUFSIZE];

int main (int argc, char *argv[])
{
  long bytecount;
  size_t rv;
  int i;
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
      fprintf (stdout, "\n%08lx: ", bytecount);
      for ( i=0 ; i<rv ; i++ )
	{
	  fprintf (stdout, "%04x ", buf[i]);
	  bytecount++;
	}
      for ( i=rv ; i<BUFSIZE ; i++ )
	fprintf (stdout, "   ");
      for ( i=0 ; i<rv ; i++ )
	{
	  if ( buf[i] >= 0x20 && buf[i] < 0x7f )
	    putchar(buf[i]);
	  else
	    putchar(' ');
	}
    }
  putchar ('\n');
}

