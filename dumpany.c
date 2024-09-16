#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

FILE *fp;

#define BUFSIZE 16

int main (int argc, char *argv[])
{ 
	int bytecount;
	size_t rv;
	int i;
	char *file_name;
	char buf[BUFSIZE]; 
	int opt_bitcount = 32;
	int opt_decimal = 0;
	for (i=1; i<=argc-2; i++) { 
		if (strcmp(argv[1], "-32")==0)
			opt_bitcount = 32;
		else if (strcmp(argv[i], "-16")==0)
			opt_decimal = 1;
		else {
			fprintf(stderr, "invalid option %s\n", argv[i]);
			exit(-1);
		} 
	} 
	file_name = argv[argc-1]; 
	fp = fopen (file_name, "r");
	if (fp == NULL) { 
		fprintf(stderr, "ERROR: fopen failed (%d, %s)\n", errno, strerror (errno));
		exit(-1);
	}

	bytecount = 0;
	while (1) {
		rv = fread (buf, 1, BUFSIZE, fp);
		if (rv<0) { 
			fprintf(stderr, "ERROR: fopen failed (%d, %s)\n", errno, strerror (errno));
			exit(-1);
		}
		if (rv == 0) { 
			break; 
		} 
		fprintf(stdout, "\n[%08x]: ", bytecount);
		bytecount += rv;
		if (opt_bitcount==32) { 
			int *p = (int *) buf;
			for (i=0; i<rv/4; i++) { 
				if (opt_decimal==1) { 
					fprintf(stdout, "%010u ", p[i]);
				} 
				else {
					fprintf(stdout, "%08x ", p[i]);
				}
			}

		} 
	
		else if (opt_bitcount == 16) { 
			short *p = (short *) buf;
			for (i=0; i<rv/2; i++) { 
				if (opt_decimal ==1) { 
					fprintf(stdout, "%05u ", p[i]);
				} 
				else { 
					fprintf(stdout, "%04x ", p[i]);
				}
			} 
		} 

		for (i=rv; i<BUFSIZE; i++) { 
			fprintf(stdout, "    ");
		} 
		for (i=0; i<rv; i++) {
			if (buf[i] >= 0x20 && buf[i] < 0x7f ) { 
				putchar(buf[i]);
			} 
			else { 
				putchar(' ');
			} 
		} 
	} 
	putchar('\n');
	printf("Total length %d (0x%x)\n", bytecount, bytecount);
} 
