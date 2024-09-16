#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
#include <errno.h> 
#include <ncurses.h> 

#define MAX_ROW 200 
#define MAX_COL 200 
#define DEFAULT_ROW 24 
#define DEFAULT_COL 80 
char default_life[DEFAULT_ROW][DEFAULT_COL] = { 
"................................................................................",
"................................................................................",
"................................................................................",
"................................................................................", 
"................................................................................",
"................................................................................",
"................................@..........@....................................",
"................................@..........@....................................",
"................................@..........@....................................",
"................................@..........@....................................",
"................................@..........@....................................",
"................................@..........@....................................",
"................................@..........@....................................",
"................................................................................",
"................................................................................",
"................................................................................",
"................................................................................",
"................................................................................",
"................................................................................",
"................................................................................",
"................................................................................",
"................................................................................",
};
short state[MAX_ROW][MAX_COL];
int rows = 24; 
int cols = 80; 

int get_live_count(int row, int col, int rows, int cols)
{ 
	int count = 0; 
	int i,j; 
	int row_start = row-1; 
	int row_end = row+1; 
	int col_start = col-1; 
	int col_end = col+1; 
	
	if (row_start < 0) {
		row_start = 0; 
	} 
	else if (row_end >= rows) { 
		row_end = rows-1; 
	} 
	if (col_start < 0) { 
		col_start = 0; 
	} 
	else if ( col_end >= cols) { 
		col_end = cols-1; 
	}  
	
	for (i=row_start; i <= row_end; i++) { 
		for (j=col_start; j <= col_end; j++) { 
			if (i==row && j==col) continue; 
			
			if (state[i][j] == 1) { 
				count++; 
			}
		} 
	} 
	return count; 
} 

void evolve_life(int rows, int cols) 
{ 
	int i,j,live_count[MAX_ROW][MAX_COL],alive;
	for (i=0; i<rows; i++) {
		for (j=0; j< cols; j++) { 
			live_count [i][j] = get_live_count(i,j,rows,cols); 
		} 
	} 
	
	for (i=0; i<rows; i++) {
		for(j=0; j<cols; j++) { 
			if (state[i][j] == 1) 
				if (live_count[i][j] ==2 || live_count[i][j] == 3) 
					alive = 1;   
				else { 
					alive = 0; 
				} 
			else if (state[i][j] ==0) { 
				if (live_count[i][j] == 3) 
					alive = 1; 
				else 
					alive = 0; 
			} 
			state[i][j] = alive; 
		} 
	} 
} 

void init_life_by_random()
{
	int i,j,n; 
	rows = DEFAULT_ROW;
	cols = DEFAULT_COL; 
	for (i=0; i<MAX_ROW; i++) { 
		for (j=0; j<MAX_COL; j++) { 
			n = rand () % 2; 
		
			state[i][j] = n; 
		} 
	} 
} 

void init_life_by_default () 
{ 
	int i,j; 
	rows = DEFAULT_ROW;
	cols = DEFAULT_COL; 
	for (i=0; i<DEFAULT_ROW; i++) {
		for (j=0; j<DEFAULT_COL; j++) { 
			if (default_life[i][j] == '@') { 
				state[i][j] = 1; 
			} 
			else { 
				state[i][j] = 0; 
			}  
		} 
	} 
} 

void init_life_by_file(char *file_name) 
{ 
	FILE *fp; 
	char *rv; 
	char str[MAX_COL];
	int i,j; 
	i = 0; 
	fp = fopen(file_name, "r");
	if (fp == NULL) {
		fprintf(stderr, "ERROR: fopen failed (%d, %s)\n", errno, strerror(errno)); 
		exit(-1); 
	} 
	while (1) { 
		rv = fgets (str, MAX_COL, fp); 
		if (rv == NULL) { 
			break;
		} 
		
		for (j=0; str[j]!='\n'; j++) {
			if (str[j] == '@') {
				state[i][j] = 1; 
			} 
			else {
				state[i][j] = 0; 
			} 
		} 
		i++; 
	} 
	fclose(fp); 
	rows = i; 
	cols = j; 
} 

int main( int argc, char *argv[]) 
{ 
	FILE *fp; 
	int opt_random = 0; 
	int i, tick; 
	tick = 0; 
	char *file_name = NULL; 
	
	if(argc!=1 && argc!=2) { 
		fprintf(stderr, "invalid option"); 
		exit(-1); 
	} 

	else if (argc == 2) { 
		if (strcmp(argv[1],"-random")==0) { 
			opt_random = 1; 
		}    
		else { 
			file_name = argv[1]; 
		} 
	} 
	if (opt_random ==1) {
 		init_life_by_random();
	} 
	else if (file_name!=NULL) { 
		init_life_by_file(file_name);
	}    

	else { 
		init_life_by_default();
	} 
	
	draw_init(rows,cols); 

	while(1) { 
		printf("generation %d\n", tick); 
		tick++;
		draw_life(rows,cols,state); 
		evolve_life(rows,cols);
		usleep(200000);
	} 
	draw_finish(); 
	return 0; 
} 
