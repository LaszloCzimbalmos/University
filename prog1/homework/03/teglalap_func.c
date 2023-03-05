#include <stdio.h>

int teglalap_kerulete(int a, int b)
{
    return 2 * (a + b);
}

int teglalap_terulete(int a, int b)
{
    return a * b;
}

int main()
{
    int a, b;

    printf("Add meg a téglalap \"a\" oldalát: ");
    scanf("%d",  &a);

    printf("Add meg a téglalap \"b\" oldalát: ");
    scanf("%d", &b);

    printf("\nTerület: %d cm^2\n", teglalap_terulete(a, b));
    printf("Kerület: %d cm\n", teglalap_kerulete(a, b));

    return 0;
}