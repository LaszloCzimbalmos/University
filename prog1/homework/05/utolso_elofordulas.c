#include "prog1.h"
#include <stdio.h>
#include <string.h>

// Egy adott stringben keresi meg az adott karakter utolsó indexét
// -1 -et ad vissza ha nem található a keresett karakter a stringben
int rfind_char(string s, char c)
{
    int length = strlen(s);
    for(int i = length - 1; i >= 0; i--)
    {
        if (s[i] == c)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    string proba1 = "kalap";
    string proba2 = "nincs";

    printf("%d", rfind_char(proba1, 'a'));
    puts("");
    printf("%d", rfind_char(proba1, 'p'));
    puts("");
    printf("%d", rfind_char(proba2, 'x'));
    puts("");
    printf("%d", rfind_char(proba2, 'i'));
    puts("");

    return 0;
}