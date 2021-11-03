#include <stdio.h>
#include "balcao.h"
#include "util.h"

int main()
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
