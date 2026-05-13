#include "head_master.h"
#include "funcoes_uteis.h"
#include "funcoes_sistema.h"

int main () {

    // Para garantir uma nova Seed a cada interação uso o srand:
    srand(time(NULL));

    // Definindo as Matriz:
    ENTIDADE matriz_atual[LINHA][COLUNA]; // OBS: read only
    ENTIDADE matriz_futura[LINHA][COLUNA]; // OBS: Matriz que guarda o futuro
    // Declarando e sorteando a quantidade de obstáculos:
    int qtd_obs = (rand() % FAIXA) + MIN_OBSTACULOS;
    // Declarando variaveis gerais:
    int turnos = 0, rodando = 1;

    // Limpando a matriz:
    limparMatriz(matriz_atual);
    limparMatriz(matriz_futura);
    
    // Gerando as entidades (quantidades para teste):
    gerarEntidades(matriz_atual, OBSTACULO, qtd_obs);
    gerarEntidades(matriz_atual, OVELHA, 45);
    gerarEntidades(matriz_atual, LOBO, 7);
    gerarEntidades(matriz_atual, PASTOR, 2);

    // Exibindo a matriz:
    exibirMatriz(matriz_atual);
    printf("\nQuantidade de Obstáculos: %d\n", qtd_obs);
    // encerrando programa:
    return 0;
}