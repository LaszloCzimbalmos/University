#include <stdio.h>

int negyzet(int szam)
{
    return szam * szam;
}

int main()
{
    int negyzetek_osszege = 0;
    int osszeg_negyzete = 0;

    for(int i = 1; i <= 100; i++)
    {
        negyzetek_osszege += negyzet(i);
        osszeg_negyzete += i;
    }

    osszeg_negyzete = negyzet(osszeg_negyzete);

    printf("%d - %d = %d\n", osszeg_negyzete, negyzetek_osszege, osszeg_negyzete - negyzetek_osszege);

    return 0;
}