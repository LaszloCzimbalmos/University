#include <stdio.h>

#define MAX 100

void tomb_kiir(int len, int arr[])
{
    for (int i = 0; i < len; i++)
    {
        printf("%d", arr[i]);

        if (i != len - 1)
        {
            printf(", ");
        }
    }
    puts("");
}

int benne_van_e(int n, int tomb[], int keresett)
{
    for (int i = 0; i < n; i++)
    {
        if (tomb[i] == keresett)
        {
            return 1;
        }
    }

    return 0;
}

void rendez(int n, int tomb[])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (tomb[i] > tomb[j])
            {
                int tmp = tomb[i];
                tomb[i] = tomb[j];
                tomb[j] = tmp;
            }
        }
    }
}

int main()
{

    printf("Adj meg 0 végjelig egész számokat az [1, 99] intervallumból!\n");
    int szamok[MAX], egyediek[MAX], szamok_hossz = 0, egyediek_hossz = 0, teszt;

    do
    {
        printf("Szám: ");
        scanf("%d", &teszt);

        if (teszt <= 99 && teszt >= 1)
        {
            szamok[szamok_hossz] = teszt;

            // volt-e mar az adott szam?
            if (benne_van_e(szamok_hossz, szamok, teszt) == 0)
            {
                egyediek[egyediek_hossz] = teszt;
                egyediek_hossz++;
            }

            szamok_hossz++;
        }
        else if (teszt != 0)
        {
            printf("A szám kívül esik az elfogadható intervallumon!\n");
        }

    } while (teszt != 0);

    puts("");
    printf("%d db különböző szám lett megadva.\n", egyediek_hossz);

    printf("Ezek (növekvő) soreendben: ");
    rendez(egyediek_hossz, egyediek);
    tomb_kiir(egyediek_hossz, egyediek);

    return 0;
}