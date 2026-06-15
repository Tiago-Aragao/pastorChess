#include "head_master.h"
#include "funcoes_uteis.h"
#include "cores.h"

// Prototipos encapsulados das funções:
// Essas funções se tornam visiveis apenas neste .c:
static COORDENADA direcaoMovimento(int linha_atual, int coluna_atual, const ENTIDADE matriz[LINHA][COLUNA]);
static int moverLobo(int l, int c, const ENTIDADE matriz[LINHA][COLUNA], ENTIDADE matriz_futura[LINHA][COLUNA]);
static int moverOvelha(int l, int c, const ENTIDADE matriz[LINHA][COLUNA], ENTIDADE matriz_futura[LINHA][COLUNA]);
static int moverVazio(int l, int c, const ENTIDADE matriz[LINHA][COLUNA], ENTIDADE matriz_futura[LINHA][COLUNA]);

// Função direcaoMovimento:
COORDENADA direcaoMovimento(int linha_atual, int coluna_atual, const ENTIDADE matriz[LINHA][COLUNA]) { // Inicio direcaoMovimento.
    /*
    Está função define uma direção (NORTE, SUL, LESTE e OESTE) aleatoriamente.
    OBS: Estou passando como parametro a matriz para que futuramente está função sirva de escopo para a IA básica
    da movimentação do sistema.
    */
    // Struct:
    COORDENADA destino;
    // Sorteio de 0 á 3:
    int sorteio = rand() % 4;
    // Crio os arryas da direção que a Entidade vai seguir:
    int direcao_linha[] = {1,-1,0,0};
    int direcao_coluna[] = {0,0,1,-1};
    // Atribuo a direção a struct destino:
    destino.l = linha_atual + direcao_linha[sorteio];
    destino.c = coluna_atual + direcao_coluna[sorteio];
    // Retorno o resultado do movimento:
    return destino;
} // fim direcaoMovimento.

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
    
    // "Limpo a tela" antes de cada rodada:
    sobrescreverTela();
    
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
}

// Mover Ovelha:
int moverOvelha (int l, int c, const ENTIDADE matriz[LINHA][COLUNA], ENTIDADE matriz_futura[LINHA][COLUNA]) { // Inicio moverOvelha.
    /*
    Está função move a ovelha checando se o espaço futuro está vazio.
    Por enquanto o movimento é aleatorio e sem nenhuma inteligencia ou lógica por parte da ovelha, apenas aplicando fisica e regra de negocio.
    */
    // Declaro as variaveis que vou precisar usar:
    int andou = 1, tentativas = 0;
    // Identidade da criatura que está jogando o turno:
    TIPO_ENTIDADE presa = matriz[l][c].tipo;

    // inicio o Loop necessario:
    while (andou == 1 && tentativas < 4) {
        // Agora pego a coordenada com a minha função que define o movimento:
        COORDENADA direcao = direcaoMovimento(l,c,matriz);
        // Checo se o movimento é valido:
        if (direcao.l >= 0 && direcao.l <= LINHA-1 && direcao.c >= 0 && direcao.c <= COLUNA-1) { // Se for valido.

            // Trago a checagem da direção para dentro dessa variavel para ser mais legivel para mim:
            int esta_vazio = (matriz[direcao.l][direcao.c].tipo == VAZIO && matriz_futura[direcao.l][direcao.c].tipo == VAZIO);

            // Agora checo se o local está valido para a ovelha se movimentar:
            if (esta_vazio) {
                // Saio da casa atual:
                matriz_futura[l][c].tipo = VAZIO;
                matriz_futura[direcao.l][direcao.c].tipo = presa;
                andou = 0;
            }
        }
        tentativas++;
    }
    return 0;
} // Fim moverOvelha.

// Mover Lobo e Comer Ovelha:
int moverLobo (int l, int c, const ENTIDADE matriz[LINHA][COLUNA], ENTIDADE matriz_futura[LINHA][COLUNA]) { // Inicio moverLobo.
    /*
    Está função move o lobo checando se o espaço futuro está vazio ou tem ovelha.
    Por enquanto o movimento é aleatorio e sem nenhuma inteligencia ou lógica por parte do lobo, apenas aplicando fisica e regra de negocio.
    */
    // Declaro as variaveis que vou precisar usar:
    int andou = 1, tentativas = 0, pontos=0;

    // Identidade da criatura que está jogando o turno
    TIPO_ENTIDADE cacador = matriz[l][c].tipo;

    // inicio o Loop necessario:
    while (andou == 1 && tentativas < 4) {
        // Agora pego a coordenada com a minha função que define o movimento:
        COORDENADA direcao = direcaoMovimento(l,c,matriz);
        // Checo se o movimento é valido:
        if (direcao.l >= 0 && direcao.l <= LINHA-1 && direcao.c >= 0 && direcao.c <= COLUNA-1) { // Se for valido.

            // Trago a checagem da direção para dentro dessa variavel para ser mais legivel para mim:
            int esta_vazio = (matriz[direcao.l][direcao.c].tipo == VAZIO && matriz_futura[direcao.l][direcao.c].tipo == VAZIO);
            int tem_ovelha = (matriz[direcao.l][direcao.c].tipo == OVELHA && matriz_futura[direcao.l][direcao.c].tipo == OVELHA);
            // Agora checo se o local está valido para a ovelha se movimentar:
            if (esta_vazio || tem_ovelha) {
                // Caso tenha ovelha lobo ganha ponto:
                if (tem_ovelha) pontos++;
                // Saio da casa atual:
                matriz_futura[l][c].tipo = VAZIO;
                matriz_futura[direcao.l][direcao.c].tipo = cacador;
                andou = 0;
            }
        }
        tentativas++;
    }
    return pontos;
} // fim moverLobo.

// Função apenas para constar na funcao movimento:
int moverVazio (int l, int c, const ENTIDADE matriz[LINHA][COLUNA], ENTIDADE matriz_futura[LINHA][COLUNA]) {
    /* Função apenas para saltar as posições de Obstaculo e Vazio no meu array de funções. */
    return 0; // retornando nada 0.
} // fim moverVazio.

// Array de funções:
static const funcao_movimento tabelaComportamentos[] = {
    [VAZIO]     = moverVazio,
    [OBSTACULO] = moverVazio,
    [PASTOR]    = moverLobo, // Pastor usa a mesma inteligência do lobo por enquanto.
    [OVELHA]    = moverOvelha,
    [LOBO]      = moverLobo
};

//
int processarTurno(TIPO_ENTIDADE qual_entidade, const ENTIDADE matriz[LINHA][COLUNA], ENTIDADE matriz_futura[LINHA][COLUNA]) {
    int pontos_turno = 0;
    // Loop para ler a matriz (padrão):
    for (int i = 0; i < LINHA; i++) {
        for (int j = 0; j < COLUNA; j++) {
            // Quando ele encontra o personagem do turno atual:
            if (matriz[i][j].tipo == qual_entidade) {
                // AQUI OS PARÂMETROS SÃO PREENCHIDOS!
                // O motor passa o 'i' e o 'j' do momento do loop para a função da tabela
                pontos_turno += tabelaComportamentos[qual_entidade](i, j, matriz, matriz_futura);
            }
        }
    }
    return pontos_turno;
}

/*
// Mover Pastor e Salvar Ovelha:
int moverPastor (const ENTIDADE matriz[LINHA][COLUNA], ENTIDADE matriz_futura[LINHA][COLUNA]) { // Inicio moverPastor.
    Está função move o pastor para um espaço Vazio ou um espaço com Ovelha, retornando uma pontuação caso a o espaço seja OVELHA.
    Por enquanto o movimento é aleatorio e sem nenhuma inteligencia ou lógica por parte do Pastor, apenas aplicando fisica e regra de negocio.
    OBS: Por enquanto está função não está implementada. Como o pastor se comporta exatamente como o Lobo, usaremos o moverLobo para o pastor no MPV do projeto.

    return 0; 
}
*/