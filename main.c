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

    while(1){
        // Exibindo a matriz:
        exibirMatriz(matriz_atual);
        printf("Matriz atual -- TURNOS: %d \n", turnos);
        
        // pauso meio segundo para dar tempo de ver a movimentação
        Sleep(500); 
        // Copiando a matriz_atual para a matriz_futura:
        memcpy(matriz_futura, matriz_atual, sizeof(matriz_atual));
        // movendo a ovelha:
        moverOvelha(matriz_atual, matriz_futura);
        // Copiando a matriz_futura para a matriz_atual:
        memcpy(matriz_atual, matriz_futura, sizeof(matriz_futura));

        turnos++;
    }
    
    return 0;
}