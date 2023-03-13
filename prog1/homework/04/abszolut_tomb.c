#include <stdio.h>
#include <stdlib.h>

//vesszővel elválasztva írja ki a tömb elemeit
void tomb_kiir(int len, int arr[])
{
    
    for(int i = 0; i < len; i++)
    {
        printf("%d", arr[i]);

        if (i != len - 1){
            printf(", ");
        }
    }
    puts("");
}

//Adott tömb elemeinek abszolút értékét veszi, és meg is változtatja a tömböt
void tomb_abszolut(int len, int arr[])
{
    for(int i = 0; i < len; i++)
    {
        arr[i] = abs(arr[i]);
    }
}

int main()
{
    int arr[] = {-1, -3, -5, 11, 22};
    int len = 5;

    tomb_kiir(len, arr);
    tomb_abszolut(len, arr);
    tomb_kiir(len, arr);

    return 0;
}