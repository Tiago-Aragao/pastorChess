#include "head_master.h"

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