#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
double kor_kerulete(int r)
{
    return 2 * r * M_PI;
}

double kor_terulete(int r)
{
    return r * r * M_PI;
}

int main()
{
    int r;
    printf("Adja meg a kör sugarát (cm): ");
    scanf("%d", &r);

    printf("\nTerület: %.2lf cm^2\n", kor_terulete(r));
    printf("Kerület: %.2lf cm\n", kor_kerulete(r));

    return 0;
}