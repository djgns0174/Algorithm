#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    // the number of temperatures to analyse
    int n;
    scanf("%d", &n);

    if(n == 0) 
    {
        printf("0\n"); 
        return 0;
    }

    int answer = 5527;
    for (int i = 0; i < n; i++) {
        // a temperature expressed as an integer ranging from -273 to 5526
        int t;
        scanf("%d", &t);

        int temp = abs(t);
        
        if(t > 0 && temp == abs(answer)) answer = t;
        if(temp < abs(answer)) answer = t;
    }

    // Write an answer using printf(). DON'T FORGET THE TRAILING \n
    // To debug: fprintf(stderr, "Debug messages...\n");

    printf("%d\n", answer);

    return 0;
}