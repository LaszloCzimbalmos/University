#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, ossz = 0;
    printf("Egesz szam (vege: 0): ");
    scanf("%d", &n);

    while(n != 0)
    {
        ossz += n;
        printf("Egesz szam (vege: 0): ");
        scanf("%d", &n);

    }

    printf("\nAz elemek osszege: %d", ossz);

    return 0;
}
