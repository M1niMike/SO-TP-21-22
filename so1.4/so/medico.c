//
// Created by mike on 11/3/21.
//

#include "medico.h"
#include "balcao.h"


void verifica(){
    if(access(FIFO_BAL, F_OK) == -1){
        printf("Balcao offline\n");
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char **argv)
{

    char nomeMedico[20];
    char especialidade[50];

    verifica();

    ///// Inserir nome e especialidade por argumentos ////
    if(argc>=3)
    {
        //for(counter=0;counter<argc;counter++)
        printf("\n\n Nome do Medico: %s\n", argv[1]);
        printf("\n\n Especialidade do Medico: %s\n", argv[2]);

        printf("\n\n Nome e Especialidade registados\n");
        printf("\n\n Aguarde...\n");

        return 0;
    }

    else
    {
        printf("\n\n Insira seu nome e especialidade apos './medico'\n");
        return 1;
    }

}
