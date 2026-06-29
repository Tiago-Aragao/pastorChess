#include "head_master.h"

// Limpar tela:
void sobrescreverTela() {
    // Move o cursor para a posição [0;0] do terminal, sem apagar o que já está lá.
    // O próximo printf vai sobrescrever o texto existente resolvendo as piscadelas:
    printf("\033[H");
}

void limparTela () {
    /*
    Função que identifica qual sistema operacional é e limpa a tela.
    */
    #ifdef _WIN32 // Para windows.
        system("cls");
    #else // Para Linux.
        system("clear");
    #endif
}

void configurarTerminal() {
    /*
    Está função configura o terminal para ele ler e entender melhor o codigo ANSI.
    */
    // Pego a "ferramenta" (Handle) que controla a tela do Windows:
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut == INVALID_HANDLE_VALUE) return; // Tratamento de erro.

    // Faço ler como o terminal está configurado atualmente:
    DWORD dwMode = 0;
    if (!GetConsoleMode(hOut, &dwMode)) return; // Tratamento de erro.

    // Injeto a flag que obriga o Windows a entender os códigos ANSI (Cores e Cursor):
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    
    // Aqui eu salvo a nova configuração no sistema:
    SetConsoleMode(hOut, dwMode);
}