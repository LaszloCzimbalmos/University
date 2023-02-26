#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, db = 0;
    printf("Egesz szam (vege: 0): ");
    scanf("%d", &n);

    while(n != 0)
    {
        if (n > 0)
        {
            ++db;
        }
        printf("Egesz szam (vege: 0): ");
        scanf("%d", &n);
    }

    printf("\nA pozitiv elemek szama: %d", db);

    return 0;
}
