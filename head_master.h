#ifndef HEAD_MASTER_H
#define HEAD_MASTER_H

// Includes básicos:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Definição de valores no sistema:
#define COLUNA 20
#define LINHA 20
#define MIN_OBSTACULOS 40
#define MAX_OBSTACULOS 60
#define FAIXA (MAX_OBSTACULOS - MIN_OBSTACULOS) + 1

// Definindo o meu tipo:
typedef enum {
    VAZIO = 0,
    OBSTACULO,
    PASTOR,
    OVELHA,
    LOBO
} TIPO_ENTIDADE;

// Struct que define minhas entidades:
typedef struct {
    TIPO_ENTIDADE tipo;
    int vel_movimento;
} ENTIDADE;

// Definindo a Matriz:
ENTIDADE matriz_atual[LINHA][COLUNA]; // OBS: read only
ENTIDADE matriz_futura[LINHA][COLUNA]; // OBS: Matriz que guarda o futuro
#endif