//
// Created by mike on 11/3/21.
//

#ifndef SO_MEDICO_H
#define SO_MEDICO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>


typedef struct medico medico, *pmedico;

struct medico{
    char nomeMedico[30];
    char especialidade[30];
};



#endif //SO_MEDICO_H
