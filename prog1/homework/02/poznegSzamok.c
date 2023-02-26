#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, poz = 0, neg = 0;
    printf("Egesz szam (vege: 0): ");
    scanf("%d", &n);

    while(n != 0)
    {
        if (n > 0){
            ++poz;
        }
        else{
            ++neg;
        }

        printf("Egesz szam (vege: 0): ");
        scanf("%d", &n);
    }

    printf("\nA pozitiv elemek szama: %d", poz);
    printf("\nA negativ elemek szama: %d", neg);

    return 0;
}
