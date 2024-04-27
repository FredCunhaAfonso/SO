#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
//#include "defs.h"

#include "../../include/Entidades/Task.h"
#include "../../include/Entidades/Prog.h"
#include "../../include/Entidades/Auxiliares.h"
#include "../../include/Entidades/Client.h"

//short amount_programs, char ** path_to_programs, short * amount_args, char *** args

int client (int argc, char* argv[]){

    // printf("%d\n", argc);
    // for(int i = 0; i < argc; i++) {
    //     printf("%s\n", argv[i]);
    // }

 	if (argc < 2 || 5 < argc || (argc != 2 && argc != 5)){
		printf("Missing argument.\n");
		_exit(1);
	}

    switch(argc) {
        case 2:
            if (strcmp(argv[1],"status") == 0) {
                //printf("recibi status\n");


                
            }
            else perror("Não foi possivel interrogar os programas, dado que o argumento número 1 recebido não foi: status\n");
            break;
        case 5:
            if (strcmp(argv[1],"execute") == 0) {
                //printf("recibi execute\n");
                if (strcmp(argv[3],"-u") == 0 || strcmp(argv[3],"-p") == 0) {
                    //printf("Es -u\n");

                    short amount_programs;
                    short* amount_args;
                    char** path_to_programs;
                    char*** args;

                    parse_string(argv[3], argv[4], &path_to_programs, &args, &amount_programs, &amount_args);
                    // printf("listo\n");
                    // printf("%s\n", path_to_programs[0]);
                    // printf("%d\n", amount_args[0]);

                    Task *newTask = create_Task(0, amount_programs, path_to_programs, amount_args, args, argv[2]);
                    printf("listo\n");
                    printf("%s\n", newTask->programs[0]->path_to_program);

                    



                }
                else perror("Não foi possivel interrogar os programas, dado que o argumento número 3 recebido não foi: -u / -p\n");
                    
            }
            else perror("Não foi possivel interrogar os programas, dado que o argumento número 1 recebido não foi: execute\n");
            break;
    }

    return 0;


}