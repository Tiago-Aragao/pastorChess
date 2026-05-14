#ifndef FUNCOES_SISTEMA_H
#define FUNCOES_SISTEMA_H

// Head_master:
#include "head_master.h"

// Protótipos das funções:
void limparMatriz(ENTIDADE matriz[LINHA][COLUNA]);
void gerarEntidades (ENTIDADE matriz[LINHA][COLUNA], TIPO_ENTIDADE ent, int quant_ent);
void exibirMatriz (ENTIDADE matriz[LINHA][COLUNA]);
void moverOvelha(const ENTIDADE matriz[LINHA][COLUNA], ENTIDADE matriz_futura[LINHA][COLUNA]);
#endif