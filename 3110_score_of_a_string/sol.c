#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*
    You are given a string s.
    The score of a string is defined as sum of the absoule difference between the ASCII values of adjacent characters.
*/

int stringScore(char *s)
{
    int i = 0;
    int sum = 0;

    while(*(s+i) != '\0')
    {
        if((i+1) == strlen(s))  // this if check can be avoided, as well as the strlen() call for each iteration
        {
            break;
        }
        sum += (((int)(*(s+i)) - (int)(*(s+i+1))) < 0) ? ((int)(*(s+i)) - (int)(*(s+i+1)))*(-1) : ((int)(*(s+i)) - (int)(*(s+i+1)));
        i++;    
    }

    return sum;
}

int main()
{
    char *pero = "hello";
    int aa = stringScore(pero);
    return 0;
}