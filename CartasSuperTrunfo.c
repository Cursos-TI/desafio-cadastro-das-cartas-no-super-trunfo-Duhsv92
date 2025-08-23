#include <stdio.h>

int main() {
    // Variáveis da Carta 1
    char estado1;
    char codigo1[4];
    char nome1[50];
    int populacao1, pontosTuristicos1;
    float area1, pib1;
    float densidade1, pibPerCapita1;

    // Variáveis da Carta 2
    char estado2;
    char codigo2[4];
    char nome2[50];
    int populacao2, pontosTuristicos2;
    float area2, pib2;
    float densidade2, pibPerCapita2;

    // ======= Entrada de dados da Carta 1 =======
    printf("Digite o estado da Carta 1: ");
    scanf(" %c", &estado1);

    printf("Digite o codigo da Carta 1: ");
    scanf("%s", codigo1);

    printf("Digite o nome da cidade da Carta 1: ");
    scanf(" %[^\n]", nome1);

    printf("Digite a populacao da cidade: ");
    scanf("%d", &populacao1);

    printf("Digite a area da cidade (em km2): ");
    scanf("%f", &area1);

    printf("Digite o PIB da cidade (em bilhoes de reais): ");
    scanf("%f", &pib1);

    printf("Digite o numero de pontos turisticos: ");
    scanf("%d", &pontosTuristicos1);

    // ======= Entrada de dados da Carta 2 =======
    printf("\nDigite o estado da Carta 2: ");
    scanf(" %c", &estado2);

    printf("Digite o codigo da Carta 2: ");
    scanf("%s", codigo2);

    printf("Digite o nome da cidade da Carta 2: ");
    scanf(" %[^\n]", nome2);

    printf("Digite a populacao da cidade: ");
    scanf("%d", &populacao2);

    printf("Digite a area da cidade (em km2): ");
    scanf("%f", &area2);

    printf("Digite o PIB da cidade (em bilhoes de reais): ");
    scanf("%f", &pib2);

    printf("Digite o numero de pontos turisticos: ");
    scanf("%d", &pontosTuristicos2);

    // ======= Cálculos =======
    densidade1 = populacao1 / area1;
    pibPerCapita1 = (pib1 * 1000000000) / populacao1; // PIB em reais por habitante

    densidade2 = populacao2 / area2;
    pibPerCapita2 = (pib2 * 1000000000) / populacao2;

    // ======= Saída Carta 1 =======
    printf("\n=== Carta 1 ===\n");
    printf("Estado: %c\n", estado1);
    printf("Codigo: %s\n", codigo1);
    printf("Nome da Cidade: %s\n", nome1);
    printf("Populacao: %d\n", populacao1);
    printf("Area: %.2f km2\n", area1);
    printf("PIB: %.2f bilhoes de reais\n", pib1);
    printf("Numero de Pontos Turisticos: %d\n", pontosTuristicos1);
    printf("Densidade Populacional: %.2f hab/km2\n", densidade1);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita1);

    // ======= Saída Carta 2 =======
    printf("\n=== Carta 2 ===\n");
    printf("Estado: %c\n", estado2);
    printf("Codigo: %s\n", codigo2);
    printf("Nome da Cidade: %s\n", nome2);
    printf("Populacao: %d\n", populacao2);
    printf("Area: %.2f km2\n", area2);
    printf("PIB: %.2f bilhoes de reais\n", pib2);
    printf("Numero de Pontos Turisticos: %d\n", pontosTuristicos2);
    printf("Densidade Populacional: %.2f hab/km2\n", densidade2);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita2);

    return 0;
}