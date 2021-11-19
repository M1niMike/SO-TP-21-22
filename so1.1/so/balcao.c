#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdio.h>

#include "balcao.h"
#include "util.h"
#include "comunicacao.h"
#include "utente.h"


int lePipes(){

    int FD_BC[2];

    int FD_CB[2];

    char str[50];

    pipe(FD_BC);

    pipe(FD_CB);

    int id = fork();


    if (id > 0){
        close(FD_BC[0]);

        printf("\nIndique os seus sintomas\n");

        fgets(str, 49, stdin);

        write(FD_BC[1], str, 49);

        close(FD_CB[1]);

    }

    else if (id == 0){
        close(STDIN_FILENO);

        dup(FD_BC[0]); // para duplicar o file descriptor, ligando-o ao primeiro fd vazio

        close(FD_BC[0]);

        close(FD_BC[1]);

        close(STDOUT_FILENO);

        dup(FD_CB[1]);
        


        execl("./classificador", "classificador", NULL);




        //close(FD_CB[0]);


        /*read(FD_PF[0], str, 49);

        printf("%s", str)*/
    }
    else{
        printf("Falha na criacao do fork()");

        return 0;
    }

}

    


void varAmb(){
    BALCAO balcao;
    balcao = balcaoDefault;

    if(getenv("MAXCLIENTES")!=NULL)
    {
        balcao.quantidadeClientes = atoi(getenv("MAXCLIENTES"));
    }else{
        fprintf(stderr, "ATENCAO! E NECESSARIO DEFINIR UMA VARIAVEL DE AMBIENTE: MAXCLIENTES!\n");
        exit(EXIT_FAILURE);
    }
    if(getenv("MAXMEDICOS")!=NULL)
    {
        balcao.quantidadeMedicos = atoi(getenv("MAXMEDICOS"));
    }else{
        fprintf(stderr, "ATENCAO! E NECESSARIO DEFINIR UMA VARIAVEL DE AMBIENTE: MAXMEDICOS!\n");
        exit(EXIT_FAILURE);
    }

    printf("MAXMEDICOS: %d \n\n", balcao.quantidadeMedicos);
    printf("MAXCLIENTES: %d \n\n", balcao.quantidadeClientes);

}


int main()
{
    int fd[2];
    UTENTE p;

    varAmb(); 

    lePipes();
    /*pipe(fd);   

    int pid = getpid();

    int id = fork();

    while(1){

    if (id == 0){
        close (fd[0]);
        read(fd[0], &p, sizeof(UTENTE));
    }
    else if (id > 0){
        close(fd[1]);
        write(fd[1], &p, sizeof(UTENTE));

    }
    else{
        printf("\nErro no fork()\n");
        exit(EXIT_FAILURE);
    }

    }*/

}
