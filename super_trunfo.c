#include <stdio.h>
#include <string.h>
//#include <stdlib.h>

int main(){

    char estado, codigo_carta[4], nome_cidade[50], estado_2, codigo_carta_2[4], nome_cidade_2[50], 
        escolha, atributo[20], valor_atributo[50], valor_atributo_2[50];
    int populacao, qtd_pontos_turisticos, populacao_2, qtd_pontos_turisticos_2, carta_vencedora;
    float area_cidade_km_quadrado, pib_cidade, area_cidade_km_quadrado_2, pib_cidade_2, densidade_populacional, densidade_populacional_2;
        
    double pib_per_capita, pib_per_capita_2;
    

    //Carta 1 - Entrada de dados
    printf("CARTA 1: \n");

    printf("Digite o Estado (A a H): \n");
    scanf(" %c", &estado);

    printf("Digite o Código da carta (A letra do estado seguida de um número de 01 a 04. ex: A01, B03): \n");
    scanf(" %s", codigo_carta);

    printf("Digite o Nome da cidade: \n");
    scanf(" %[^\n]", nome_cidade);

    printf("Digite o Número de habitantes da cidade : \n");
    scanf(" %i", &populacao);

    printf("Digite a Área da cidade (em km²): \n");
    scanf(" %f", &area_cidade_km_quadrado);

    printf("Digite o PIB da cidade (em bilhões): \n");
    scanf(" %f", &pib_cidade);

    printf("Digite o Número de pontos turísticos da cidade: \n");
    scanf("%i", &qtd_pontos_turisticos);

    //Carta 2 - Entrada de dados
    printf(" \n");
    printf("CARTA 2: \n");

    printf("Digite o Estado (A a H): \n");
    scanf(" %c", &estado_2);

    printf("Digite o Código da carta (A letra do estado seguida de um número de 01 a 04. ex: A01, B03): \n");
    scanf(" %s", codigo_carta_2);

    printf("Digite o Nome da cidade: \n");
    scanf(" %[^\n]", nome_cidade_2);

    printf("Digite o Número de habitantes da cidade: \n");
    scanf(" %i", &populacao_2);

    printf("Digite a Área da cidade (em km²): \n");
    scanf(" %f", &area_cidade_km_quadrado_2);

    printf("Digite o PIB da cidade (em bilhões): \n");
    scanf(" %f", &pib_cidade_2);

    printf("Digite o Número de pontos turísticos da cidade: \n");
    scanf(" %i", &qtd_pontos_turisticos_2);


/*
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

*/

    //Calcula densidade populacional da carta 1
    densidade_populacional   = populacao / area_cidade_km_quadrado;
    //Calcula densidade populacional da carta 2
    densidade_populacional_2 = populacao_2 / area_cidade_km_quadrado_2;

    //Calcula PIB per capita da carta 1 (Multiplica por 1 Bilhão pois na entrada a quantidade é em bilhões)
    pib_per_capita  = pib_cidade * 1000000000 / populacao;
    //Calcula PIB per capita da carta 2 (Multiplica por 1 Bilhão pois na entrada a quantidade é em bilhões)
    pib_per_capita_2 = pib_cidade_2 * 1000000000 / populacao_2;

    //Mostra Densidade populacional e pib per capita da carta 1 
    printf("CARTA 1: \n");
    printf("Densidade Populacional: %.2f \n", densidade_populacional);
    printf("PIB per capita: %.2f \n", pib_per_capita);

    //Mostra Densidade populacional e pib per capita da carta 2 
    printf("CARTA 2: \n");
    printf("Densidade Populacional: %.2f \n", densidade_populacional_2);
    printf("PIB per capita: %.2f \n", pib_per_capita_2);

    //Pula linhas
    printf(" \n");
    printf(" \n");
    printf(" \n");

    //Escolha definida em código. Escolhas Possíveis = P (População), A (Área), I (PIB), D (Densidade Populacional) e C (PIB per capita)
    escolha = 'P';
    //Inicialização da carta vencedora com zero, se não encontrar nenhuma condição, haverá empate.
    carta_vencedora = 0;

    //Preenche as variáveis que serão mostradas de acordo com a opção atribuída a variável "escolha". 
    if (escolha == 'P') {
        strcpy(atributo, "População");
        sprintf(valor_atributo, "%i", populacao);
        sprintf(valor_atributo_2, "%i", populacao_2);

        if (populacao > populacao_2) {
            carta_vencedora = 1;
        } else if (populacao < populacao_2) {
            carta_vencedora = 2;
        }
    } else if (escolha == 'A') {
        strcpy(atributo, "Área");
        sprintf(valor_atributo, "%.2f", area_cidade_km_quadrado);
        sprintf(valor_atributo_2, "%.2f", area_cidade_km_quadrado_2);

        if (area_cidade_km_quadrado > area_cidade_km_quadrado_2) {
            carta_vencedora = 1;
        } else if (area_cidade_km_quadrado < area_cidade_km_quadrado_2) {
            carta_vencedora = 2;
        }
    } else if (escolha == 'I') {
        strcpy(atributo, "PIB");
        sprintf(valor_atributo, "%.2f", pib_cidade);
        sprintf(valor_atributo_2, "%.2f", pib_cidade_2);

        if (pib_cidade > pib_cidade_2) {
            carta_vencedora = 1;
        } else if (pib_cidade < pib_cidade_2) {
            carta_vencedora = 2;
        }
    } else if (escolha == 'D') {
        strcpy(atributo, "Densidade Populacional");
        sprintf(valor_atributo, "%.2f", densidade_populacional);
        sprintf(valor_atributo_2, "%.2f", densidade_populacional_2);

        if (densidade_populacional < densidade_populacional_2) {
            carta_vencedora = 1;
        } else if (densidade_populacional > densidade_populacional_2) {
            carta_vencedora = 2;
        }
    } else if (escolha == 'C') {
        strcpy(atributo, "PIB per capita");
        sprintf(valor_atributo, "%.2f", pib_per_capita);
        sprintf(valor_atributo_2, "%.2f", pib_per_capita_2);

        if (pib_per_capita > pib_per_capita_2) {
            carta_vencedora = 1;
        } else if (pib_per_capita < pib_per_capita_2) {
            carta_vencedora = 2;
        }
    } else
    //Se a variável "escolha" tiver um valor que não seja: P (População), A (Área), I (PIB), D (Densidade Populacional) e C (PIB per capita), 
    //sai do program e mostra mensagem.
        {
            printf("Escolha %c não é válida: \n", escolha);
            return 0;
        }
    
    //Mostra saída pedida no exercício        
    printf("Comparação de cartas (Atributo: %s): \n", atributo);
    printf("Carta 1 - %s (%c): %s \n", nome_cidade, estado, valor_atributo);
    printf("Carta 2 - %s (%c): %s \n", nome_cidade_2, estado_2, valor_atributo_2);

    //Verifica qual carta ganhou e mostra saída pedida no exercício
    if ( carta_vencedora == 0 ) {
            printf("Resultado: Houve empate! \n", atributo);
        } 
    else if ( carta_vencedora == 1 )
            {
                printf("Resultado: Carta 1 (%s) venceu ! \n", nome_cidade);
            }
    else {
            printf("Resultado: Carta 2 (%s) venceu ! \n", nome_cidade_2);
        }
    
    return 0;

}