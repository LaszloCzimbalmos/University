#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n1, n2;

    printf("Adjon meg 2 egesz szamot vesszovel elvalasztva: ");
    scanf("%d,%d", &n1, &n2);

    if (n1 == n2)
    {
        printf("=");
    }
    else if (n1 < n2)
    {
        printf("<");
    }
    else
    {
        printf(">");
    }


    return 0;
}
