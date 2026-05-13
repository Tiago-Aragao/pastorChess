#include "head_master.h"

// Limpar tela:
void limparTela() {
    /*
    Função que identifica qual sistema operacional é e limpa a tela.
    */
    #ifdef _WIN32 // Para windows.
        system("cls");
    #else // Para Linux.
        system("clear");
    #endif
}