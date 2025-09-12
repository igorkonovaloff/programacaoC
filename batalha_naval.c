#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h> // Necessária para as funções de string
//Definição de constantes globais
//O programa funcionará com alterção destas constantes. Todavia, se a quantidade ou tamanho dos navios não couber no tabuleiro,
// pode entrar em loop infinito
#define TAMANHO_TABULEIRO 10 //Tamanho do tabuleiro
#define QTD_NAVIOS 5 //Quantidade de navios que serão colocados no tabuleiro 
#define TAMANHO_NAVIO 3 //Tamanho dos 
//Estes 3 símbolos devem ser diferentes
#define SIMBOLO_NAVIO_HORIZONTAL 3 //Simbolo que aparecerá onde houver navios na horizontal
#define SIMBOLO_NAVIO_VERTICAL 1 //Simbolo que aparecerá onde houver navios na vertical
#define SIMBOLO_AGUA 0 //Simbolo que aparecerá onde houver água

const char HORIZONTAL[] = "HORIZONTAL";
const char VERTICAL[] = "VERTICAL";
const char *direcao_navio[2]={HORIZONTAL,VERTICAL}; //Direção que o navio será desenhado
int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]; //Tabuleiro do jogo


/**
 * Função que gera um número aleatório entre 0 e RAND_MAX (inclusive)
 * RAND_MAX É o maior número que será gerado.
 */
int gerar_numero_aleatorio(int rand_max) {
    // O operador de módulo (%) limita o número ao intervalo desejado.
    return rand() % rand_max;
}

/**
 * Função que verifica se já existe parte de algum navio na posição que será desenhado o novo navio.
 * LINHA_INICIAL É o número da linha inicial onde será desenhado o navio
 * COLUNA_INICIAL É o número da coluna inicial onde será desenhado o navio
 * DIRECAO É a direção em que o navio será criado [HORIZONTAL ou VERTICAL]
 */
bool verifica_posicao(int linha_inicial, int coluna_inicial, int direcao){

    //Se a direção for horizontal, verifica se está preenchida alguma coluna, até o tamanho do navio, partindo da linha inicial.
    if (strcmp(direcao_navio[direcao], HORIZONTAL) == 0){
        for (int i=coluna_inicial; i < coluna_inicial + TAMANHO_NAVIO; ++i){
            if (tabuleiro[linha_inicial][i] == SIMBOLO_NAVIO_HORIZONTAL || tabuleiro[linha_inicial][i] == SIMBOLO_NAVIO_VERTICAL) {
                return false;
            }
        }
    //Se a direção for vertical, verifica se está preenchida alguma linha, até o tamanho do navio, partindo da coluna inicial.
    } else {
        for (int i=linha_inicial; i < linha_inicial + TAMANHO_NAVIO; ++i){
            if (tabuleiro[linha_inicial][i] == SIMBOLO_NAVIO_HORIZONTAL || tabuleiro[linha_inicial][i] == SIMBOLO_NAVIO_VERTICAL) {
                return false;
            }
        }
    }
    return true;   
}



int main() {

    // Inicializa o gerador de números aleatórios com a hora atual.
    srand(time(NULL));

    //Guarda os dados dos navios que serão criados :  Posicao da linha e coluna inicial e direcao
    int navios[QTD_NAVIOS][3];
    //Utilizada para guardar a direção aleatória 0 e 1 para posterior conversão em HORIZONTAL e VERTICAL.
    int iDirecao;

    //Loop que inicializa o tabuleiro todo com zeros.
    for (int i=0; i<TAMANHO_TABULEIRO ;++i){
        for (int j=0; j<10 ;++j){
            tabuleiro[i][j]=SIMBOLO_AGUA;
        }
    }
   
    //Loop para desenhar os navios aleatoriamente
    for (int i=0; i<QTD_NAVIOS ;++i){
        int linha,coluna;
        //Gera aleatoriamente a direção.
        iDirecao=gerar_numero_aleatorio(2);

        //Se a direção for horiozntal
        if (strcmp(direcao_navio[iDirecao], HORIZONTAL) == 0){
            //Sorteia a linha e coluna inicial. Coluna só pode ir até o tamanho do tabuleiro menos o tamanho do navio, 
            //pois senão pode extrapolar a quantidade de colunas do tabuleiro
            do {
                linha  = gerar_numero_aleatorio(TAMANHO_TABULEIRO);
                coluna = gerar_numero_aleatorio(TAMANHO_TABULEIRO-TAMANHO_NAVIO);
            }
            //Se já existe navio na posição, sorteia novamente,
            while (!verifica_posicao(linha, coluna, iDirecao));


            //Preenche a primeira posição do navio
            tabuleiro[linha][coluna]=SIMBOLO_NAVIO_HORIZONTAL;
            //Preenche as demais posições do navio (Lembrando que varia a coluna porque o navio está na horizontal.)
            for (int j=0;j<TAMANHO_NAVIO; ++j){
                tabuleiro[linha][coluna+j]=SIMBOLO_NAVIO_HORIZONTAL;
            }
        } else {
            //Sorteia a linha e coluna inicial. Linha só pode ir até o tamanho do tabuleiro menos o tamanho do navio, 
            //pois senão pode extrapolar a quantidade de linhas do tabuleiro
            do {
                linha  = gerar_numero_aleatorio(TAMANHO_TABULEIRO-TAMANHO_NAVIO);
                coluna = gerar_numero_aleatorio(TAMANHO_TABULEIRO);
            }
            //Se já existe navio na posição, sorteia novamente,
            while (!verifica_posicao(linha, coluna, iDirecao));

            //Preenche a primeira posição do navio
            tabuleiro[linha][coluna]=SIMBOLO_NAVIO_VERTICAL;
            //Preenche as demais posições do navio (Lembrando que varia a linha porque o navio está na vertical.)
            for (int j=0;j<TAMANHO_NAVIO; ++j){
                tabuleiro[linha+j][coluna]=SIMBOLO_NAVIO_VERTICAL;
            }
        }

        //Atribui os dados do navio sorteado para ser conferido ao final.
        navios[i][0]=linha;
        navios[i][1]=coluna;
        navios[i][2]=iDirecao;
};

    
    //Imprime o tabuleiro no formato de matriz para facilitar a conferência.
    for (int i=0; i<TAMANHO_TABULEIRO ;++i){
        printf("\n");
        for (int j=0; j<TAMANHO_TABULEIRO ;++j){
            printf("%i-", tabuleiro[i][j]);
        }
    }
    printf("\n");
   
    //Imprime os dados dos navios para facilitar a conferência.
    for (int i=0; i<QTD_NAVIOS ;++i){
        printf("Navio %i- Linha Inicial: %i - Coluna Inicial: %i - Direcao = %s \n", i, navios[i][0],navios[i][1],navios[i][2]==1?"VERTICAL":"HORIZONTAL");
    }
 
    return 0;
}