#include <stdio.h>
#include <string.h> // Necessária para as funções de string
#include <stdbool.h> // Necessária para a declaração Bool
#include <stdlib.h> // Necessário para a função system()

//Declaração das constantes
const char RAINHA[7] = "RAINHA", TORRE[6]  = "TORRE", BISPO[6]  = "BISPO", CAVALO[7] = "CAVALO";
const char DIREITA[8] = "DIREITA", ESQUERDA[9] = "ESQUERDA", CIMA[5] = "CIMA", BAIXO[6] = "BAIXO"; 
const char CIMA_DIREITA[13] = "CIMA_DIREITA", BAIXO_DIREITA[14] = "BAIXO_DIREITA" , CIMA_ESQUERDA[14] = "CIMA_ESQUERDA", BAIXO_ESQUERDA[15]="BAIXO_ESQUERDA";

// Declaração antecipada para que a struct Peca seja reconhecida
typedef struct Peca Peca;

//Define a estrutura da tabela de métodos para a classe Peça
typedef struct {
    // Método (ponteiro para função)
    bool (*mover)(Peca*);

} Peca_VTable;

//Emula uma classe abstrata. As outras classes vão derivar dela. 
struct Peca {
    // Parâmetros (dados do objeto)
    char sentido[20];
    int casas;
    Peca_VTable *vpeca;
};

// Classe concreta Derivada: Torre
typedef struct {
    Peca peca;
} Torre;

// Classe concreta Derivada: Bispo
typedef struct {
    Peca peca;
} Bispo;

// Classe concreta Derivada: Rainha
typedef struct {
    Peca peca;
} Rainha;


//Implementação dos tipos de movimentos que podem ser executados pelas peças.
//Recebe um objeto peça genérico e retorna se o movimento foi feito ou não.

//Movimento horizontal e vertical
bool mover_horizontal_vertical(Peca *p) {
    int i;
    bool movimentou = true;
    if (strcmp(p->sentido, DIREITA) == 0) {
        for (i=1; i <= p->casas; ++i) {
            printf("Direita\n");
        }
    } else if (strcmp(p->sentido, ESQUERDA) == 0) {
        for (i=1; i <= p->casas; ++i) {
            printf("Esquerda\n");
        }
    } else if (strcmp(p->sentido, CIMA) == 0) {
        for (i=1; i <= p->casas; ++i) {
            printf("Cima\n");
        }
    } else if (strcmp(p->sentido, BAIXO) == 0) {
        for (i=1; i <= p->casas; ++i) {
            printf("Baixo\n");
        }
    } else {
        movimentou = false;                
    }

    return movimentou;
}

//Movimento horizontal e vertical
bool mover_diagonal(Peca *p) {
    int i;
    bool movimentou = true;

    if (strcmp(p->sentido, CIMA_DIREITA) == 0) {
        for (i=1; i <= p->casas; ++i) {
            printf("Cima\n");
            printf("Direita\n");
        }
    } else if (strcmp(p->sentido, CIMA_ESQUERDA) == 0) {
        for (i=1; i <= p->casas; ++i) {
            printf("Cima\n");
            printf("Esquerda\n");
        }
    } else if (strcmp(p->sentido, BAIXO_DIREITA) == 0) {
        for (i=1; i <= p->casas; ++i) {
            printf("Baixo\n");
            printf("Direita\n");
        }
    } else if (strcmp(p->sentido, BAIXO_ESQUERDA) == 0) {
        for (i=1; i <= p->casas; ++i) {
            printf("Baixo\n");
            printf("Esquerda\n");
        }
    } else {
        //Verifica se houve movimento da peça. Este retorno é utilizado para peças que fazem mais de um tipo de movimento.
        movimentou = false;                
    }

    return movimentou;
}


//Movimento horizontal e vertical e diagonal
bool mover_diagonal_horizontal_vertical(Peca *p) {
    int i;
    bool movimentou = false;

    //Verifica se houve movimento de algum tipo para a peça.
    if (mover_diagonal(p) || mover_horizontal_vertical(p)) {
        movimentou = true;
    }

    return movimentou; 
}

// Aloca a VTable para a Torre (pode ser estática para economizar memória mas deve existir uma para cada tipo de peça)
// e aplica polimorfismo.
static Peca_VTable vtable_torre = {
    .mover = mover_horizontal_vertical
};

// Aloca a VTable para o Bispo 
static Peca_VTable vtable_bispo = {
    .mover = mover_diagonal
};

// Aloca a VTable para o Bispo 
static Peca_VTable vtable_rainha = {
    .mover = mover_diagonal_horizontal_vertical
};

//Configura o estado interno do objeto.
void inicializar_peca(Peca* peca, char * sentido, int casas){
    //peca é um ponteiro, então não há necessidade da função retornar o objeto. 
    snprintf(peca->sentido, sizeof(peca->sentido), "%s", sentido);
    peca->casas = casas;
}

// Implementação dos construtores de cada classe. Efetivamente seta os atributos e vincula o ponteiro de cada vtable (tabela de métodos) ao objeto correspondente.

// Construtor da Torre
void inicializar_torre(Torre *torre, char * sentido, int casas) {

    inicializar_peca((Peca*)torre, sentido, casas);

    torre->peca.vpeca = &vtable_torre;
}

// Construtor do bispo
void inicializar_bispo(Bispo *bispo, char * sentido, int casas) {

    inicializar_peca((Peca*)bispo, sentido, casas);

    bispo->peca.vpeca = &vtable_bispo;
}

// Construtor da rainha
void inicializar_rainha(Rainha *rainha, char * sentido, int casas) {

    inicializar_peca((Peca*)rainha, sentido, casas);

    rainha->peca.vpeca = &vtable_rainha;
}

//Método principal executável
void main(){

    //Declaração das variáveis de entrada do usuário
    char peca [20], sentido [20], sair[2];
    int casas;

    //Loop responsável pela entrada de dados, criação das instâncias e execução dos métodos.
    do
    {
        //Limpa a tela
        system("clear");

        //Limpa as variáveis
        strcpy(peca, "");
        strcpy(sentido, "");
        strcpy(sair, "");
        casas = 0;

        //Prompt de entrada para o usuário
        printf("Digite a peça que deseja mover (%s, %s, %s, %s para sair do programa.): \n", RAINHA, TORRE, BISPO, CAVALO);
        scanf(" %s", peca);
        printf("Digite o sentido da peça (%s, %s, %s, %s, %s, %s, %s, %s): \n", DIREITA, ESQUERDA, CIMA, BAIXO, CIMA_DIREITA, BAIXO_DIREITA , CIMA_ESQUERDA, BAIXO_ESQUERDA);
        scanf(" %s", sentido);
        printf("Digite a quantidade de casas (1-8): \n");
        scanf(" %i",&casas);

        //Testa número de casas. Só permite de 1 a 8, por causa do tamanho do tabuleiro de xadrez; 8x8
        if (casas < 1 || casas >8) {
            printf("Número inválido de casas para a peça percorrer.\n");
        } else {
            //Testa as peças, cria as instâncias de cada classe e executa o movimento de acordo com a condição.
            if (strcmp(peca, RAINHA) == 0) {
                //Declara o objeto peca
                Rainha rainha;
                inicializar_rainha(&rainha, sentido, casas);
                //Testa se o usuário digitou um movimento válido para a peça.
                if (!rainha.peca.vpeca->mover((Peca*)&rainha)) {
                    printf("Movimento inválido para a %s.\n", RAINHA);
                };
            } else if (strcmp(peca, TORRE) == 0) {
                //Declara o objeto peca
                Torre torre;
                inicializar_torre(&torre, sentido, casas);
                //Testa se o usuário digitou um movimento válido para a peça.
                if (!torre.peca.vpeca->mover((Peca*)&torre)) {
                    printf("Movimento inválido para a %s.\n", TORRE);
                };
            } else if (strcmp(peca, BISPO) == 0) {
                //Declara o objeto peca
                Bispo bispo;
                inicializar_bispo(&bispo, sentido, casas);
                //Testa se o usuário digitou um movimento válido para a peça.
                if (!bispo.peca.vpeca->mover((Peca*)&bispo)) {
                    printf("Movimento inválido para o %s.\n", BISPO);
                };
            } else {
                //Retorna mensagem se a peça não está presente na cadeia de condições acima.
                printf("Peça inexistente ou não implementada\n");
            }
        }


    printf("Deseja sair ? (S/N) \n");
    scanf(" %s",sair);

    } while (strcmp(sair, "S") != 0);
}
