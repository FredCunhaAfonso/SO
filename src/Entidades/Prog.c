#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "../../include/Entidades/Prog.h"

Prog * create_Prog(char * path_to_program, short amount_args, char ** args){
    Prog * x = malloc(sizeof(Prog));

    if (x == NULL) {
        perror("Não deu para alocar memória ... cringe");
        exit(EXIT_FAILURE);
    }

    x->path_to_program = strdup(path_to_program);
    x->amount_args = amount_args;

    x->args = malloc(sizeof(char *) * amount_args);

    for(int i = 0; i < amount_args; i++)
    x->args[i] = strdup(args[i]);

    return x;
}
void execute_Prog(Prog * x , char * outputpath){

    pid_t pid = fork();
    int status;

    if(pid == -1)
    {
        perror("O garfo não garfou");
        exit(EXIT_FAILURE);
    }
    
    else if(pid == 0)
    {
                          // Ola fred mudei isto um coto... acho que n tirei nada....
        int file = open (outputpath , O_WRONLY) ;
        dup2 (file , 1) ; // eu nao sei como e que depois de usar isto desfaco os efeitos
                          // e nao sei o que e que isto afeta mas supostamente o output
                          // do que executamos tera de ir para um ficheiro (paco disse txt btw)
                          //suponho que se tenha de fazer uma condicao para quando for com varios
                          //comandos seguidos porque ai acho que nao deve ir para um file mas
                          // sim para um pipe dos nao named

                          //ass(:) Chandre

                          // (.) (.)
                          //    -
    

        execvp(x->path_to_program, x->args) ;
    }

    else
    waitpid(pid, &status, 0) ;

}


void destroy_Prog(Prog * x){
    free(x->path_to_program);
    for(int i = 0; i<x->amount_args; i++)
    free(x->args[i]);
    free(x->args);
    free(x);
}