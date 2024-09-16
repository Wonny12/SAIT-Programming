#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h> 
#include <ncurses.h>
#include <unistd.h>
void rstrip (char *text)  
{ 
	int space,blank; 
	space = -1; 
	blank = 0;
	while(text[space] != '\0') { 
		if(text[space] != ' ' && text[space] != '\t' && text[space] != '\n') { 
			space = blank; 
		} 
		blank++; 
	} 
}  

void iscsource (char *text) 
{ 
	FILE *fp; 
	fp = fopen("git log --raw", "r"); 
	int getcharacter = getc(fp);
	while (getcharacter != EOF) { 
		getcharacter = getc(fp);
	} 
} 
	
int main (int argc, char *argv[]) 
{ 
	FILE *fp;
	char *file_name = "git log --raw";
	char *rv;
	char str[100], str2[100]; 
	struct tm timenow; 
	fp = fopen("git log --raw", "r"); 
	if (fp == NULL) { 
		fprintf(stderr, "ERROR: fopen failed (%d, %s)\n", errno, strerror(errno));
		exit(-1);
	} 
	rv =fgets(str, 100, fp);
	while (rv!=NULL) { 
		fscanf(fp, "%[^\n]", str);
	} 
	strptime(rv, str, &timenow);
	return 0;
} 
	
		
