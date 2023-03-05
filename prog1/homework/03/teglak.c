#include <stdio.h>

int main()
{
    int n;

    printf("Magassag: ");
    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
    {
        int szokoz = n-i;
        int tegla = i;

        for(int j = 0; j < szokoz; j++)
        {
            printf(" ");
        }

        for(int k = 0; k < tegla; k++)
        {
            printf("#");
        }

        printf(" ");

        for(int h = 1; h <= i; h++)
        {
            printf("#");
        }

        printf("\n");
    }

    return 0;
}