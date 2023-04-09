#include <stdio.h>
#include <stdlib.h>

#define LOWER 10
#define UPPER 99
#define MAX 10

typedef struct
{
    int min;
    int max;
    float avg;

} TombAdatok;

void random_feltolt(int n, int tomb[], int also, int felso)
{

    for (int i = 0; i < n; i++)
    {
        tomb[i] = (rand() % (felso - also + 1)) + also;
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


TombAdatok tomb_adatai(int n, int tomb[])
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

    TombAdatok result;
    result.min = legkisebb;
    result.max = legnagyobb;
    result.avg = osszeg / n;

    return result;
}

int main()
{
    int tomb[MAX];
    int meret = MAX;

    random_feltolt(meret, tomb, LOWER, UPPER);

    printf("A tömb elemei: ");
    tomb_kiir(meret, tomb);

    TombAdatok adatok = tomb_adatai(meret, tomb);

    printf("A legkisebb elem: %d\n", adatok.min);

    printf("A legnagyobb elem: %d\n", adatok.max);

    printf("Az elemek átlaga: %.1f\n", adatok.avg);

    return 0;
}