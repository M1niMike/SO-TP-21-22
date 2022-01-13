//
// Created by mike on 11/3/21.
//

#include "medico.h"

int fd_balcao, fd_utente, fd_medico;

pcomunica c;
pmedico m;

void verifica()
{
    if (access(FIFO_BAL, F_OK) == -1)
    {
        printf("Balcao offline\n");
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char **argv)
{
    m=malloc(sizeof(struct medico));
    if(m == NULL)
    {
        fprintf(stderr, "\nErro [Alocacao Memoria - medico]\n");
        free(m);
        return 0;
    }

    c=malloc(sizeof(struct comunica));
    if(c == NULL)
    {
        fprintf(stderr, "\nErro [Alocacao Memoria - comunica]\n");
        free(c);
        return 0;
    }
    verifica();

    c->pid = getpid();
    printf("Criando FIFO Medico\n");
    sprintf(MFF, FIFO_MED, c->pid);
    if (mkfifo(MFF, 0777) == -1)
    { // criacao fifo balcao
        if (errno != EEXIST)
        {
            printf("Erro [Criacao - Fifo balcao]\n");
            exit(EXIT_FAILURE);
        }
    }

    

    fd_balcao = open(FIFO_BAL, O_RDWR | O_NONBLOCK);
    if(fd_balcao == -1)
    {
        printf("Erro [Abertura - Fifo balcao]\n");
        unlink(MFF);
        exit(EXIT_FAILURE);
    }

    ///// Inserir nome e especialidade por argumentos ////
    if (argc >= 3)
    {
        strcpy(m->nomeMedico, argv[1]);
        strcpy(m->especialidade, argv[2]);
        printf("\n\n Nome do Medico: %s\n", m->nomeMedico);
        printf("\n\n Especialidade do Medico: %s\n", m->especialidade);

        //strcpy(c->pid, m->pid);
        strcpy(c->nomeMedico, m->nomeMedico);
        strcpy(c->especialidadeMedico, m->especialidade);

        if (write(fd_balcao, c, sizeof(comunica)) == -1)
        {
            printf("Erro [Write - Fifo Balcao - Sintomas]\n");
            unlink(MFF);
            exit(EXIT_FAILURE);
        }

        printf("\n\n Nome e Especialidade registados\n");
        printf("\n\n Aguarde...\n");

        fd_medico = open(MFF, O_RDONLY);
        if (fd_medico == -1)
        {
            printf("Erro [Abertura - Fifo Utente]\n");
            unlink(MFF);
            exit(EXIT_FAILURE);
        }
        if (read(fd_medico, c, sizeof(comunica)) == -1)
        {
            printf("Erro [Read - Fifo Utente - Sintomas]\n");
            //exit(EXIT_FAILURE);
        }
        printf("nome do utente: %s\n", c->nomeUtente);
        printf("sintomas do utente: %s\n", c->sintomasUtente);
        printf("recebido do Balcao: %s\n", c->Classificador);


        return 0;

    }

    else
    {
        printf("\n\n Insira seu nome e especialidade apos './medico'\n");
        return 1;
    }
}
