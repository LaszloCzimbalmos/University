#include <stdio.h>
#include <stdlib.h>

#define LOWER 10
#define UPPER 99
#define MAX 10

void random_feltolt(int n, int tomb[], int also, int felso)
{

    for (int i = 0; i < n; i++)
    {
        tomb[i] = (rand() % (felso - also + 1)) + also;
    }
}

void tomb_adatok(int n, int tomb[], int *min, int *max, float *avg)
{
    int legkisebb = tomb[0], legnagyobb = tomb[0];
    int osszeg = 0;

    for (int i = 0; i < n; i++)
    {
        osszeg += tomb[i];

        if (tomb[i] < legkisebb)
        {
            legkisebb = tomb[i];
        }

        if (tomb[i] > legnagyobb)
        {
            legnagyobb = tomb[i];
        }
    }

    *avg = osszeg / n;
    *min = legkisebb;
    *max = legnagyobb;
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
    int tomb[MAX];
    int meret = MAX;
    int min, max;
    float avg;

    random_feltolt(meret, tomb, LOWER, UPPER);
    tomb_adatok(meret, tomb, &min, &max, &avg);

    printf("A tömb elemei: ");
    tomb_kiir(meret, tomb);

    printf("A legkisebb elem: %d\n", min);

    printf("A legnagyobb elem: %d\n", max);

    printf("Az elemek átlaga: %.1f\n", avg);

    return 0;
}