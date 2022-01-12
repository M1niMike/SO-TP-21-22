//
// Created by mike on 11/3/21.
//

#include "utente.h"
#include "balcao.h"
#include <sys/wait.h>

char Cl[50];
int fifo, fifoUte;
COMUNICA comunica;

void verifica() // verifica fifo balcao para inicializacao do utente
{
    if (access(FIFO_BAL, F_OK) == -1)
    {
        printf("Balcao offline\n");
        exit(EXIT_FAILURE);
    }
}

void clear() // comando limpa
{ 
    system("clear");
}

void sair()
{ // encerra programa e apaga fifo server
    printf("Fim do programa!\n");
    unlink(CFF);
    exit(EXIT_SUCCESS);
}

char *interface(char cmd[50])
{
    printf("Comando: ");
    fflush(stdout);
    scanf("%s", cmd);
    if (strcmp(cmd, "sair") == 0)
    {
        sair();
    }
    else if (strcmp(cmd, "clear") == 0)
    {
        clear();
    }
    else
    {
        printf("\nAviso [Comando invalido!]\n");
    }
    return cmd;
}








int main(int argc, char **argv)
{

    char cmd[50];
    utente p;

    verifica(); // funcao verifica fifo balcao

    
    comunica.pid = getpid();
    printf("Criando FIFO Utente\n");
    sprintf(CFF, FIFO_UTE, comunica.pid);
    if (mkfifo(CFF, 0777) == -1) // criacao fifo utente
    {                            
        if (errno != EEXIST)
        {
            printf("Erro [Criacao - Fifo utente]\n");
            exit(EXIT_FAILURE);
        }
    }
    printf("%s\n", CFF);
    //printf("%d\n", pid_ute);

    fifo = open(FIFO_BAL, O_WRONLY); // abre o fifo balcao
    if (fifo == -1)
    {
        printf("Erro [Abertura - Fifo balcao]\n");
        exit(EXIT_FAILURE);
    }

    if (argc >= 2)
    {
        strcpy(comunica.nomeUtente, argv[1]);
        printf("\n\n Nome do Utente: %s\n", comunica.nomeUtente);

        printf("\n\n Registe os seus sintomas:\n");
        fgets(comunica.sintomas, 50, stdin);

        if (write(fifo, &comunica, sizeof(COMUNICA)) == -1)
        {
            printf("Erro [Write - Fifo Balcao - Sintomas ]\n");
            exit(EXIT_FAILURE);
        }
        close(fifo);

        ///// ABERTURA FIFO CLIENT /////
        fifoUte = open(CFF, O_RDONLY);
        if (fifoUte == -1)
        {
            printf("Erro [Abertura - Fifo Utente]\n");
            exit(EXIT_FAILURE);
        }
        printf("\n\n Nome e sintomas registados\n");
        printf("\n\n Aguarde...\n");
        if (read(fifoUte, Cl, 50) == -1)
        {
            printf("Erro [Read - Fifo Utente - Sintomas ]\n");
            //exit(EXIT_FAILURE);
        }
        printf("recebido: %s\n", Cl);
        close(fifoUte);
    }
    else
    {
        printf("\n\n Insira seu nome apos './utente'\n");
        exit(EXIT_FAILURE);
    }

    while (1)
    {
        interface(cmd);
    }
}
