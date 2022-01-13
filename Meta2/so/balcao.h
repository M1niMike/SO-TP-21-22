//
// Created by mike on 11/3/21.
//

#ifndef SO_BALCAO_H
#define SO_BALCAO_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <dirent.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/select.h>

#define STRING 100


#define FIFO_BAL "fifo_balcao"
#define FIFO_UTE "fifo_cliente%d"
#define FIFO_MED "fifo_medico%d"
char CFF[100], MFF[100];


typedef struct comunica comunica, *pcomunica;
typedef struct utente utente, *putente;
typedef struct medico medico, *pmedico;
typedef struct server server, *pserver;

struct comunica{
    int fd; 
    int pid;
    char nomeUtente[STRING];
    char sintomasUtente[STRING];
    char nomeMedico[STRING];
    char especialidadeMedico[STRING];
    char Classificador[STRING];
    int prioridadeUtente;
    char msg[STRING];
};




struct utente{
    int pid;
    char nome[STRING];
    char sintomas[STRING];
    char especialidade[STRING];
    char classificacao[STRING];
    int prioridade;
    pmedico medico;
    putente prox;
};


struct medico{
    int pid;
    char nomeMedico[STRING];
    char especialidade[STRING];
    putente utente;
    pmedico prox;
};


struct server{
    int quantidadeMedicos;
    int quantidadeClientes;
    putente utente;
    pmedico medico;
};



#endif //SO_BALCAO_H
