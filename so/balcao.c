#include <stdio.h>
#include "balcao.h"
#include "util.h"
#include "comunicacao.h"
#include "utente.h"

/*int resposta();


void getBalcaoCorrer(){
     int isBalcaoCorrer = 0; // quando esta a 0 nao esta a correr
}

void read_pipe(UTENTE *p){
    int fd[2];
    // fd[0] - read
    // fd[1] - write

    if (pipe(fd) == -1 ) {
        printf("\nOcorreu um erro com o PIPE!\n");
        exit(EXIT_FAILURE);
    }else{

            int id = fork();

            if (id == 0){
                close(fd[0]);
                if (read(fd[0], p->sintomas, sizeof(UTENTE) == -1))
                {
                    printf("\nOcorreu um erro com a leitura do nome!\n");
                    exit(EXIT_FAILURE);
                }






        }

    }


}*/






int main()
{
    int fd[2];
    UTENTE *p;
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

    close(fd[1]);
    if (read(fd[0], p->sintomas, sizeof(UTENTE)) == -1){
        printf("Erro ocorreu com o PIPE");
        exit(EXIT_FAILURE);
    }
    close(fd[0]);
    printf("%s", p->sintomas);

}
