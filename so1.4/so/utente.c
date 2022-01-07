//
// Created by mike on 11/3/21.
//

#include "utente.h"
#include "balcao.h"
#include <sys/wait.h>


void verifica(){
    if(access(FIFO_BAL, F_OK) == -1){
        printf("Balcao offline\n");
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char **argv)
{
    setbuf(stdout, NULL);
    int fd[2];
    pipe(fd);
    utente p;

    verifica();

    if (pipe(fd) == -1 ) {
        printf("\nOcorreu um erro com o PIPE!\n");
        exit(EXIT_FAILURE);

    }else{
            //close(fd[0]);
            if(argc>= 2)
            {
                /*p = malloc(sizeof(UTENTE));

                if (p == NULL){
                    printf("Erro a alocar espaco para ponteiro estrutura UTENTE");
                    return 0;
                }*/

                strcpy(p.nome, argv[1]);
                printf("\n\n Nome do Utente: %s\n", p.nome);


                printf("\n\n Registe os seus sintomas:\n");
                fflush(stdout);
                fgets(p.sintomas, 50, stdin);
                write(fd[1], p.sintomas, sizeof(utente));

                if (read(fd[0], p.sintomas, sizeof(utente)) == -1){
                    printf("\nO pipe nao conseguiu ler.\n");
                }


                printf("\n\n Nome e sintomas registados\n");

                printf("%s", p.sintomas);

                printf("\n\n Aguarde...\n");
            }

            else{
                printf("\n\n Insira seu nome apos './utente'\n");
                return 1;
            }
        
    }


}
