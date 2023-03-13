#include <stdio.h>

//megállapítja a legkisebb elemét egy tömbnek
int find_min(int n, int array[])
{
    int min = array[0];
    for(int i = 1; i < n; i++)
    {
        if (min > array[i])
        {
            min = array[i];
        }
    }

    return min;
}

//megállapítja a legnagyobb elemét egy tömbnek
int find_max(int n, int array[])
{
    int max = array[0];
    for(int i = 1; i < n; i++)
    {
        if (max < array[i])
        {
            max = array[i];
        }
    }

    return max;
}


int main()
{
    int len = 5;
    int array[] = {1, 4, 34, 98, 22};

    printf("A tömb legnagyobb eleme: %d\n", find_max(len, array));
    printf("A tömb legkisebb eleme: %d\n", find_min(len, array));

    return 0;
}