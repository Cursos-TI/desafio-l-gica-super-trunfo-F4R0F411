#include <stdio.h>
#include <string.h>

// Estrutura para representar uma carta do Super Trunfo
struct Carta {
    char pais[50];
    char codigo[10];
    int populacao;
    float area;
    float pib;
    int numPontosTuristicos;
    float densidadeDemografica;
    float pibPerCapita;
};

// Função para calcular os indicadores derivados
void calcularIndicadores(struct Carta *carta) {
    carta->densidadeDemografica = (float)carta->populacao / carta->area;
    carta->pibPerCapita = carta->pib * 1e9 / carta->populacao; // PIB per capita em reais
}

// Função para exibir os dados da carta
void exibirCarta(struct Carta carta) {
    printf("País: %s\n", carta.pais);
    printf("Código: %s\n", carta.codigo);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões\n", carta.pib);
    printf("Pontos turísticos: %d\n", carta.numPontosTuristicos);
    printf("Densidade Demográfica: %.2f hab/km²\n", carta.densidadeDemografica);
    printf("PIB per capita: %.2f\n", carta.pibPerCapita);
    printf("\n");
}

// Função auxiliar para obter o valor de um atributo
float obterValorAtributo(struct Carta carta, int atributo) {
    switch (atributo) {
        case 1: return (float)carta.populacao;
        case 2: return carta.area;
        case 3: return carta.pib;
        case 4: return (float)carta.numPontosTuristicos;
        case 5: return carta.densidadeDemografica;
        case 6: return carta.pibPerCapita;
        default: return 0;
    }
}

// Função para exibir o nome do atributo
const char* nomeAtributo(int atributo) {
    switch (atributo) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Número de Pontos Turísticos";
        case 5: return "Densidade Demográfica";
        case 6: return "PIB per capita";
        default: return "Desconhecido";
    }
}

int main() {
    struct Carta carta1 = {"Brasil", "P001", 211000000, 8516000.0, 14450.0, 20};
    struct Carta carta2 = {"Argentina", "P002", 45000000, 2780000.0, 500.0, 15};

    calcularIndicadores(&carta1);
    calcularIndicadores(&carta2);

    int opcao1, opcao2;
    float valor1Carta1, valor1Carta2;
    float valor2Carta1, valor2Carta2;
    float soma1, soma2;

    printf("=== Super Trunfo: Desafio Final ===\n\n");
    printf("Carta 1:\n");
    exibirCarta(carta1);
    printf("Carta 2:\n");
    exibirCarta(carta2);

    printf("Escolha o PRIMEIRO atributo para comparação:\n");
    printf("1 - População\n2 - Área\n3 - PIB\n4 - Número de Pontos Turísticos\n5 - Densidade Demográfica\n6 - PIB per capita\n");
    printf("Sua escolha: ");
    scanf("%d", &opcao1);

    if (opcao1 < 1 || opcao1 > 6) {
        printf("Opção inválida.\n");
        return 1;
    }

    printf("\nEscolha o SEGUNDO atributo para comparação:\n");
    for (int i = 1; i <= 6; i++) {
        if (i != opcao1) {
            printf("%d - %s\n", i, nomeAtributo(i));
        }
    }
    printf("Sua escolha: ");
    scanf("%d", &opcao2);

    if (opcao2 < 1 || opcao2 > 6 || opcao2 == opcao1) {
        printf("Opção inválida.\n");
        return 1;
    }

    printf("\n--- COMPARAÇÃO DOS ATRIBUTOS ---\n");

    valor1Carta1 = obterValorAtributo(carta1, opcao1);
    valor1Carta2 = obterValorAtributo(carta2, opcao1);
    valor2Carta1 = obterValorAtributo(carta1, opcao2);
    valor2Carta2 = obterValorAtributo(carta2, opcao2);

    printf("Atributo 1: %s\n", nomeAtributo(opcao1));
    printf("%s: %.2f | %s: %.2f\n", carta1.pais, valor1Carta1, carta2.pais, valor1Carta2);
    int resultado1 = (opcao1 == 5) ? (valor1Carta1 < valor1Carta2 ? 1 : (valor1Carta2 < valor1Carta1 ? 2 : 0))
                                   : (valor1Carta1 > valor1Carta2 ? 1 : (valor1Carta2 > valor1Carta1 ? 2 : 0));

    printf("Atributo 2: %s\n", nomeAtributo(opcao2));
    printf("%s: %.2f | %s: %.2f\n", carta1.pais, valor2Carta1, carta2.pais, valor2Carta2);
    int resultado2 = (opcao2 == 5) ? (valor2Carta1 < valor2Carta2 ? 1 : (valor2Carta2 < valor2Carta1 ? 2 : 0))
                                   : (valor2Carta1 > valor2Carta2 ? 1 : (valor2Carta2 > valor2Carta1 ? 2 : 0));

    soma1 = valor1Carta1 + valor2Carta1;
    soma2 = valor1Carta2 + valor2Carta2;

    printf("\n--- RESULTADO FINAL ---\n");
    printf("Soma dos atributos:\n");
    printf("%s: %.2f\n", carta1.pais, soma1);
    printf("%s: %.2f\n", carta2.pais, soma2);

    printf("\nVencedor: ");
    if (soma1 > soma2) {
        printf("%s venceu a rodada!\n", carta1.pais);
    } else if (soma2 > soma1) {
        printf("%s venceu a rodada!\n", carta2.pais);
    } else {
        printf("Empate!\n");
    }

    return 0;
}