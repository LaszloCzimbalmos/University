#include <stdio.h>

void line(char c, int length)
{
    for(int i = 0; i < length; i++)
    {
        printf("%c", c);
    }
    puts("");
}

int main()
{
    printf("hello\n");
    line('-', 50);

    return 0;
}