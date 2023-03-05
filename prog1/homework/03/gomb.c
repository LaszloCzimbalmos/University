#include <stdio.h>
#include <math.h>

double get_double()
{
    double n;
    scanf("%lf", &n);
    return n;
}

double gomb_felszine(double r)
{
    return 4 * (r * r) * M_PI;
}

double gomb_terfogata(double r)
{
    return (4 * (r * r * r) * M_PI) / 3;
}

int main()
{
    double r;
    printf("Adja meg a gömb sugarát (cm): ");
    r = get_double();

    printf("\nFelszín: %.2lf cm^2\n", gomb_felszine(r));
    printf("Térfogat: %.2lf cm^3\n", gomb_terfogata(r));

    return 0;
}