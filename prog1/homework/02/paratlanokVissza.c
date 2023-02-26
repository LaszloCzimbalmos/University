#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Adjon meg egy egesz szamot: ");
    scanf("%d", &n);

    for(int i = n; i >= 1; --i)
    {
        if (i % 2 == 1)
        {
            printf("%d\n", i);
        }
    }
    return 0;
}
