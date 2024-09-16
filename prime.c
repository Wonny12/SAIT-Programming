#include    <stdio.h>

#define COUNT   100

/* calculates the number of digits for a number */

int digit_count(int x)
{
    int n;
    if (x < 10) n = 1;
    else if (x < 100) n = 2;
    else if (x < 1000) n = 3;
    else if (x < 10000) n = 4;
    else if (x < 100000) n = 5;
    else if (x < 1000000) n = 6;
    else if (x < 10000000) n = 7;
    else if (x < 100000000) n = 8;
    else if (x < 1000000000) n = 9;
    else n = 10;
    return n;
}

int main()
{
    int i, j, cnt, sum=0, n;

    for (i=1,cnt=0; cnt<=COUNT; i++) {
        /* tests if a prime number */
        for (j=2; j<i; j++) {
            if ((i%j)==0) break;
        }
        if (i==1 || j==i) {
            n = digit_count(i);
            sum += n+1;
            if (sum > 80) {
                /* if line exceeds 80 chars, then new line */
                printf("\n");
                sum = 0;
            }

            /* prints a prime number */
            printf("%d ", i);
            cnt++;
        }
    }
    printf("\n");
    return 0;
}


