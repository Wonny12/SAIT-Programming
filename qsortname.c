#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <errno.h> 
#include <time.h>
#define MAXNAMES 30000
#define MAXNAMELEN 80

FILE *fp;
char names[MAXNAMES][MAXNAMELEN];
char *pnames[MAXNAMES];
int namecount = 0;

int my_comp(const void *p, const void *q)
{ 
	return strcmp(p, q);
} 

int main(int argc, char **argv)
{ 
	int i;
	
	if (argc <2) { 
		fprintf(stderr, "we need a parameter plz!\n");
		exit(-1);
	} 

	fp = fopen(argv[1], "r");
	
	if (fp == NULL) { 
		fprintf(stderr, "Cannot open file %s (%d, %s)\n", argv[1], errno, strerror(errno));
		exit(-1);
	} 

	while(namecount < MAXNAMES) {
		char *rv;
		rv = fgets(names[namecount], MAXNAMELEN, fp);
		if (rv == NULL) 
			break;
		if (names[namecount][0] == '\n' || names [namecount][0] == '\0')
			continue;
		namecount++;
	} 
	
	qsort(names, namecount, MAXNAMELEN, my_comp); 
	for (i=0; i<10; i++) { 
		fprintf(stdout, "%d %s", i, names[i]);
	} 
	return 0;
} 
