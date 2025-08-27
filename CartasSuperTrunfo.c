#include <stdio.h>

// Programa: Super Trunfo - Comparação de Cartas
// Nível: Novato
// Objetivo: Cadastrar duas cartas e compará-las por um atributo numérico

int main() {
    // Dados da Carta 1
    char estado1[50], codigo1[10], cidade1[50];
    int populacao1, pontosTuristicos1;
    float area1, pib1;
    float densidade1, pibPerCapita1;

    // Dados da Carta 2
    char estado2[50], codigo2[10], cidade2[50];
    int populacao2, pontosTuristicos2;
    float area2, pib2;
    float densidade2, pibPerCapita2;

    // Cadastro da Carta 1

    printf("Digite o codigo da Carta 1: ");
    scanf(" %[^\n]", codigo1);

    printf("Digite o estado da Carta 1: ");
    scanf(" %[^\n]", estado1);

    printf("Digite o nome da cidade da Carta 1: ");
    scanf(" %[^\n]", cidade1);

    printf("Digite a populacao da Carta 1: ");
    scanf("%d", &populacao1);

    printf("Digite a area da Carta 1 (km²): ");
    scanf("%f", &area1);

    printf("Digite o PIB da Carta 1 (em bilhoes): ");
    scanf("%f", &pib1);

    printf("Digite o numero de pontos turisticos da Carta 1: ");
    scanf("%d", &pontosTuristicos1);

    // Calculando valores derivados
    densidade1 = populacao1 / area1;
    pibPerCapita1 = pib1 / populacao1;

    // Cadastro da Carta 2

    printf("Digite o codigo da Carta 2: ");
    scanf(" %[^\n]", codigo2);

    printf("Digite o estado da Carta 2: ");
    scanf(" %[^\n]", estado2);

    printf("Digite o nome da cidade da Carta 2: ");
    scanf(" %[^\n]", cidade2);

    printf("Digite a populacao da Carta 2: ");
    scanf("%d", &populacao2);

    printf("Digite a area da Carta 2 (km²): ");
    scanf("%f", &area2);

    printf("Digite o PIB da Carta 2 (em bilhoes): ");
    scanf("%f", &pib2);

    printf("Digite o numero de pontos turisticos da Carta 2: ");
    scanf("%d", &pontosTuristicos2);

    // Calculando valores derivados
    densidade2 = populacao2 / area2;
    pibPerCapita2 = pib2 / populacao2;

    // --- COMPARAÇÃO ---
    // Alterar aqui o atributo desejado:
    // Opções: populacao1 vs populacao2
    //         area1 vs area2
    //         pib1 vs pib2
    //         densidade1 vs densidade2
    //         pibPerCapita1 vs pibPerCapita2

    printf("\n=== Comparacao de cartas (Atributo: Populacao) ===\n");
    printf("Carta 1 - %s (%s): %d habitantes\n", cidade1, estado1, populacao1);
    printf("Carta 2 - %s (%s): %d habitantes\n", cidade2, estado2, populacao2);

    if (populacao1 > populacao2) {
        printf("Resultado: Carta 1 (%s) venceu!\n", cidade1);
    } else if (populacao2 > populacao1) {
        printf("Resultado: Carta 2 (%s) venceu!\n", cidade2);
    } else {
        printf("Resultado: Empate!\n");
    }

    return 0;
}