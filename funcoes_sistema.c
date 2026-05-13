#include "head_master.h"
#include "funcoes_uteis.h"
#include "cores.h"

// Função para limpar a matriz antes de trabalhar:
void limparMatriz(ENTIDADE matriz[LINHA][COLUNA]){
    
    /*
    Aqui eu vou limpar a minha matriz que está cheia de lixo de memória, dessa forma "preenchendo"
    ela de espaços vazios.
    */
    
    // Aqui declaro e inicializo as entidades que estarão na limpeza da matriz:
    ENTIDADE limpo = {.tipo = VAZIO, .vel_movimento = 0};
    //Inicializo o loop que irá percorrer a matriz:
    for (int i=0;i<LINHA;i++){
        for(int j=0;j<COLUNA;j++){
            matriz[i][j] = limpo;
        }
    }
}

// Gerar Entidades (Pastor, Lobo, Ovelha e Obstáculo):
void gerarEntidades (ENTIDADE matriz[LINHA][COLUNA], TIPO_ENTIDADE ent, int quant_ent) {

    /*
    Está função gera as entidades para popular a matriz por metodo de sorteio de casas.
    Entidades a serem geradas:
    >>> Pastor
    >>> Lobo
    >>> Ovelha
    >>> Obstáculo
    */

    // Declaro e inicializo quantos obstaculos tem atualmente:
    int cont_ent = 0;
    // Declaro as variaveis que guardaram as colunas e linhas sorteadas:
    int linha_sorteada, coluna_sorteada;
    
    // Inicio o loop para sortear e adicionar os obstaculos na matriz:
    while (quant_ent > cont_ent) { // Inicio do loop.
        // Aqui implemento a lógica de sorteio de casas da minha matriz:
        // Futuramente também será adaptado para o tamanho da matriz
        linha_sorteada = rand() % LINHA;
        coluna_sorteada = rand() % COLUNA;
        
        // Aqui olho se o espaço já não tem um obstaculo:
        if (matriz[linha_sorteada][coluna_sorteada].tipo == VAZIO) { // Se ele não tiver eu posso adicionar.
            matriz[linha_sorteada][coluna_sorteada].tipo = ent;
            cont_ent++; // incremento o contador
        }
    } // Fim do Loop.
}

void exibirMatriz (ENTIDADE matriz[LINHA][COLUNA]) {
    
    // Limpo a tela antes de cada rodada:
    limparTela();

    // Separador:
    printf("---------------------------\n");
    
    for (int i = 0; i < LINHA; i++) {
        for (int j = 0; j < COLUNA; j++) {
            
            // O switch avalia o qual o tipo e pinta a letra correspondente:
            switch (matriz[i][j].tipo) {
                case VAZIO:
                    // Um ponto verde para representar a grama:
                    printf(VERDE ". " RESET); 
                    break;
                case OBSTACULO:
                    // Uma cerquilha cinza para os obstáculos:
                    printf(CINZA "# " RESET); 
                    break;
                    // Branco para ovvelhas:
                case OVELHA:
                    printf(BRANCO "O " RESET);
                    break;
                    // Vermelho para os lobos:
                case LOBO:
                    printf(VERMELHO "L " RESET);
                    break;
                    // Azul para os pastores:
                case PASTOR:
                    printf(AZUL "P " RESET);
                    break;
            }
        }
        printf("\n"); // Quebra a linha toda vez que terminar de imprimir as colunas
    }
    
    printf("---------------------------\n");
}