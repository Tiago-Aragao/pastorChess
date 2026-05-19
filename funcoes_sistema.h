#ifndef FUNCOES_SISTEMA_H
#define FUNCOES_SISTEMA_H

// Head_master:
#include "head_master.h"

// Protótipos das funções:

// Geração de Mapa:
void limparMatriz(ENTIDADE matriz[LINHA][COLUNA]);
void gerarEntidades (ENTIDADE matriz[LINHA][COLUNA], TIPO_ENTIDADE ent, int quant_ent);
// Exibição de informações:
void exibirMatriz (ENTIDADE matriz[LINHA][COLUNA]);
// Lógica de movimentação:
void moverOvelha(const ENTIDADE matriz[LINHA][COLUNA], ENTIDADE matriz_futura[LINHA][COLUNA]);
int moverLobo (const ENTIDADE matriz[LINHA][COLUNA], ENTIDADE matriz_futura[LINHA][COLUNA]);
#endif