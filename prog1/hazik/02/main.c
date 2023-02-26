#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ossz = 0;
    for (int i = 1; i < 1000; ++i)
    {
        if ((i % 5 == 0) || (i % 3 == 0))
        {
            ossz += i;
        }

    }

    printf("Az ezertol kisebb szamok feltetelek szerinti osszege: %d\n", ossz);

    return 0;
}
