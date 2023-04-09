#include "prog1.h"
#include <stdio.h>
#include <string.h>

// A match_ends feladat feltételeinek eleget tévő szavakat számolja meg.
int match_ends(int n, string words[])
{
    int count = 0;
    for(int i = 0; i < n; i++)
    {
        int str_hossz = strlen(words[i]);
        char elso_karakter = words[i][0];
        char utolso_karakter = words[i][str_hossz - 1];

        if ((str_hossz >= 2) && (elso_karakter == utolso_karakter))
        {
            count++;
        }
    }

    return count;
}

int main()
{
    string szavak1[] = {"aba", "xyz", "aa", "x", "bbb"};
    string szavak2[] = {"", "x", "xy", "xyx", "xx"};
    string szavak3[] = {"aaa", "be", "abc", "hello"};

    int szavak1_meret = 5;
    int szavak2_meret = 5;
    int szavak3_meret = 4;

    printf("Az adott feltételeknek eleget tévő szavak száma: %d", match_ends(szavak1_meret, szavak1));
    puts("");

    for (int i = 0; i < szavak1_meret; ++i)
    {
        puts(szavak1[i]);
    }

    return 0;
}