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

// Mover Ovelha:
void moverOvelha (const ENTIDADE matriz[LINHA][COLUNA], ENTIDADE matriz_futura[LINHA][COLUNA]) { // Inicio moverOvelha.

    /*
    Está função move a ovelha checando se o espaço futuro está vazio.
    Por enquanto o movimento é aleatorio e sem nenhuma inteligencia ou lógica por parte da ovelha, apenas aplicando fisica e regra de negocio.
    */

    // Declaração dos arrays que terão as posições cardeais (NORTE, SUL, LESTE, OESTE):
    int direcao_linha[] = {1,-1,0,0};
    int direcao_coluna[] = {0,0,1,-1};

    // Inicio o for que irá varrer a matriz procurando ovelhas para mover:
    for (int i=0;i<LINHA;i++) { // Inicio forI.
        for (int j=0;j<COLUNA;j++) { // Inicio forJ.
            if (matriz[i][j].tipo == OVELHA) { // Inicio IF.
                // Aqui é a variavel que confirma se ela andou e a variavel de controle de tentativas:
                int andou=1, tentativas = 0; // 
                while (andou && tentativas < 4) { // Inicio While.
                    // Sorteio em qual direção ela vai andar:
                    int sorteio = rand() % 4;
                    // FAço o calculo para saber a nova direção:
                    int novaL = i +  direcao_linha[sorteio]; // Somo a posição atual da linha com o valor sorteado.
                    int novaC = j + direcao_coluna[sorteio]; // Somo a posição atual da coluna com o valor sorteado.
                    // Aqui eu inicio a checagem se ela não sai do mapa ou não tem obstaculo:
                    if (novaL >= 0 && novaL <= LINHA-1 && novaC >= 0 && novaC <= COLUNA-1) { // Se não sair, inicio a logica.
                        // Aqui eu tento simplificar a minha leitura passando a checagem de vazio para a variavel que será atribuida como 0 ou 1.
                        int esta_vazio = (matriz[novaL][novaC].tipo == VAZIO && matriz_futura[novaL][novaC].tipo == VAZIO);
                        // Checo se o espaço está vazio (de forma mais clean Laele):
                        if (esta_vazio) { // Se estiver vazio.
                            matriz_futura[i][j].tipo = VAZIO;
                            // Depois atualizo a direção sorteada com a OVELHA:
                            matriz_futura[novaL][novaC].tipo = OVELHA;
                            // Aqui atualizo para sair do while:
                            andou = 0;
                        } // Fim if
                    } // Fim if.
                    tentativas++;
                } // Fim While.
            } // Fim if.
        } // Fim forJ.
    } // Fim forI.
} // Fim moverOvelha.

// Mover Lobo e Comer Ovelha:
int moverLobo (const ENTIDADE matriz[LINHA][COLUNA], ENTIDADE matriz_futura[LINHA][COLUNA]) { // Inicio moverLobo.
    
    /*
    Está função move o lobo para um espaço Vazio ou um espaço com Ovelha, retornando uma pontuação caso a o espaço seja OVELHA.
    Por enquanto o movimento é aleatorio e sem nenhuma inteligencia ou lógica por parte do Lobo, apenas aplicando fisica e regra de negocio.
    */

    // Declaração dos arrays que terão as posições cardeais (NORTE, SUL, LESTE, OESTE):
    int direcao_linha[] = {1,-1,0,0};
    int direcao_coluna[] = {0,0,1,-1};
    // Aqui será meu contador de pontos que o Lobo gerou:
    int pontos=0;
    // Inicio o for que irá varrer a matriz procurando Lobos para mover:
    for (int i=0;i<LINHA;i++) { // Inicio forI.
        for (int j=0;j<COLUNA;j++) { // Inicio forJ.
            if (matriz[i][j].tipo == LOBO) { // Inicio IF.
                // Aqui é a variavel que confirma se ela andou e a variavel de controle de tentativas:
                int andou=1, tentativas = 0;
                while (andou && tentativas < 4) { // Inicio While.
                    // Sorteio em qual direção ela vai andar:
                    int sorteio = rand() % 4;
                    // FAço o calculo para saber a nova direção:
                    int novaL = i +  direcao_linha[sorteio]; // Somo a posição atual da linha com o valor sorteado.
                    int novaC = j + direcao_coluna[sorteio]; // Somo a posição atual da coluna com o valor sorteado.
                    // Aqui eu inicio a checagem se o Lobo não sai do mapa ou não tem obstaculo:
                    if (novaL >= 0 && novaL <= LINHA-1 && novaC >= 0 && novaC <= COLUNA-1) { // Testo primeiro se o Lobo não vai sair do mapa.
                        // Aqui eu tento simplificar a minha leitura passando as logicas que seriam dentro do if para variaveis que serão retornadas em 0 e 1:
                        int esta_vazio = (matriz[novaL][novaC].tipo == VAZIO && matriz_futura[novaL][novaC].tipo == VAZIO);
                        int tem_ovelha = (matriz[novaL][novaC].tipo == OVELHA && matriz_futura[novaL][novaC].tipo == OVELHA);
                        // Depois checo se o espaço é uma OVELHA ou VAZIO:
                        if (esta_vazio || tem_ovelha) { // Se tiver faço a lógica seguir.
                            // Aqui caso tenha uma Ovelha:
                            if (tem_ovelha) pontos++; // Aumento a pontuação.
                            // Agora faço a movimentação do lobo normalmente:
                            // Coloco a posição atual como VAZIO:
                            matriz_futura[i][j].tipo = VAZIO;
                            // Depois atualizo a direção sorteada com a OVELHA:
                            matriz_futura[novaL][novaC].tipo = LOBO;
                            // Aqui atualizo para sair do while:
                            andou = 0;
                        } // Fim if.
                    } // Fim if.
                    tentativas++;
                } // Fim While.
            } // Fim if.
        } // Fim forJ.
    } // Fim forI.
    // Retorno a pontuação que o lobo fez nessa rodada.
    return pontos;
} // Fim moverLobo.