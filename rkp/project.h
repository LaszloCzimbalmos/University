#ifndef PROJECT_H_
#define PROJECT_H_

int origin(int *operation_mode, int *communication_mode, int argc, char *argv[]);
void show_version();

int Measurement(int **Values);
int elapsed_seconds();
int get_array_size();
int get_state();

void BMPcreator(int *Values, int NumValues);

void ReceiveViaSocket();

void ReceiveViaFile();

void SendViaSocket(int *Values, int NumValues);

void SendViaFile(int *Values, int NumValues);

int FindPID();

void SignalHandler(int sig);

#endif // PPROJECT_H_