#include <stdio.h>

/*
    Simulação avançada dos movimentos das peças de xadrez:
    - Torre: movimento recursivo para a direita
    - Bispo: movimento recursivo para cima e à direita + loops aninhados (vertical/horizontal)
    - Rainha: movimento recursivo para a esquerda
    - Cavalo: movimento em "L" (duas casas para cima e uma para a direita) usando loops aninhados complexos
*/

// Função recursiva para o movimento da Torre (direita)
void moverTorre(int casas) {
    if (casas == 0) return;
    printf("Direita\n");
    moverTorre(casas - 1);
}

// Função recursiva para o movimento da Rainha (esquerda)
void moverRainha(int casas) {
    if (casas == 0) return;
    printf("Esquerda\n");
    moverRainha(casas - 1);
}

// Função recursiva para o movimento do Bispo (cima e direita)
void moverBispoRecursivo(int casas) {
    if (casas == 0) return;
    printf("Cima Direita\n");
    moverBispoRecursivo(casas - 1);
}

// Função para o movimento do Bispo usando loops aninhados (vertical/horizontal)
void moverBispoLoops(int casas_vertical, int casas_horizontal) {
    // O bispo só pode andar na diagonal, então casas_vertical == casas_horizontal
    for (int v = 1; v <= casas_vertical; v++) {
        for (int h = 1; h <= casas_horizontal; h++) {
            if (v == h) {
                printf("Cima Direita\n");
                break; // Garante que só imprime uma vez por diagonal
            }
        }
    }
}

// Função para o movimento complexo do Cavalo (duas casas para cima, uma para a direita)
void moverCavalo(int movimentos) {
    // Cada movimento é um "L": 2 para cima, 1 para a direita
    for (int m = 1; m <= movimentos; m++) {
        int casas_cima = 2;
        int casas_direita = 1;
        int i = 0, j = 0;
        // Loop externo: casas para cima
        for (i = 0; i < casas_cima + casas_direita; i++) {
            if (i < casas_cima) {
                printf("Cima\n");
                // Se quiser pular a segunda casa para cima, pode usar continue
                continue;
            }
            // Loop interno: casa para a direita
            for (j = 0; j < casas_direita; j++) {
                printf("Direita\n");
                // Como só há uma casa para a direita, pode usar break
                break;
            }
        }
        // Linha em branco entre movimentos do cavalo, se houver mais de um
        if (m < movimentos) printf("\n");
    }
}

int main() {
    // Movimento da Torre: 5 casas para a direita (recursivo)
    int casas_torre = 5;
    printf("Movimento da Torre:\n");
    moverTorre(casas_torre);

    // Movimento do Bispo: 5 casas na diagonal para cima e à direita (recursivo)
    int casas_bispo = 5;
    printf("\nMovimento do Bispo (Recursivo):\n");
    moverBispoRecursivo(casas_bispo);

    // Movimento do Bispo: 5 casas na diagonal para cima e à direita (loops aninhados)
    printf("\nMovimento do Bispo (Loops Aninhados):\n");
    moverBispoLoops(casas_bispo, casas_bispo);

    // Movimento da Rainha: 8 casas para a esquerda (recursivo)
    int casas_rainha = 8;
    printf("\nMovimento da Rainha:\n");
    moverRainha(casas_rainha);

    // Movimento do Cavalo: 2 para cima, 1 para a direita (loops aninhados complexos)
    int movimentos_cavalo = 1; // Quantos movimentos em "L" deseja simular
    printf("\nMovimento do Cavalo:\n");
    moverCavalo(movimentos_cavalo);

    return 0;
}