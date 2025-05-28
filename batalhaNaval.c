
// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.


    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0
#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

void inicializaTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for(int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for(int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

int verificaLimites(int linha, int coluna, int tamanho, char orientacao) {
    if(orientacao == 'H') {
        if(coluna + tamanho > TAMANHO_TABULEIRO) return 0;
    } else if(orientacao == 'V') {
        if(linha + tamanho > TAMANHO_TABULEIRO) return 0;
    } else {
        return 0;
    }
    return 1;
}

int verificaSobreposicao(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int tamanho, char orientacao) {
    for(int i = 0; i < tamanho; i++) {
        int l = linha + (orientacao == 'V' ? i : 0);
        int c = coluna + (orientacao == 'H' ? i : 0);
        if(tabuleiro[l][c] != 0) {
            return 1;
        }
    }
    return 0;
}

void posicionaNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int tamanho, char orientacao) {
    for(int i = 0; i < tamanho; i++) {
        int l = linha + (orientacao == 'V' ? i : 0);
        int c = coluna + (orientacao == 'H' ? i : 0);
        tabuleiro[l][c] = 3;
    }
}

void exibeTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    // Cabeçalho colunas A até J
    printf("   ");
    for(char c = 'A'; c < 'A' + TAMANHO_TABULEIRO; c++) {
        printf(" %c ", c);
    }
    printf("\n");

    // Exibir linhas 1 a 10
    for(int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%2d ", i + 1);
        for(int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf(" %d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    inicializaTabuleiro(tabuleiro);

    // Coordenadas iniciais dos navios (base zero)
    int navio1_linha = 2;    // linha 3 na visualização
    int navio1_coluna = 3;   // coluna D na visualização
    char navio1_orientacao = 'H';

    int navio2_linha = 5;    // linha 6 na visualização
    int navio2_coluna = 7;   // coluna H na visualização
    char navio2_orientacao = 'V';

    if(!verificaLimites(navio1_linha, navio1_coluna, TAMANHO_NAVIO, navio1_orientacao)) {
        printf("Navio 1 está fora dos limites do tabuleiro.\n");
        return 1;
    }
    if(verificaSobreposicao(tabuleiro, navio1_linha, navio1_coluna, TAMANHO_NAVIO, navio1_orientacao)) {
        printf("Navio 1 sobrepõe outro navio.\n");
        return 1;
    }
    posicionaNavio(tabuleiro, navio1_linha, navio1_coluna, TAMANHO_NAVIO, navio1_orientacao);

    if(!verificaLimites(navio2_linha, navio2_coluna, TAMANHO_NAVIO, navio2_orientacao)) {
        printf("Navio 2 está fora dos limites do tabuleiro.\n");
        return 1;
    }
    if(verificaSobreposicao(tabuleiro, navio2_linha, navio2_coluna, TAMANHO_NAVIO, navio2_orientacao)) {
        printf("Navio 2 sobrepõe outro navio.\n");
        return 1;
    }
    posicionaNavio(tabuleiro, navio2_linha, navio2_coluna, TAMANHO_NAVIO, navio2_orientacao);

    exibeTabuleiro(tabuleiro);

    return 0;
}