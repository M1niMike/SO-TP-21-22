//
// Created by mike on 11/3/21.
//

#include "utente.h"

int main(int argc, char **argv)
{


    char nome[20];
    char sintoma[50];
    if(argc>= 2)
    {
        printf("\n\n Nome do Utente: %s\n", argv[1]);

        printf("\n\n Registe seu sintomas:\n");
        fgets(sintoma, 50, stdin);


        printf("\n\n Nome e sintomas registados\n");
        printf("\n\n Aguarde...\n");
    }

    else
    {
        printf("\n\n Insira seu nome apos './utente'\n");
        return 1;
    }
    //argv == nome;

//FAZER FUNCIONAR MAIS TARDE (tenta ai gonzo xD)
//    if (strlen(nome) < 3)
//    {
//        printf("\n\n Nome Invalido!");
//        printf("\n\n Necessario ter pelo menos 3 letras no nome, Ex: Ana");
//        printf("\n\n Registe seu nome NOVAMENTE:");
//        fgets(nome, 20, stdin);
//    }


}

