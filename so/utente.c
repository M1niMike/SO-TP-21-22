//
// Created by mike on 11/3/21.
//

#include "utente.h"
#include "util.h"
//#include "comunicacao.h"
#include "balcao.h"
#include <sys/wait.h>

int main(int argc, char **argv)
{
    setbuf(stdout, NULL);
    int fd[2];
    UTENTE *p;

    if (pipe(fd) == -1 ) {
        printf("\nOcorreu um erro com o PIPE!\n");
        exit(EXIT_FAILURE);

    }else{

        int id = fork();
        if (id == 0){
            //close(fd[0]);
            if(argc>= 2)
            {
                p = malloc(sizeof(UTENTE));

                if (p == NULL){
                    printf("Erro a alocar espaco para ponteiro estrutura UTENTE");
                    return 0;
                }
                strcpy(p->nome, argv[1]);
                printf("\n\n Nome do Utente: %s\n", p->nome);


                printf("\n\n Registe seu sintomas:\n");
                fflush(stdout);
                //scanf("%s", p->sintomas);
                //malloc();
                fgets(p->sintomas, 50, stdin);


                printf("\n\n Nome e sintomas registados\n");
                printf("%s", p->sintomas);
                printf("\n\n Aguarde...\n");
            }

            else{
                printf("\n\n Insira seu nome apos './utente'\n");
                return 1;
            }


            if (write(fd[1], p->sintomas, sizeof(UTENTE)) == -1){
                printf("Erro com o Write\n");
                exit(EXIT_FAILURE);
            }
            close(fd[1]);

        }else{
                wait(NULL);

        }

    }



//FAZER FUNCIONAR MAIS TARDE (tenta ai gonzo xD)
//    if (strlen(nome) < 3)
//    {
//        printf("\n\n Nome Invalido!");
//        printf("\n\n Necessario ter pelo menos 3 letras no nome, Ex: Ana");
//        printf("\n\n Registe seu nome NOVAMENTE:");
//        fgets(nome, 20, stdin);
//    }


}
