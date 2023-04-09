#include "prog1.h"
#include <stdio.h>
#include <string.h>

#define MAX 26

string feltolt_abc(int n, char tomb[])
{   
    for(int i = 0; i < n; i++)
    {
        tomb[i] = 'a' + i;
        
    }
    string result = tomb;

    return result;
}

int main()
{

    char tomb[MAX];
    int n = MAX;

    string abc = feltolt_abc(n, tomb);
    printf("Eredmeny: %s\n", abc);

    return 0;
}