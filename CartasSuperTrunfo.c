#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct {
    char codigo[16];
    char estado[4];
    char nome[64];
    unsigned long int populacao;
    double area;
    double pib;
    int pontos_turisticos;

    double densidade;
    double pib_per_capita;
    float super_poder;
} Carta;

static void ler_linha(const char *prompt, char *buf, size_t tam) {
    printf("%s", prompt);
    fgets(buf, (int)tam, stdin);
    buf[strcspn(buf, "\n")] = 0;
}

static void ler_carta(Carta *c, int idx) {
    char tmp[128];
    printf("\n--- Cadastro da Carta %d ---\n", idx);

    ler_linha("Digite o codigo: ", c->codigo, sizeof(c->codigo));
    ler_linha("Digite o estado (UF): ", c->estado, sizeof(c->estado));
    ler_linha("Digite o nome da cidade: ", c->nome, sizeof(c->nome));

    ler_linha("Digite a populacao: ", tmp, sizeof(tmp));
    sscanf(tmp, "%lu", &c->populacao);

    ler_linha("Digite a area em km2: ", tmp, sizeof(tmp));
    sscanf(tmp, "%lf", &c->area);

    ler_linha("Digite o PIB: ", tmp, sizeof(tmp));
    sscanf(tmp, "%lf", &c->pib);

    ler_linha("Digite o numero de pontos turisticos: ", tmp, sizeof(tmp));
    sscanf(tmp, "%d", &c->pontos_turisticos);
}

static void calcular_derivados(Carta *c) {
    c->densidade     = (c->area > 0) ? (double)c->populacao / c->area : INFINITY;
    c->pib_per_capita= (c->populacao > 0) ? c->pib / (double)c->populacao : 0.0;

    double inv_densidade = (isfinite(c->densidade) && c->densidade > 0.0)
                         ? 1.0 / c->densidade
                         : 0.0;

    double soma = (double)c->populacao + c->area + c->pib +
                  (double)c->pontos_turisticos + c->pib_per_capita + inv_densidade;

    c->super_poder = (float)soma;
}

static void exibir_carta(const Carta *c, int idx) {
    printf("\n=== Carta %d ===\n", idx);
    printf("Codigo: %s\n", c->codigo);
    printf("Estado: %s\n", c->estado);
    printf("Cidade: %s\n", c->nome);
    printf("Populacao: %lu\n", c->populacao);
    printf("Area: %.2f\n", c->area);
    printf("PIB: %.2f\n", c->pib);
    printf("Pontos Turisticos: %d\n", c->pontos_turisticos);
    printf("Densidade Populacional: %.6f\n", isfinite(c->densidade) ? c->densidade : 0.0);
    printf("PIB per Capita: %.6f\n", c->pib_per_capita);
    printf("Super Poder: %.6f\n", c->super_poder);
}

static void comparar(const char *rotulo, double v1, double v2, int maior_vence) {
    int resultado = (fabs(v1 - v2) < 1e-12) ? -1
                    : (maior_vence ? (v1 > v2) : (v1 < v2));

    printf("%s: %s\n", rotulo,
           (resultado == -1) ? "Empate (0)" :
           (resultado == 1)  ? "Carta 1 venceu (1)" :
                               "Carta 2 venceu (0)");
}

int main(void) {
    Carta c1 = {0}, c2 = {0};

    ler_carta(&c1, 1);
    ler_carta(&c2, 2);

    calcular_derivados(&c1);
    calcular_derivados(&c2);

    exibir_carta(&c1, 1);
    exibir_carta(&c2, 2);

    printf("\nComparacao de Cartas:\n\n");
    comparar("Populacao",           (double)c1.populacao, (double)c2.populacao, 1);
    comparar("Area",                c1.area,              c2.area,              1);
    comparar("PIB",                 c1.pib,               c2.pib,               1);
    comparar("Pontos Turisticos",   (double)c1.pontos_turisticos, (double)c2.pontos_turisticos, 1);
    comparar("Densidade Populacional", c1.densidade,       c2.densidade,        0); // menor vence
    comparar("PIB per Capita",      c1.pib_per_capita,    c2.pib_per_capita,    1);
    comparar("Super Poder",         c1.super_poder,       c2.super_poder,       1);

    return 0;
}
