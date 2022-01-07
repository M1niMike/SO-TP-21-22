//
// Created by mike on 11/3/21.
//

#ifndef SO_BALCAO_H
#define SO_BALCAO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <dirent.h>
#include <fcntl.h>
#include <sys/select.h>

#define FIFO_BAL "fifo_balcao"
#define FIFO_UTE "fifo_cliente%d"

typedef struct {
    int quantidadeMedicos;
    int quantidadeClientes;
    //char* caminho;
} BALCAO;

static const BALCAO balcaoDefault = {
        .quantidadeClientes = 0,
        .quantidadeMedicos = 0,
        //.caminho = NULL
};

typedef struct {
    pid_t pid;
    char nomeUtente[20];
    char cmd[20];
    char flag[99];
    char sintomas[50];
}COMUNICA;

#endif //SO_BALCAO_H
