cmake_minimum_required(VERSION 3.20)
project(so C)

set(CMAKE_C_STANDARD 99)

add_executable(so balcao.c balcao.h classifica.c classifica.h utente.c utente.h medico.c medico.h util.h)
