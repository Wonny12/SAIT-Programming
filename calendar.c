#include    <stdio.h>
#include    <time.h>

time_t  get_epoch_time(int YY, int MM, int DD)
{
    struct tm   tm_val;

    tm_val.tm_year = YY - 1900;
    tm_val.tm_mon  = MM - 1;
    tm_val.tm_mday = DD;
    tm_val.tm_hour = 0;
    tm_val.tm_min = 0;
    tm_val.tm_sec = 0;

    return mktime(&tm_val);
}

int get_month(time_t epoch_time)
{
    struct tm   tm_val;
    localtime_r(&epoch_time, &tm_val); // converts epoch time to struct tm
    return tm_val.tm_mon + 1;
}

int get_last_day(int YY, int MM)
{
    int     DD = 28;
    time_t  epoch_time = get_epoch_time(YY, MM, DD+1);

    while (get_month(epoch_time)==MM) {
        epoch_time += 86400;
        DD++;
    }
    return DD;
}


int get_week_day(int YY, int MM, int DD)
{
    struct tm   tm_val;
    time_t      epoch_time;
    int         wd;
    epoch_time = get_epoch_time(YY, MM, DD);
    localtime_r(&epoch_time, &tm_val); // converts epoch time to struct tm
    wd = tm_val.tm_wday-1; // Sun=0 Mon=1 Tue=2 ...
    if (wd < 0) wd = 6;
    return wd;
}

void display_calendar(int YY, int MM)
{
    int wd, day, x, last_day;

    printf("         %d-%d\n", YY, MM);
    printf("Mon Tue Wed Thu Fri Sat Sun\n");

    last_day = get_last_day(YY, MM);
    wd = get_week_day(YY, MM, 1);

    for (x=0; x<wd; x++)
        printf("    ");

    for (day=1; day<=last_day; day++, wd++) {
        if (wd >= 7) {
            printf("\n");
            wd = 0;
        }
        printf("%3d ", day);
    }
    printf("\n");
}

int main()
{
    display_calendar(2017, 10);
    return 0;
}
