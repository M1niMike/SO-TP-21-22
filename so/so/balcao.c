#include <stdio.h>
#include "balcao.h"
#include "util.h"
#include "comunicacao.h"

int resposta()


void getBalcaoCorrer(){
    isBalcaoCorrer = 0; // quando esta a 0 nao esta a correr
}

void read_pipe(UTENTE *p){
    int fd[2];

    pipe(fd);

    int id = fork();

    if (id == 0){
        close(fd[0]);
        if(read(fd[0]), p->sintomas, sizeof(UTENTE) == -1){
            printf("\nOcorreu um erro com a leitura do nome!\n");
            return -1;
        }
        else{
            return 0;
        }


    }

}

void getEnvVar()
{
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
