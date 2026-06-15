#include "head_master.h"
#include "funcoes_uteis.h"
#include "funcoes_sistema.h"

int main () {

    // Para garantir uma nova Seed a cada interação uso o srand:
    srand(time(NULL));
    // Configurando o terminal para ANSI:
    configurarTerminal();

    // Definindo as Matriz:
    // Agora eu inicializo elas já limpas em vez de rodar um laço for para limpar as matrizes.
    ENTIDADE matriz_atual[LINHA][COLUNA] = {0}; // OBS: read only
    ENTIDADE matriz_futura[LINHA][COLUNA] = {0}; // OBS: Matriz que guarda o futuro
    // Declarando e sorteando a quantidade de obstáculos:
    int qtd_obs = (rand() % FAIXA) + MIN_OBSTACULOS;
    // Declarando variaveis gerais:
    int rodadas = 0, rodando = 1, pontuacao_lobos = 0, pontuacao_pastores = 0;

    // Inicialmente no MVP remove a necessidade de ter um laço for apenas para limpar as matrizes:
    // Limpando a matriz:
    // limparMatriz(matriz_atual);
    // limparMatriz(matriz_futura);
    
    // Gerando as entidades (quantidades para teste):
    gerarEntidades(matriz_atual, OBSTACULO, qtd_obs);
    gerarEntidades(matriz_atual, OVELHA, 50);
    gerarEntidades(matriz_atual, LOBO, 5);
    gerarEntidades(matriz_atual, PASTOR, 5);

    // Limpo o terminal antes de iniciar o loop:
    system("cls");
    
    while(1){
        // Exibindo a matriz:
        exibirMatriz(matriz_atual);
        printf("-------------------------------------\n");
        printf("Matriz atual -- RODADAS: %d \n", rodadas);
        printf("Numero de Obstaculos: %d \n", qtd_obs);
        printf("-------------------------------------\n");
        printf("               PONTUACAO\n");
        printf("-------------------------------------\n");
        printf("PASTORES: %d\n", pontuacao_pastores);
        printf("LOBOS: %d\n", pontuacao_lobos);

        // Pausa para dar um sweet move para os membros da matriz:
        Sleep(200);
            
        //TURNO 1: OVELHA
        // Copio a matriz atual para a futura:
        memcpy(matriz_futura, matriz_atual, sizeof(matriz_atual));
        // Disparo o motor para processar todas as ovelhas:
        processarTurno(OVELHA, matriz_atual, matriz_futura);
        // Atualizo a matriz atual com as infos da matriz futura:
        memcpy(matriz_atual, matriz_futura, sizeof(matriz_futura));

        //TURNO 2: LOBOS
        memcpy(matriz_futura, matriz_atual, sizeof(matriz_atual));
        // Disparo o motor para processar todos os lobos e guardo os pontos:
        pontuacao_lobos += processarTurno(LOBO, matriz_atual, matriz_futura);
        memcpy(matriz_atual, matriz_futura, sizeof(matriz_futura));

        //TURNO 3: PASTOR
        memcpy(matriz_futura, matriz_atual, sizeof(matriz_atual));
        // Disparo o motor para o pastor. 
        // A Tabela vai automaticamente rodar a lógica do lobo para ele!
        pontuacao_pastores += processarTurno(PASTOR, matriz_atual, matriz_futura);
        memcpy(matriz_atual, matriz_futura, sizeof(matriz_futura));

        rodadas++;
    }
    
    return 0;
}