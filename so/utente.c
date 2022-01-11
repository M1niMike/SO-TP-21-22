//
// Created by mike on 11/3/21.
//

#include "utente.h"
#include "balcao.h"
#include <sys/wait.h>

char Cl[50];
int fifo, fifoUte;

void verifica() // verifica fifo balcao para inicializacao do utente
{
    if (access(FIFO_BAL, F_OK) == -1)
    {
        printf("Balcao offline\n");
        exit(EXIT_FAILURE);
    }
}

void criaFifo()
{
    printf("Criando FIFO Utente\n");
    if (mkfifo(FIFO_UTE, 0777) == -1)
    { // criacao fifo balcao
        if (errno != EEXIST)
        {
            printf("Erro [Criacao - Fifo utente]\n");
            exit(EXIT_FAILURE);
        }
    }
}

void clear()
{ // comando limpa
    system("clear");
}

void sair()
{ // encerra programa e apaga fifo server
    printf("Fim do programa!\n");
    unlink(FIFO_UTE);
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
    //int fifo, fifoUte;
    utente p;

    verifica(); // funcao verifica fifo balcao
    

    fifo = open(FIFO_BAL, O_WRONLY); // abre o fifo

    if (fifo == -1)
    {
        printf("Erro [Abertura - Fifo balcao]\n");
        exit(EXIT_FAILURE);
    }

    if (argc >= 2)
    {

        strcpy(p.nome, argv[1]);
        printf("\n\n Nome do Utente: %s\n", p.nome);

        printf("\n\n Registe os seus sintomas:\n");
        fgets(p.sintomas, 50, stdin);

        if (write(fifo, p.sintomas, 50) == -1)
        {
            printf("Erro [Write - Fifo Balcao - Sintomas ]\n");
            exit(EXIT_FAILURE);
        }

        close(fifo);

        criaFifo(); // cria fifo client

        printf("\n\n Nome e sintomas registados\n");

        printf("\n\n Aguarde...\n");

        fifoUte = open(FIFO_UTE, O_RDONLY);

        if (fifoUte == -1)
        {
            printf("Erro [Abertura - Fifo Utente]\n");
            exit(EXIT_FAILURE);
        }

        if(read(fifoUte, Cl, 50) == -1)
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
