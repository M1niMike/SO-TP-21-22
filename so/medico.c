//
// Created by mike on 11/3/21.
//

#include "medico.h"


int main()
{

    char nomeMedico[20];
    char especialidade[50];

    printf("\n\n Registe seu nome:\n");
    fgets(nomeMedico, 20, stdin);


//FAZER FUNCIONAR MAIS TARDE (tenta ai gonzo xD)
//    if (strlen(nome) < 3)
//    {
//        printf("\n\n Nome Invalido!");
//        printf("\n\n Necessario ter pelo menos 3 letras no nome, Ex: Ana");
//        printf("\n\n Registe seu nome NOVAMENTE:");
//        fgets(nome, 20, stdin);
//    }

    printf("\n\n Registe sua especialidade:\n");
    fgets(especialidade, 50, stdin);


    printf("\n\n Nome e especialidade guardados\n");
    printf("\n\n Aguarde...\n");

    return 0;

}
