#include "head_master.h"
#include "funcoes_uteis.h"
#include "funcoes_sistema.h"

int main () {

    // Para garantir uma nova Seed a cada interação uso o srand:
    srand(time(NULL));
    // Chamo a configuração do Terminal:
    configurarTerminal();

    // Definindo as Matriz:
    ENTIDADE matriz_atual[LINHA][COLUNA]; // OBS: read only
    ENTIDADE matriz_futura[LINHA][COLUNA]; // OBS: Matriz que guarda o futuro
    // Declarando e sorteando a quantidade de obstáculos:
    int qtd_obs = (rand() % FAIXA) + MIN_OBSTACULOS;
    // Declarando variaveis gerais:
    int rodadas = 0, rodando = 1, pontuacao_lobos = 0, pontuacao_pastores = 0;

    // Limpando a matriz:
    limparMatriz(matriz_atual);
    limparMatriz(matriz_futura);
    
    // Gerando as entidades (quantidades para teste):
    gerarEntidades(matriz_atual, OBSTACULO, qtd_obs);
    gerarEntidades(matriz_atual, OVELHA, 45);
    gerarEntidades(matriz_atual, LOBO, 2);
    gerarEntidades(matriz_atual, PASTOR, 2);

    while(1){
        // Exibindo a matriz:
        exibirMatriz(matriz_atual);
        printf("-------------------------------------\n");
        printf("Matriz atual -- TURNOS: %d \n", rodadas);
        printf("Numero de Obstaculos: %d \n", qtd_obs);
        printf("-------------------------------------\n");
        printf("               PONTUACAO\n");
        printf("-------------------------------------\n");
        printf("PASTORES: %d\n", pontuacao_pastores);
        printf("LOBOS: %d\n", pontuacao_lobos);
        // Pausa para dar um sweet move para os membros da matriz:
        Sleep(250);
        
        //TURNO 1: OVELHA
        // Copio a matriz atual para a futura:
        memcpy(matriz_futura, matriz_atual, sizeof(matriz_atual));
        // Movo a ovelha:
        moverOvelha(matriz_atual, matriz_futura);
        // Atualizo a matriz atual com as infos da matriz futura:
        memcpy(matriz_atual, matriz_futura, sizeof(matriz_futura));

        //TURNO 2: LOBOS
        // Copio a matriz atual para a futura:
        memcpy(matriz_futura, matriz_atual, sizeof(matriz_atual));
        // Movo o lobo:
        pontuacao_lobos += moverLobo(matriz_atual, matriz_futura);
        // Atualizo a matriz atual com as infos da matriz futura:
        memcpy(matriz_atual, matriz_futura, sizeof(matriz_futura));

        //TURNO 3: PASTOR
        // Copio a matriz atual para a futura:
        memcpy(matriz_futura, matriz_atual, sizeof(matriz_atual));
        // Movo o pastor:
        pontuacao_pastores += moverPastor(matriz_atual, matriz_futura);
        // Atualizo a matriz atual com as infos da matriz futura:
        memcpy(matriz_atual, matriz_futura, sizeof(matriz_futura));

        rodadas++;
    }
    
    return 0;
}