#include "project.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <signal.h>
#include <dirent.h>
#include <ctype.h>
#include<omp.h>


int main(int argc, char *argv[]) {
    srand(time(NULL));

    if (strcmp(argv[0], "./chart") != 0) {
        fprintf(stderr, "Nem chart a program neve!\n");
        return EXIT_FAILURE;
    }

    int *values = NULL;
    int size;

    int operation_mode = 0;     
    int communication_mode = 0; 

    origin(&operation_mode, &communication_mode, argc, argv);

    signal(SIGINT, SignalHandler);
    signal(SIGUSR1, SignalHandler);

    if (operation_mode < 0 || communication_mode < 0) {
        return EXIT_FAILURE;
    }

    if (operation_mode == 0 && communication_mode == 0) {
        size = Measurement(&values);
        printf("Tömb kreáció...\n");
        SendViaFile(values, size);
        printf("Fájl átment\n");
        free(values);
        exit(0);
    } else if (operation_mode == 0 && communication_mode == 1) { 
        size = Measurement(&values);
        printf("Tömb kreáció...\n");
        SendViaSocket(values, size);
        free(values);
        exit(0);
    } else if (operation_mode == 1 && communication_mode == 0) { 
        while (1) {
            signal(SIGUSR1, SignalHandler);
            ReceiveViaFile(signal(SIGUSR1, SignalHandler));
            ReceiveViaFile();
            pause();
        }
    } else if (operation_mode == 1 && communication_mode == 1) { 
        ReceiveViaSocket();
    }

    return EXIT_SUCCESS;
}

