#include "project.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <ctype.h>
#include <sys/socket.h>
#include <signal.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include<omp.h>

void show_version()
{
    int thread_id = omp_get_thread_num();
    int num_threads = omp_get_num_threads();

    if (thread_id == 0) {
        printf("Czimbalmos László - F1NGN6\n");
    } else if (thread_id == 1) {
        printf("Verzio: v01.6\n");
    } else if (thread_id == 2) {
        printf("2024.05.03.\n");
    }
}


// 1.
int origin(int *operation_mode, int *communication, int argc, char *argv[]) {
    const char *possible_switches[] = {"--version", "--help", "-send", "-receive", "-file", "-socket"};
    size_t num_switches = sizeof(possible_switches) / sizeof(possible_switches[0]);

    int valid_switches = 0;
    if (argc > 1) {
        for (int i = 1; i < argc; i++) {
            int found = 0;
            for (size_t j = 0; j < num_switches; j++) {
                if (strcmp(possible_switches[j], argv[i]) == 0) {
                    found = 1;
                    valid_switches++;
                    break;
                }
            }
            if (!found) {
                *operation_mode = -1;
                *communication = -1;
            }
        }

        if (valid_switches != argc - 1) {
            printf("--version : Program verziója\n");
            printf("--help : Használható commandok\n");
            printf("-send : Küldő üzem\n");
            printf("-receive : Fogadó üzem\n");
            printf("-file : Fájlon keresztül kommunikál\n");
            printf("-socket : Socketen keresztül kommunikál\n");

            *operation_mode = -1;
            *communication = -1;
        }

        for (int i = 1; i < argc; i++) {
            if (strcmp(argv[i], "--version") == 0) {

                #pragma omp parallel num_threads(3)
                {
                    show_version();
                }

                *operation_mode = -1;
                *communication = -1;
            } else if (strcmp(argv[i], "--help") == 0) {
            printf("--version : Program verziója\n");
            printf("--help : Használható commandok\n");
            printf("-send : Küldő üzem\n");
            printf("-receive : Fogadó üzem\n");
            printf("-file : Fájlon keresztül kommunikál\n");
            printf("-socket : Socketen keresztül kommunikál\n");

                *operation_mode = -1;
                *communication = -1;
            } else if (strcmp(argv[i], "-send") == 0) {
                *operation_mode = 0;
            } else if (strcmp(argv[i], "-receive") == 0) {
                *operation_mode = 1;
            } else if (strcmp(argv[i], "-socket") == 0) {
                *communication = 1;
            } else if (strcmp(argv[i], "-file") == 0) {
                *communication = 0;
            }
        }
    } else {
        return EXIT_FAILURE;
    }

    return 0;
}
//2.
int elapsed_seconds() {
    // Az aktuális idő lekérése
    time_t current_time;
    struct tm * time_info;
    int elapsed_seconds;
    
    time(&current_time);
    time_info = localtime(&current_time);

    elapsed_seconds = time_info->tm_sec + 60 * time_info->tm_min + 3600 * time_info->tm_hour;
    elapsed_seconds %= 900; // Negyedóra: 15 perc * 60 mp = 900 mp
    
    return elapsed_seconds;
}

int get_array_size()
{
    int elps = elapsed_seconds();
    if (elps < 100)
    {
        return 100;
    }
    else{
        return elps;
    }
}

int get_state()
{
    double rand_num = (double)rand() / RAND_MAX;

    if (rand_num < 0.428571) 
    {
        return 1;
    } 
    else if (rand_num < 0.428571 + 11.0/31.0) 
    {
        return 2;
    } 
    else 
    {
        return 3;
    }
}

//meresekhez
int Measurement(int **Values)
{
    int array_size = get_array_size();
    *Values = (int*)malloc(array_size * sizeof(int));

    (*Values)[0] = 0;
    for (int i = 0; i < array_size - 1; i++)
    {
        int state = get_state(); // 1/2/3 a megadott eselyek szerint
        {
            if (state == 1)
            {
                (*Values)[i + 1] = (*Values)[i] + 1;
            }
            else if (state == 2)
            {
                (*Values)[i + 1] = (*Values)[i] - 1;
            }
            else
            {
                (*Values)[i + 1] = (*Values)[i];
            }
        }
    }
    return array_size;
}

// 3.
void BMPcreator(int *Values, int NumValues)
{
    unsigned long int size = 62UL + (unsigned long int)(NumValues * NumValues);
    unsigned int padding = 0;

    int f = open("chart.bmp", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IROTH);
    unsigned char **arr = malloc(NumValues * sizeof(*arr));

    unsigned char head[] = {
        0x42,0x4d,0x00,0x00,0x00,0x00,0x3e,0x00,0x00,0x00,
        0x28,0x00,0x00,0x00,0x01,0x00,0x01,0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,0x00,0x61,0x0f,0x00,0x00,
        0x61,0x0f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,
        0xaa,
        0xaa,
        0xfa,
        0x00,
        0x10,
        0xcc,
        0xcc,
    };

    for (int i = 0; i < NumValues; ++i)
    {
        arr[i] = (unsigned char*)calloc(NumValues, sizeof(unsigned char));
    }

    int ccount; //columns

    for (int i = 0; i < NumValues; ++i) {
    int ccount = (NumValues >> 1) + Values[i]; // /2 error miatt
                                             //col koezepetol kell 

    if (ccount > NumValues) { //ne legyen neg vagy nagyobb
        ccount = NumValues - 1;
    } else if (ccount < -(NumValues >> 1)) {
        ccount = 0;
    }
    
    arr[ccount][i] = 0x01; // col közepe
}

    write(f, head, sizeof(unsigned char) * 2);
    write(f, &size, sizeof(int));
    write(f, &head[2], sizeof(unsigned char) * 12);
    write(f, &NumValues, sizeof(int));
    write(f, &NumValues, sizeof(int));
    write(f, &head[14], sizeof(unsigned char) * 36);

    for (int i = 0; i < NumValues; ++i)
    {
        int x = 7;

        for (int j = 0; j < NumValues; ++j)
        {
            if (arr[i][j] == 0x01) {
                padding += (1 << x);
            }

            switch (x) {
                case 24:  //padding ne legyen tobb
                    write(f, &padding, sizeof(int));
                    padding = 0;
                    x = 7;
                    continue;
                default:
                    break;
            }

            if ((x & 7) == 0) {  // %8
                x = (j % 32) + 9;  // körbe 9-31ig
            }

            --x;
        }

        write(f, &padding, sizeof(int));
        padding = 0;
    }

    free(arr);
}

// 4.
int FindPID() {
    DIR *dir1;
    DIR *dir2;
    struct dirent *entry1;
    struct dirent *entry2;
    FILE *file;

    char line[100];
    const char *chart_name = "Name:\tchart\n"; //ez a process neve
    const char *pid_prefix = "Pid:";

    int is_chart = 0;
    char pid_str[4];

    dir1 = opendir("/proc");
    if (dir1 == NULL) {
        return -1;
    }

    while ((entry1 = readdir(dir1)) != NULL) {
        if (isdigit(entry1->d_name[0])) { //ha szam az eleje akkor statust jelol
            char *new_path = malloc(strlen(entry1->d_name) + 6);
            sprintf(new_path, "/proc/%s", entry1->d_name);

            dir2 = opendir(new_path);
            if (dir2 == NULL) {
                free(new_path);
                continue;
            }

            while ((entry2 = readdir(dir2)) != NULL) {
                if (strcmp(entry2->d_name, "status") == 0) {
                    char *status_path = malloc(strlen(new_path) + 8);
                    sprintf(status_path, "%s/status", new_path);

                    file = fopen(status_path, "r"); //ha nullt ad vissza skippeli az id keresest
                    if (file == NULL) {
                        free(new_path);
                        free(status_path);
                        closedir(dir2);
                        continue;
                    }

                    is_chart = 0;  //keresi a chart process ID-t
                    while (fgets(line, sizeof(line), file) != NULL) {
                        if (strcmp(line, chart_name) == 0) {
                            is_chart = 1;
                        }

                        if (strncmp(line, pid_prefix, 4) == 0 && is_chart) { 
                            strncpy(pid_str, line + 5, 4);
                            pid_str[4] = '\0';
                            fclose(file);
                            free(new_path);
                            free(status_path);
                            closedir(dir2);
                            closedir(dir1);
                            return atoi(pid_str);  //int kent adja vissza a pidet
                        }
                    }

                    fclose(file);
                    free(status_path);
                }
            }

            free(new_path);
            closedir(dir2);
        }
    }

    closedir(dir1);
    return -1;
}


// 5.
void ReceiveViaFile(int sig) {
    printf("Fájl fogadás\n");

    char *home_dir = getenv("HOME");
    char filepath[strlen(home_dir) + strlen("/Measurement.txt") + 1];  // home-ba krealja a filet
    sprintf(filepath, "%s/Measurement.txt", home_dir);

    FILE *file = fopen(filepath, "r");
    if (file == NULL) {
        printf("Hiba a fájl megnyitásakor\n");
        return;
    }

    int *result = NULL;
    int count = 0;
    char line[100];
    while (fgets(line, sizeof(line), file) != NULL) {
        int value = atoi(line);                                 //kiszedi az ertekeket line by line intté alakitva
        result = realloc(result, (count + 1) * sizeof(int));
        result[count++] = value;
    }

    fclose(file);

    printf("BMP létrehozása\n");
    BMPcreator(result, count);
    printf("Létrehozás kész\n");

    free(result);
}

void SendViaFile(int *values, int numValues) {
    char *fileName = "Measurement.txt";
    char *filePath = NULL;
    FILE *file = NULL;

    size_t pathLen = strlen(getenv("HOME")) + strlen(fileName) + 2; //null term miatt +2
    filePath = (char *)malloc(pathLen * sizeof(char));
    sprintf(filePath, "%s/%s", getenv("HOME"), fileName);
    

    file = fopen(filePath, "w");
    if (file == NULL) {
        fprintf(stderr, "Hiba a fájl megnyitásakor: %s\n", filePath);
        free(filePath);
        return;
    }


    for (int i = 0; i < numValues; i++) {
        fprintf(file, "%d\n", values[i]);
    }


    fclose(file);
    free(filePath);

    pid_t pid = FindPID(); //fut e fogado prog?
    if (pid == -1) {
        fprintf(stderr, "Nincs fogadó program indítva..\n");
    } else {
        kill(pid, SIGUSR1);  //ha fut küldi a szignált
    }
}

// 6.
void SendViaSocket(int *Values, int NumValues)
{
    int s;
    int bytes;
    int flag;
    char on;
    unsigned int server_size;
    struct sockaddr_in server;
    int valasz;

    /************************ Initialization ********************/
    on = 1;
    flag = 0;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_port = htons(3333);
    server_size = sizeof server;

    /************************ Creating socket *******************/
    s = socket(AF_INET, SOCK_DGRAM, 0);
    if (s < 0)
    {
        fprintf(stderr, "Socket létrehozási hiba...\n");
        exit(2);
    }
    setsockopt(s, SOL_SOCKET, SO_REUSEADDR, &on, sizeof on);
    setsockopt(s, SOL_SOCKET, SO_KEEPALIVE, &on, sizeof on);

    /************************ Sending array size **********************/
    bytes = sendto(s, &NumValues, sizeof(int), flag, (struct sockaddr *)&server, server_size);
    puts("Tömb méret küldés");
    if (bytes <= 0)
    {
        fprintf(stderr, "Küldési hiba...\n");
        exit(3);
    }

    //modositas
    signal(SIGALRM, SignalHandler);
    sleep(2);
    signal(SIGALRM, SIG_IGN);

    /************************ Receive allocation size **********************/
    bytes = recvfrom(s, &valasz, sizeof(int), flag, (struct sockaddr *)&server, &server_size);
    puts("Allokációs méret fogadás");
    if (bytes < 0)
    {
        fprintf(stderr, "Fogadási hiba...\n");
        exit(3);
    }

    /************************ Size test **********************/
    if (NumValues != valasz)
    {
        fprintf(stderr, "Méret hiba...\n");
        exit(4);
    }
    puts("Fogadási és küldési méret megegyezik");

    /************************ Sending array data **********************/
    bytes = sendto(s, Values, (NumValues * sizeof(int)), flag, (struct sockaddr *)&server, server_size);
    if (bytes <= 0)
    {
        fprintf(stderr, "Küldési hiba...\n");
        exit(5);
    }
    puts("Tömb adat küldés");

    /************************ Receive send bytes size! **********************/
    int s_bytes = recvfrom(s, &valasz, sizeof(int), flag, (struct sockaddr *)&server, &server_size);
    if (bytes <= 0)
    {
        fprintf(stderr, "Hibás méret...\n");
        exit(7);
    }
    if (valasz != bytes)
    {
        fprintf(stderr, "Méret hiba...\n");
        exit(5);
    }
    puts("Fogadott és küldött byte-ok száma megeggyezik");

    close(s);
}

void ReceiveViaSocket()
{
    int bytes;
    int err;
    int flag;
    char on;
    unsigned int server_size;
    unsigned int client_size;
    struct sockaddr_in server;
    struct sockaddr_in client;
    int valasz;

    /************************ Initialization ********************/
    on = 1;
    flag = 0;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(3333);
    server_size = sizeof server;
    client_size = sizeof client;
    // signal(SIGINT, stop);
    // signal(SIGTERM, stop);

    /************************ Creating socket *******************/
    int s = socket(AF_INET, SOCK_DGRAM, 0);
    if (s < 0)
    {
        fprintf(stderr, "Socket létrehozási hiba...\n");
        exit(2);
    }
    setsockopt(s, SOL_SOCKET, SO_REUSEADDR, &on, sizeof on);
    setsockopt(s, SOL_SOCKET, SO_KEEPALIVE, &on, sizeof on);

    /************************ Binding socket ********************/
    err = bind(s, (struct sockaddr *)&server, server_size);
    if (err < 0)
    {
        fprintf(stderr, "Összeköttetési hiba...\n");
        exit(3);
    }

    while (1)
    {
        puts("Várakozás az adatra\n");

        /************************ Receive array size! **********************/
        bytes = recvfrom(s, &valasz, sizeof(int), flag, (struct sockaddr *)&client, &client_size);
        if (bytes < 0)
        {
            fprintf(stderr, "Fogadási hiba...\n");
            exit(4);
        }

        /************************ Array allocation **********************/
        int *ERTEKEK = malloc(valasz * sizeof(int));
        puts("Tömb allokáció kész");

        /************************ Send array allocation size **********************/
        bytes = sendto(s, &valasz, sizeof(int), flag, (struct sockaddr *)&client, client_size);
        puts("Tömb allokációs méret küldése");
        if (bytes <= 0)
        {
            fprintf(stderr, "Küldési hiba...\n");
            exit(4);
        }

        /************************ Receive array data **********************/
        bytes = recvfrom(s, ERTEKEK, valasz * sizeof(int), flag, (struct sockaddr *)&client, &client_size);
        puts("Tömb adat fogadása");
        if (bytes < 0)
        {
            fprintf(stderr, "Fogadási hiba...\n");
            exit(4);
        }

        /************************ Send receive data bytes **********************/
        bytes = sendto(s, &bytes, sizeof(int), flag, (struct sockaddr *)&client, client_size);
        puts("Fogadott byte-ok méretének küldése");
        if (bytes < 0)
        {
            fprintf(stderr, "Küldési hiba...\n");
            exit(11);
        }

        /************************ Create BMP file **********************/
        printf("BMP létrehozása\n");
        BMPcreator(ERTEKEK, valasz);
        printf("kész");
        puts("");

        free(ERTEKEK);
    }

    close(s);
}

// 7.
void SignalHandler(int sig) {
    switch (sig) {
        case SIGUSR1:
            printf("A Fájlküldés nem működik...\n");
            break;
        case SIGINT:
            printf("Viszlát!\n");
            exit(0);
        case SIGALRM:
            printf("időtúllépés..\n");
            exit(5);
        default:
            break;
    }
}