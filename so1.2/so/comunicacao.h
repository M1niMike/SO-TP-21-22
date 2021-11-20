//
// Created by mike on 11/11/21.
//

#ifndef SO_COMUNICACAO_H
#define SO_COMUNICACAO_H
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

#define FIFO_BAL "Balcao"
#define FIFO_UTE "Utente %d"

typedef struct {
    pid_t pid;
    char nomeUtente[20];
    char cmd[20];
    char flag[99];
    char sintomas[50];
}COMUNICA;


#endif //SO_COMUNICACAO_H
