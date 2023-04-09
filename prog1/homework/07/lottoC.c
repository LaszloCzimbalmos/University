#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

void random_feltolt(int n, int tomb[], int also, int felso)
{
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        while(1)
        {
            int szam = (rand() % (felso - also + 1)) + also;

            if (!benne_van_e(n, tomb, szam))
            {
                tomb[i] = szam;
                break;
            }
        }
    }
}

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

int main()
{
    int n, also, felso;
    printf("Hány darab random számot kérsz?\n");
    scanf("%d", &n);

    int lotto_szamok[n];

    printf("Alsó határ: ");
    scanf("%d", &also);

    printf("Felső határ (zárt intervallum): ");
    scanf("%d", &felso);

    puts("");
    printf("A generált számok: ");

    random_feltolt(n, lotto_szamok, also, felso);
    rendez(n, lotto_szamok);
    tomb_kiir(n, lotto_szamok);

    return 0;
}