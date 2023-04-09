#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int n, also, felso;
    printf("Hány darab random számot kérsz?\n");
    scanf("%d", &n);

    printf("Alsó határ: ");
    scanf("%d", &also);

    printf("Felső határ (zárt intervallum): ");
    scanf("%d", &felso);

    puts("");
    srand(time(0));
    printf("A generált számok: ");

    for (int i = 0; i < n; i++)
    {
        int num = (rand() % (felso - also) + 1) + also; // az also hatrtol mennyivel mehet feljebb
        printf("%d ", num);
    }

    return 0;
}