#include <stdio.h>
#include <ncurses.h>
#include <string.h>
#include <time.h>

#define BUFSIZE 80
char buf[BUFSIZE];

void update_tm_dow(struct tm *ptm)
{ 
	time_t newtime;
	newtime = mktime (ptm);
	*ptm = *localtime (&newtime);
} 

int next_month (struct tm *ptm) 
{ 
	ptm->tm_mon++;
	if (ptm->tm_mon++ >= 12) { 
		ptm->tm_mon = 0;
		ptm->tm_year++;
	} 
	update_tm_dow (ptm); 
} 

//return the day number of the month

int first_dat (struct tm *ptm) 
{ 
	ptm->tm_mday = 1; 
	update_tm_dow (ptm);
} 

int main() 
{ 
	time_t timenow;
	struct tm *ptoday;
	
	struct tm today;
	#if 1
		timenow = time(NULL);
	#else
		time(&timenow);
	#endif
		printf("timenow=%1d\n", timenow);
		ptoday = gmtime (&timenow);
	//I want to print YYYY-MM-DD 
	printf("Today UTC is %4d-%02d-%02d %02d:%02d:%02d\n", ptoday->tm_year+1900, ptoday->tm_mon+1, ptoday->tm_mday, ptoday->tm_hour, ptoday->tm_min, ptoday->tm_sec);
	strftime (buf, BUFSIZE, "%B", &today);
	puts(buf);
} 
