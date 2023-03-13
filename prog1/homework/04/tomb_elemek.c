#include <stdio.h>

//Vesszővel és szóközzel elválasztva írja ki az adott tömb elemeit.
//Az utolsó elem után csak sortörés szerepel.
void kiir_vesszovel(int len, int arr[])
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

int main()
{
    int len = 5;
    int arr[] = {1, 2, 3, 4, 5};

    kiir_vesszovel(len, arr);

    return 0;
}