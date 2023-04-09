#include <stdio.h>
#include <stdlib.h>

void tomb_kiir(int len, int arr[])
{
    for (int i = 0; i < len; i++)
    {
        printf("%d", arr[i]);

        if (i != len - 1)
        {
            printf(", ");
        }
    }
    puts("");
}

int main()
{
    int mennyiseg;

    printf("Hány db számot szeretnél bevinni?\n");
    scanf("%d", &mennyiseg);

    int bevitt_szamok[mennyiseg];
    int absz_szamok[mennyiseg];

    for (int i = 0; i < mennyiseg; i++)
    {
        printf("%d. Szám: ", i + 1);
        scanf("%d", &bevitt_szamok[i]);
        absz_szamok[i] = abs(bevitt_szamok[i]);
    }

    puts("");
    printf("A bevitt számok abszolút értékei: ");
    tomb_kiir(mennyiseg, absz_szamok);

    printf("A megadott számok: ");
    tomb_kiir(mennyiseg, bevitt_szamok);

    return 0;
}