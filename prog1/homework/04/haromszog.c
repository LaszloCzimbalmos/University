#include <stdio.h>

//megállapítja, hogy megszerkeszthető-e a háromszög.
//a visszatérési értek 0 ha nem, 1 ha megszerkeszthető.
int valid_triangle(double a, double b, double c)
{
    if ((a > 0) && (b > 0) && (c > 0))
    {
        if ((a + b <= c) || (a + c <= b) || (b + c <= a)){
            return 0;
        }
        else{
            return 1;
        }
    }
    else{
        return -1;
    }
}

int main()
{
    double a, b, c;
    printf("Adja meg a háromszög \"a\" oldalát: ");
    scanf("%lf", &a);

    printf("Adja meg a háromszög \"b\" oldalát: ");
    scanf("%lf", &b);

    printf("Adja meg a háromszög \"c\" oldalát: ");
    scanf("%lf", &c);


    double result = valid_triangle(a, b, c);

    if (result < 0){
        printf("\nA megadott oldalak között csak pozitív, valós számok lehetnek.\n");
    }
    else{
        printf(result == 1 ? "A háromszög megszerkeszthető.\n" : "A háromszög NEM szerkeszthető meg.\n");
    }

    return 0;
}