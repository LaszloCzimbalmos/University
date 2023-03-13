#include <stdio.h>

//Megállapítja páros-e az adott szám.
int is_even(int n)
{
    return n % 2 == 0;
}

//Megállapítja páratlan-e az adott szám.
int is_odd(int n)
{
    return n % 2 == 1;
}

//Megállapítja páratlan-e az adott szám, az is_even() fv. segítségével.
int is_odd2(int n)
{
    return !(is_even(n));
}

int main()
{
    int n;
    printf("Tesztelési érték: ");
    scanf("%d", &n);
    puts("");

    printf("Páros-e: %d\n", is_even(n));
    printf("Páratlan-e: %d\n", is_odd(n));
    printf("Páratlan-e: %d\n", is_odd2(n));

    return 0;
}