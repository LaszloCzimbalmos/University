#include <stdio.h>

//megállapítja rendezett-e (jelen esetben növekvő-e) az adott tömb.
int rendezett_e(int n, int arr[])
{
    int i = 0;
    while(i < (n - 1))
    {
        if (arr[i] > arr[i + 1]){
            return 0;
        }
        i++;
    }

    return 1;
}

int main()
{
    int len = 5;
    int array1[] = {1, 5, 11, 56, 58};
    int array2[] = {1, 12, 6, 26, 11};

    printf(rendezett_e(len, array1) == 1 ? "A tömb rendezett" : "A tömb NEM rendezett.");
    puts("");
    printf(rendezett_e(len, array2) == 1 ? "A tömb rendezett" : "A tömb NEM rendezett.");
    puts("");

    return 0;
}