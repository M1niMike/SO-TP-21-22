//
// Created by mike on 11/3/21.
//

#ifndef SO_UTENTE_H
#define SO_UTENTE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>



typedef struct utente utente, *putente;

struct utente{
    char nome[35];
    char sintomas[50];
    char envia_para_class[50];
    char recebe_class[50];
};

#endif //SO_UTENTE_H
