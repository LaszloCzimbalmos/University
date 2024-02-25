#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void show_version()
{
    printf("Verzioszam: v0.02\n");
    printf("Elkeszules datuma: 2024.04.12.\n");
    printf("Fejleszto neve: Czimbalmos Laszlo\n");
}

void line()
{
    printf("----------------------------------\n");
}

void show_help()
{
    line();
    printf("Uzemmodok (parancssori argumentumkent megadva): \n");
    printf("! Alapertelmezetten a rendszer kuldokent viselkedik !\n\n");
    printf("[-send] - a rendszer kuldokent viselkedik\n");
    printf("[-receive] - a rendszer fogadokent mukodik\n");
    line();

    printf("A kommunikacio modja: \n\n");
    printf("! Alapertelmezetten a kommunikacio modja fajl !\n");
    printf("[-file] - fajlt hasznal kommunikaciora\n");
    printf("[-socket] - socketet hasznal kommunikaciora\n");
    line();
}

int main(int argc, char* argv[])
{
    char* outName = argv[0];
    char* arg = argv[1];

    if (strcmp(outName, "./--version") == 0)
    {
        show_version();
        exit(0);
    }
    if (strcmp(outName, "./--help") == 0)
    {
        show_help();
        exit(0);
    }
    
}