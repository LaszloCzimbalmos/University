#include "prog1.h"
#include <stdio.h>
#include <string.h>

// Egy adott stringben megszámolja a megadott karakter előfordulásainak számát.
int char_count(string s, char c)
{
    int ossz = 0, length = strlen(s);
    for(int i = 0; i < length; i++)
    {
        if (s[i] == c)
        {
            ossz++;
        }
    }

    return ossz;
}

int main()
{
    string s = "alaposan";

    printf("A(z) %s szóban a \"%c\" karakter előfordulási száma: %d", s, 'e', char_count(s, 'e'));
    puts("");
    printf("A(z) %s szóban a \"%c\" karakter előfordulási száma: %d", s, 'a', char_count(s, 'a'));
    puts("");
    printf("A(z) %s szóban a \"%c\" karakter előfordulási száma: %d", s, 'p', char_count(s, 'p'));
    puts("");

    return 0;
}