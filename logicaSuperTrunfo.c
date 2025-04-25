#include <stdio.h>
#include <string.h>

// Estrutura para armazenar os dados de uma carta do Super Trunfo
typedef struct {
    char estado[3];               // Sigla do estado (ex: SP)
    char codigoCarta[10];        // Código da carta
    char nomeCidade[50];         // Nome da cidade
    int populacao;               // População
    float area;                  // Área em km²
    float pib;                   // PIB em bilhões
    int pontosTuristicos;        // Número de pontos turísticos
    float densidadePopulacional;// População / Área
    float pibPerCapita;          // PIB / População
} Carta;

// Função para cadastrar os dados da carta
void cadastrarCarta(Carta *carta, const char *estado, const char *codigo, const char *cidade,
                    int populacao, float area, float pib, int pontosTuristicos) {
    strcpy(carta->estado, estado);
    strcpy(carta->codigoCarta, codigo);
    strcpy(carta->nomeCidade, cidade);
    carta->populacao = populacao;
    carta->area = area;
    carta->pib = pib;
    carta->pontosTuristicos = pontosTuristicos;
    carta->densidadePopulacional = populacao / area;
    carta->pibPerCapita = pib / populacao;
}

// Função para exibir os dados de uma carta
void exibirCarta(Carta carta) {
    printf("Cidade: %s (%s)\n", carta.nomeCidade, carta.estado);
    printf("Código da Carta: %s\n", carta.codigoCarta);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta.densidadePopulacional);
    printf("PIB per capita: %.2f\n", carta.pibPerCapita);
    printf("-----------------------------------\n");
}

int main() {
    Carta carta1, carta2;

    // Cadastro das cartas (dados fictícios)
    cadastrarCarta(&carta1, "SP", "C001", "São Paulo", 12300000, 1521.11, 760.0, 30);
    cadastrarCarta(&carta2, "RJ", "C002", "Rio de Janeiro", 6000000, 1182.30, 407.0, 25);

    // Exibindo cartas
    printf("=== CARTA 1 ===\n");
    exibirCarta(carta1);
    printf("=== CARTA 2 ===\n");
    exibirCarta(carta2);

    // Comparação com base em População
    printf("Comparação de cartas (Atributo: População):\n\n");
    printf("Carta 1 - %s (%s): %d\n", carta1.nomeCidade, carta1.estado, carta1.populacao);
    printf("Carta 2 - %s (%s): %d\n", carta2.nomeCidade, carta2.estado, carta2.populacao);

    if (carta1.populacao > carta2.populacao) {
        printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
    } else if (carta2.populacao > carta1.populacao) {
        printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
    } else {
        printf("Resultado: Empate!\n");
    }

    return 0;
}