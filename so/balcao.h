//
// Created by mike on 11/3/21.
//

#ifndef SO_BALCAO_H
#define SO_BALCAO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>


typedef struct {
    int quantidadeMedicos;
    int quantidadeClientes;
    char* caminho;
} BALCAO;

static const BALCAO balcaoDefault = {
        .quantidadeClientes = 0,
        .quantidadeMedicos = 0,
        .caminho = NULL
};


#endif //SO_BALCAO_H
