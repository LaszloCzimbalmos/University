#include <stdio.h>

int main()
{
    int h;
    printf("Magasság: ");
    scanf("%d", &h);

    if (h % 2 == 1 && h > 0)
    {
        //teteje
        int lines = (h / 2) + 1;
        int spaces = (h / 2) -1;
        int stars = 1;
        for(int i = 1; i <= lines; i++)
        {
            for(int k = 0; k <= spaces; k++)
            {
                printf(" ");
            }

            for(int j = 1; j <= stars; j++)
            {
                printf("*");
            }

            stars += 2;
            spaces--;
            printf("\n");      
        }

        //alja
        stars = h - 2;
        lines = h / 2;
        spaces = 1;
        for(int i = 1; i <= lines; i++)
        {
            for(int k = 1; k <= spaces; k++)
            {
                printf(" ");
            }
            spaces++;

            for(int j = 1; j <= stars; j++)
            {
                printf("*");
            }
            stars -= 2;

            printf("\n");
        }

    }
    else{
        printf("A megadott érték nem megfelelő. Páratlan számot adjon meg.\n");
    }



    return 0;
}