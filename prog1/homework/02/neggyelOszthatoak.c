#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Adjon meg egy egesz szamot: ");
    scanf("%d", &n);

    for(int i = 1; i <= n; ++i)
    {
        if (i % 4 == 0)
        {
            printf("%d\n", i);
        }
    }
    return 0;
}
