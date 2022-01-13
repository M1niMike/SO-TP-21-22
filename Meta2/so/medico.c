//
// Created by mike on 11/3/21.
//

#include "medico.h"
#include "balcao.h"

COMUNICA comunica;
medico medic;


void verifica(){
    if(access(FIFO_BAL, F_OK) == -1){
        printf("Balcao offline\n");
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char **argv)
{


    verifica();

    ///// Inserir nome e especialidade por argumentos ////
    if(argc>=3)
    {
        strcpy(medic.nomeMedico, argv[1]);
        strcpy(medic.especialidade, argv[2]);
        printf("\n\n Nome do Medico: %s\n", medic.nomeMedico);
        printf("\n\n Especialidade do Medico: %s\n", medic.especialidade);

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
