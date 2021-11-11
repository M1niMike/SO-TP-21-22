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



typedef struct{
    char nome[30];
    char sintomas[30];
} UTENTE;

#endif //SO_UTENTE_H
