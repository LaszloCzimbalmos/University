#include <stdio.h>
#include "prog1.h"
#include <ctype.h>
#include <string.h>

int eros_jelszo(string text)
{
    int len = strlen(text);
    int nagybetu = 0, kisbetu = 0, szamjegy = 0;

    if (len < 8)
    {
        return 0;
    }

    for (int i = 0; i < len; i++)
    {
        if (islower(text[i]))
        {
            kisbetu = 1;
        }

        if (isupper(text[i]))
        {
            nagybetu = 1;
        }

        if (isdigit(text[i]))
        {
            szamjegy = 1;
        }
    }

    int ertek = kisbetu + nagybetu + szamjegy;

    return ertek == 3 ? 1 : 0;
}

int main()
{
    printf("Adj meg jelszavakat '*' végjelig!\n");
    puts("");

    while (1)
    {
        string jelszo = get_string("jelszó: ");

        if (strcmp(jelszo, "*") == 0)
        {
            break;
        }

        printf(eros_jelszo(jelszo) ? "erős jelszó\n" : "gyenge jelszó\n");
        puts("");
    }

    return 0;
}