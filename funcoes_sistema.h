#ifndef FUNCOES_SISTEMA_H
#define FUNCOES_SISTEMA_H
#include "head_master.h"

// Protótipos das funções adaptados para Alocação Dinâmica na Heap:

// Geração de Mapa:
void limparMatriz(ENTIDADE **matriz, int linhas, int colunas);
void gerarEntidades(ENTIDADE **matriz, int linhas, int colunas, TIPO_ENTIDADE ent, int quant_ent);

// Exibição de informações:
void exibirMatriz(ENTIDADE **matriz, int linhas, int colunas);

// Processamento do turno:
int processarTurno(TIPO_ENTIDADE qual_entidade, int linhas, int colunas, ENTIDADE **matriz, ENTIDADE **matriz_futura); 

#endif