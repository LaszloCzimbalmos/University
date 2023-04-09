#include "prog1.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int szamjegyek_osszege(string szam)
{
    int osszeg = 0;
    int len = strlen(szam);

    for(int i = 0; i < len; i++)
    {
        char szamjegy[] = {szam[i], '\0'};
        osszeg += atoi(szamjegy);
    }

    return osszeg;
}

int main()
{
    string szam = get_string("Szám: ");

    printf("A számjegyek összege: %d\n", szamjegyek_osszege(szam));

    return 0;
}