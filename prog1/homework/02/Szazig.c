#include <stdio.h>
#include <stdlib.h>

int main()
{

    int ossz = 0;
    for(int i = 1; i <= 100; ++i)
    {
        ossz += i;
    }

    printf("Az elso szaz pozitiv szam osszege: %d\n", ossz);

    return 0;
}
