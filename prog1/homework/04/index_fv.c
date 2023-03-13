#include <stdio.h>

//A függvény vissza adja a keresett elem indexét az adott tömbben.
//A függvény -1 -el tér vissza, ha nem található az adott elem a tömbben.
int find_index(int n, int arr[], int target)
{
    for(int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    int len = 5, target = 3;
    int arr[] = {11, 4, 5, 3, 2};
    int arr2[] = {1, 2, 4, 5, 6};
    int result = find_index(len, arr, target);
    int result2 = find_index(len, arr2, target);

    if (result >= 0)
    {
        printf("A keresett elem indexe a tömbben: %d\n", result);
    }
    else
    {
        printf("A tömbben nem található a keresett elem\n");
    }

    puts("");
    if (result2 >= 0)
    {
        printf("A keresett elem indexe a tömbben: %d\n", result2);
    }
    else
    {
        printf("A tömbben nem található a keresett elem\n");
    }

    return 0;
}