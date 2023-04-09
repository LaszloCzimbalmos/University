#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int hossza(char tomb[])
{
    int i = 0;
    while (tomb[i] != '\n')
    {
        i++;
    }

    return i;
}

int main()
{
    printf("Adj meg szavakat '*' végjelig.\n");

    char szo[MAX];
    int szamlal = 0, max = 0;

    do
    {
        printf("Szó: ");
        fgets(szo, MAX, stdin);

        if (szo[0] != '*' || hossza(szo) > 1)
        {
            szamlal++;
        }

        if (hossza(szo) > max)
        {
            max = hossza(szo);
        }

    } while (hossza(szo) > 1 || szo[0] != '*');

    puts("");
    printf("%d db szót adtál meg. A leghosszabb szó %d karakterből áll.\n", szamlal, max);

    return 0;
}