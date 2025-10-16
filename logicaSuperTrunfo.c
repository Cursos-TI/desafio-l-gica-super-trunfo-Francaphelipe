#include <stdio.h> // Biblioteca para funções de entrada e saída, como printf
#include <string.h> // Biblioteca para manipulação de strings, como strcpy

// Documentação: Define uma estrutura para armazenar os dados de uma carta do Super Trunfo.
struct CartaSuperTrunfo {
    char estado[3];              // Ex: "SP" (2 caracteres + 1 para o terminador nulo '\0')
    char codigo[5];              // Ex: "A1"
    char nomeCidade[50];         // Nome da cidade/capital
    int populacao;               // Número de habitantes
    float area;                  // Área em km²
    float pib;                   // PIB em bilhões de R$
    int pontosTuristicos;        // Quantidade de pontos turísticos
    
    // Campos calculados
    float densidadePopulacional; // Habitantes por km²
    float pibPerCapita;          // PIB por habitante
};

int main() {
    // --- REQUISITO 1: Receber os dados de duas cartas ---
    // Para este desafio, as cartas são pré-definidas diretamente no código.
    
    // Declaração da primeira carta
    struct CartaSuperTrunfo carta1;
    
    // Preenchimento dos dados da Carta 1 (São Paulo)
    strcpy(carta1.estado, "SP");
    strcpy(carta1.codigo, "A1");
    strcpy(carta1.nomeCidade, "Sao Paulo");
    carta1.populacao = 12396372;
    carta1.area = 1521.11f; // 'f' indica que é um float
    carta1.pib = 763.8f;    // PIB em bilhões de R$
    carta1.pontosTuristicos = 15;

    // Declaração da segunda carta
    struct CartaSuperTrunfo carta2;
    
    // Preenchimento dos dados da Carta 2 (Rio de Janeiro)
    strcpy(carta2.estado, "RJ");
    strcpy(carta2.codigo, "B2");
    strcpy(carta2.nomeCidade, "Rio de Janeiro");
    carta2.populacao = 6775561;
    carta2.area = 1200.33f;
    carta2.pib = 358.3f;    // PIB em bilhões de R$
    carta2.pontosTuristicos = 20;

    // --- REQUISITO 2: Calcular Densidade Populacional e PIB per capita ---
    // Lógica: Realiza os cálculos para cada carta e armazena nos campos correspondentes da struct.
    
    // Cálculo para a Carta 1
    carta1.densidadePopulacional = (float)carta1.populacao / carta1.area;
    carta1.pibPerCapita = (carta1.pib * 1000000000) / carta1.populacao; // Converte PIB para valor real

    // Cálculo para a Carta 2
    carta2.densidadePopulacional = (float)carta2.populacao / carta2.area;
    carta2.pibPerCapita = (carta2.pib * 1000000000) / carta2.populacao; // Converte PIB para valor real

    // Exibição dos dados completos das cartas para conferência
    printf("--- DADOS DAS CARTAS CADASTRADAS ---\n");
    printf("Carta 1: %s (%s) \n", carta1.nomeCidade, carta1.estado);
    printf("  - Densidade Populacional: %.2f hab/km^2\n", carta1.densidadePopulacional);
    printf("  - PIB per capita: R$ %.2f\n\n", carta1.pibPerCapita);
    
    printf("Carta 2: %s (%s) \n", carta2.nomeCidade, carta2.estado);
    printf("  - Densidade Populacional: %.2f hab/km^2\n", carta2.densidadePopulacional);
    printf("  - PIB per capita: R$ %.2f\n", carta2.pibPerCapita);
    printf("----------------------------------------\n\n");

    // --- REQUISITO 3: Comparar um atributo escolhido ---
    // A escolha do atributo é feita diretamente nesta variável.
    // Altere o texto abaixo para "Area", "PIB", "Densidade", etc., para testar outras comparações.
    char atributo_escolhido[] = "Populacao";

    // --- REQUISITOS 4 e 5: Determinar a vencedora e Exibir o resultado ---
    printf("======= COMPARACAO SUPER TRUNFO =======\n");
    
    // Lógica: Compara o atributo de texto escolhido e entra no bloco if correspondente.
    if (strcmp(atributo_escolhido, "Populacao") == 0) {
        printf("Atributo de Comparacao: POPULACAO (maior vence)\n\n");
        printf("Carta 1 - %s (%s): %d\n", carta1.nomeCidade, carta1.estado, carta1.populacao);
        printf("Carta 2 - %s (%s): %d\n", carta2.nomeCidade, carta2.estado, carta2.populacao);
        printf("----------------------------------------\n");
        
        if (carta1.populacao > carta2.populacao) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
        } else if (carta2.populacao > carta1.populacao) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
        } else {
            printf("Resultado: EMPATE!\n");
        }
    } 
    else if (strcmp(atributo_escolhido, "Densidade") == 0) {
        // Lógica: Regra especial para Densidade, onde o MENOR valor vence.
        printf("Atributo de Comparacao: DENSIDADE POPULACIONAL (menor vence)\n\n");
        printf("Carta 1 - %s (%s): %.2f hab/km^2\n", carta1.nomeCidade, carta1.estado, carta1.densidadePopulacional);
        printf("Carta 2 - %s (%s): %.2f hab/km^2\n", carta2.nomeCidade, carta2.estado, carta2.densidadePopulacional);
        printf("----------------------------------------\n");
        
        if (carta1.densidadePopulacional < carta2.densidadePopulacional) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
        } else if (carta2.densidadePopulacional < carta1.densidadePopulacional) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
        } else {
            printf("Resultado: EMPATE!\n");
        }
    }
    else if (strcmp(atributo_escolhido, "PIB") == 0) {
        printf("Atributo de Comparacao: PIB (maior vence)\n\n");
        printf("Carta 1 - %s (%s): %.2f Bilhoes\n", carta1.nomeCidade, carta1.estado, carta1.pib);
        printf("Carta 2 - %s (%s): %.2f Bilhoes\n", carta2.nomeCidade, carta2.estado, carta2.pib);
        printf("----------------------------------------\n");
        
        if (carta1.pib > carta2.pib) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
        } else if (carta2.pib > carta1.pib) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
        } else {
            printf("Resultado: EMPATE!\n");
        }
    }
     else {
        // Mensagem para caso o atributo escolhido não seja um dos implementados.
        printf("Atributo '%s' nao reconhecido para comparacao.\n", atributo_escolhido);
    }
    
    printf("=======================================\n");

    return 0; 
}

