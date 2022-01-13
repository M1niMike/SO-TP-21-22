//
// Created by mike on 11/3/21.
//

#include "utente.h"


int fd_balcao, fd_utente;

pcomunica c;
putente u;

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
    close(fd_utente);
    close(fd_balcao);
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
    else if (strcmp(cmd, "classificador") == 0)
    {
        
    }
    else
    {
        printf("\nAviso [Comando invalido!]\n");
    }
    return cmd;
}

int main(int argc, char **argv)
{

    setbuf(stdout,NULL);
    c=malloc(sizeof(struct comunica));
    if(c == NULL)
    {
        fprintf(stderr, "\nErro Alocacao memoria - Comunica - VarAmb\n");
        free(c);
        return 0;
    }

    u=malloc(sizeof(struct utente));
    if(u == NULL)
    {
        fprintf(stderr, "\nErro Alocacao memoria - utente \n");
        free(u);
        return 0;
    }

    char cmd[50];

    verifica(); // funcao verifica fifo balcao

    c->pid = getpid();
    printf("Criando FIFO Utente\n");
    sprintf(CFF, FIFO_UTE, c->pid);
    if (mkfifo(CFF, 0777) == -1) // criacao fifo utente
    {
        if (errno != EEXIST)
        {
            printf("Erro [Criacao - Fifo utente]\n");
            //unlink(CFF);
            exit(EXIT_FAILURE);
        }
    }

    fd_balcao = open(FIFO_BAL, O_RDWR | O_NONBLOCK); // abre o fifo balcao
    if (fd_balcao == -1)
    {
        printf("Erro [Abertura - Fifo balcao]\n");
        unlink(CFF);
        exit(EXIT_FAILURE);
    }

    if (argc >= 2)
    {
        strcpy(u->nome, argv[1]);
        printf("\n\n Nome do Utente: %s\n", u->nome);

        printf("\n\n Registe os seus sintomas:\n");
        fgets(u->sintomas, 50, stdin);

        strcpy(c->nomeUtente, u->nome);
        strcpy(c->sintomasUtente, u->sintomas);
        

        if (write(fd_balcao, c, sizeof(comunica)) == -1)
        {
            printf("Erro [Write - Fifo Balcao - Sintomas]\n");
            unlink(CFF);
            exit(EXIT_FAILURE);
        }

        ///// ABERTURA FIFO CLIENT /////

        printf("\n\n Nome e sintomas registados\n");
        printf("\n\n Aguarde...\n");
        fd_utente = open(CFF, O_RDONLY);
        if (fd_utente == -1)
        {
            printf("Erro [Abertura - Fifo Utente]\n");
            unlink(CFF);
            exit(EXIT_FAILURE);
        }
        if (read(fd_utente, c, sizeof(comunica)) == -1)
        {
            printf("Erro [Read - Fifo Utente - Sintomas]\n");
            //exit(EXIT_FAILURE);
        }
        printf("recebido do Balcao: %s\n", c->Classificador);
        printf("nome medico: %s\n", c->nomeMedico);


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
