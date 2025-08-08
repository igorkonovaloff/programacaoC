#include <stdio.h>

int main(){

    char estado, codigo_carta[4], nome_cidade[50], estado_2, codigo_carta_2[4], nome_cidade_2[50];
    int populacao, qtd_pontos_turisticos, populacao_2, qtd_pontos_turisticos_2;
    float area_cidade_km_quadrado, pib_cidade, area_cidade_km_quadrado_2, pib_cidade_2;

    //Carta 1 - Entrada de dados
    printf("CARTA 1: \n");

    printf("Digite o Estado: \n");
    scanf(" %c", &estado);

    printf("Digite o Código da carta (A letra do estado seguida de um número de 01 a 04. ex: A01, B03): \n");
    scanf(" %s", codigo_carta);

    printf("Digite o Nome da cidade: \n");
    scanf(" %[^\n]", nome_cidade);

    printf("Digite o Número de habitantes da cidade (em bilhões): \n");
    scanf(" %i", &populacao);

    printf("Digite a Área da cidade (em km²): \n");
    scanf(" %f", &area_cidade_km_quadrado);

    printf("Digite o PIB da cidade: \n");
    scanf(" %f", &pib_cidade);

    printf("Digite o Número de pontos turísticos da cidade: \n");
    scanf("%i", &qtd_pontos_turisticos);

    //Carta 2 - Entrada de dados
    printf(" \n");
    printf("CARTA 2: \n");

    printf("Digite o Estado: \n");
    scanf(" %c", &estado_2);

    printf("Digite o Código da carta (A letra do estado seguida de um número de 01 a 04. ex: A01, B03): \n");
    scanf(" %s", codigo_carta_2);

    printf("Digite o Nome da cidade: \n");
    scanf(" %[^\n]", nome_cidade_2);

    printf("Digite o Número de habitantes da cidade (em bilhões): \n");
    scanf(" %i", &populacao_2);

    printf("Digite a Área da cidade (em km²): \n");
    scanf(" %f", &area_cidade_km_quadrado_2);

    printf("Digite o PIB da cidade: \n");
    scanf(" %f", &pib_cidade_2);

    printf("Digite o Número de pontos turísticos da cidade: \n");
    scanf(" %i", &qtd_pontos_turisticos_2);



    //Mostra os resultados da Carta 1 na tela
    printf(" \n");
    printf(" \n");
    printf(" \n");
    printf("Carta 1: \n");
    printf("Estado: %c \n", estado);
    printf("Código: %s \n", codigo_carta);
    printf("Nome da cidade: %s \n", nome_cidade);
    printf("População: %i \n", populacao);
    printf("Área: %.2f km² \n", area_cidade_km_quadrado);
    printf("PIB: %.2f bilhões de reais \n", pib_cidade);
    printf("Número de Pontos Turísticos: %i \n", qtd_pontos_turisticos);

    //Mostra os resultados da Carta 2 na tela
    printf(" \n");
    printf(" \n");
    printf(" \n");
    printf("Carta 2: \n");
    printf("Estado: %c \n", estado_2);
    printf("Código: %s \n", codigo_carta_2);
    printf("Nome da cidade: %s \n", nome_cidade_2);
    printf("População: %i \n", populacao_2);
    printf("Área: %.2f km² \n", area_cidade_km_quadrado_2);
    printf("PIB: %.2f bilhões de reais \n", pib_cidade_2);
    printf("Número de Pontos Turísticos: %i \n", qtd_pontos_turisticos_2);


    printf(" \n");
    printf(" \n");
    printf(" \n");

    return 0;

}