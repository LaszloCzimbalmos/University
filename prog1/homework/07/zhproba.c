#include "prog1.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{

    if (argc != 2)
    {
        printf("Szar\n");
        exit(1);
    }

    string bin = argv[1];
    int len = strlen(bin);
    int base = 2;
    int dec = 0;

    for (int i = 0; i < len; i++)
    {
        char digit[] = {bin[i], '\0'}; 
        if (i == 0)
        {
            dec += 1 * atoi(digit);
        }
        else
        {
            dec += base * atoi(digit);
            base *= 2;
        }
    }

    printf("%d\n", dec);

    return 0;
}