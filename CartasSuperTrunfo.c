#include <stdio.h>
#include <string.h>

// Programa: Super Trunfo - Comparações Avançadas
// Nível: Mestre
// Objetivo: Comparar duas cartas com dois atributos escolhidos pelo jogador

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

    // ===== CADASTRO DAS CARTAS =====
    printf("=== Cadastro da Carta 1 ===\n");
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

    printf("\n=== Cadastro da Carta 2 ===\n");
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

    // ===== MENU DE ESCOLHA DE ATRIBUTOS =====
    int opcao1, opcao2;
    float valor1_carta1, valor1_carta2;
    float valor2_carta1, valor2_carta2;
    float soma1, soma2;
    char atributo1[30], atributo2[30];

    printf("\n=== SUPER TRUNFO - COMPARACAO ===\n");
    printf("Escolha 2 atributos diferentes para comparar:\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("4 - Densidade Demografica\n");
    printf("5 - PIB per Capita\n");

    // Escolha do primeiro atributo
    printf("\nEscolha o primeiro atributo (1 a 5): ");
    scanf("%d", &opcao1);

    switch(opcao1) {
        case 1: valor1_carta1 = populacao1; valor1_carta2 = populacao2; strcpy(atributo1, "Populacao"); break;
        case 2: valor1_carta1 = area1; valor1_carta2 = area2; strcpy(atributo1, "Area"); break;
        case 3: valor1_carta1 = pib1; valor1_carta2 = pib2; strcpy(atributo1, "PIB"); break;
        case 4: valor1_carta1 = densidade1; valor1_carta2 = densidade2; strcpy(atributo1, "Densidade Demografica"); break;
        case 5: valor1_carta1 = pibPerCapita1; valor1_carta2 = pibPerCapita2; strcpy(atributo1, "PIB per Capita"); break;
        default: printf("Opcao invalida!\n"); return 0;
    }

    // Escolha do segundo atributo
    printf("\nEscolha o segundo atributo (diferente de %s): ", atributo1);
    scanf("%d", &opcao2);

    if (opcao2 == opcao1) {
        printf("Erro: voce nao pode escolher o mesmo atributo duas vezes!\n");
        return 0;
    }

    switch(opcao2) {
        case 1: valor2_carta1 = populacao1; valor2_carta2 = populacao2; strcpy(atributo2, "Populacao"); break;
        case 2: valor2_carta1 = area1; valor2_carta2 = area2; strcpy(atributo2, "Area"); break;
        case 3: valor2_carta1 = pib1; valor2_carta2 = pib2; strcpy(atributo2, "PIB"); break;
        case 4: valor2_carta1 = densidade1; valor2_carta2 = densidade2; strcpy(atributo2, "Densidade Demografica"); break;
        case 5: valor2_carta1 = pibPerCapita1; valor2_carta2 = pibPerCapita2; strcpy(atributo2, "PIB per Capita"); break;
        default: printf("Opcao invalida!\n"); return 0;
    }

    // ===== RESULTADOS =====
    printf("\n=== RESULTADOS DA COMPARACAO ===\n");
    printf("Carta 1 - %s (%s)\n", cidade1, estado1);
    printf("Carta 2 - %s (%s)\n\n", cidade2, estado2);

    // Comparacao do atributo 1
    printf("Atributo 1: %s\n", atributo1);
    printf("  %s: %.2f\n  %s: %.2f\n", cidade1, valor1_carta1, cidade2, valor1_carta2);

    int vencedor1 = (opcao1 == 4) ?  // Se for densidade, menor vence
                    (valor1_carta1 < valor1_carta2 ? 1 : (valor1_carta2 < valor1_carta1 ? 2 : 0)) :
                    (valor1_carta1 > valor1_carta2 ? 1 : (valor1_carta2 > valor1_carta1 ? 2 : 0));

    printf("  Vencedor do atributo 1: %s\n\n", vencedor1 == 1 ? cidade1 : vencedor1 == 2 ? cidade2 : "Empate");

    // Comparacao do atributo 2
    printf("Atributo 2: %s\n", atributo2);
    printf("  %s: %.2f\n  %s: %.2f\n", cidade1, valor2_carta1, cidade2, valor2_carta2);

    int vencedor2 = (opcao2 == 4) ?  
                    (valor2_carta1 < valor2_carta2 ? 1 : (valor2_carta2 < valor2_carta1 ? 2 : 0)) :
                    (valor2_carta1 > valor2_carta2 ? 1 : (valor2_carta2 > valor2_carta1 ? 2 : 0));

    printf("  Vencedor do atributo 2: %s\n\n", vencedor2 == 1 ? cidade1 : vencedor2 == 2 ? cidade2 : "Empate");

    // Soma dos atributos
    soma1 = valor1_carta1 + valor2_carta1;
    soma2 = valor1_carta2 + valor2_carta2;

    printf("Soma dos atributos:\n");
    printf("  %s: %.2f\n  %s: %.2f\n", cidade1, soma1, cidade2, soma2);

    // Resultado final
    printf("\n=== RESULTADO FINAL ===\n");
    if (soma1 > soma2) {
        printf("Carta 1 (%s) venceu a rodada!\n", cidade1);
    } else if (soma2 > soma1) {
        printf("Carta 2 (%s) venceu a rodada!\n", cidade2);
    } else {
        printf("Empate!\n");
    }

    return 0;
}
