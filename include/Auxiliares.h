#include "../include/Task.h"

#ifndef AUXILIARES_H
#define AUXILIARES_H

// void parse_string(char *mode, char *input, char ***path_to_programs, char ****args, short *amount_programs, short **amount_args);
int amount_chars(char * string, char c);
Task * parse_string(int pid, char * pipe_flag, char * time, char *argv);
void new_status(char * folder, int task_id, Task_Status estado, long time);
char *remove_quotes(const char *input);

#endif