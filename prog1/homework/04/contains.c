#include <stdio.h>

//Megadja, hogy egy adott elem benne van-e a tömbben.
int contains(int n, int arr[], int target)
{
    for(int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            return 1;
        }
    }

    return 0;
}

int main()
{
    int target = 12, len = 5;
    int arr1[] = {1, 2, 6, 23, 0};
    int arr2[] = {45, 23, 16, 12, 3};

    printf(contains(len, arr1, target) == 1 ? "Az elem benne van a tömbben." : "Az elem nincs benne a tömbben.");
    puts("");
    printf(contains(len, arr2, target) == 1 ? "Az elem benne van a tömbben." : "Az elem nincs benne a tömbben.");
    puts("");


    return 0;
}