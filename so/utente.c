//
// Created by mike on 11/3/21.
//

#include "utente.h"

int main()
{

    char nome[20];
    char sintoma[50];

    printf("\n\n Registe seu nome:\n");
    fgets(nome, 20, stdin);


//FAZER FUNCIONAR MAIS TARDE (tenta ai gonzo xD)
//    if (strlen(nome) < 3)
//    {
//        printf("\n\n Nome Invalido!");
//        printf("\n\n Necessario ter pelo menos 3 letras no nome, Ex: Ana");
//        printf("\n\n Registe seu nome NOVAMENTE:");
//        fgets(nome, 20, stdin);
//    }

    printf("\n\n Registe seu sintomas:\n");
    fgets(sintoma, 50, stdin);


    printf("\n\n Nome e sintomas registados\n");
    printf("\n\n Aguarde...\n");

    return 0;

}