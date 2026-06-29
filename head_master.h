#ifndef HEAD_MASTER_H
#define HEAD_MASTER_H

// Includes básicos:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

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

// Struct para definir minha direção que será retornada no definirDirecao:
typedef struct {
    int l; // LINHA
    int c; // COLUNA
} COORDENADA;

// Crio um ponteiro de função chamado funcao_movimento:
typedef int (*funcao_movimento)(int l, int c, int linhas, int colunas, ENTIDADE **matriz, ENTIDADE **matriz_futura);
#endif