#include <stdio.h>
#include <string.h>

int main(){
//case sensitive
    int idade = 55;
    int quantidade;
    float altura=1.84;
    double soma;
    char opcao = 'S';
    char nome[20];
    int _teste;

    //Para Strings não há necessidade do &
    printf("%s\n","Escreva seu nome");
    /*
    Expressão regula foi utilizada porque espaço é entendido como quebra de linha. Então nada aparece após o espaço.
    Se quisermos limitar o tamanho da string, podemos limitá-la antes do conjunto de caracteres a ler. 
    Neste exemplo, vamos ler uma string com 60 caracteres no máximo: %60[^\n].    
    */

    scanf("%[^\n]", nome);
    printf("O nome digitado é: %s\n",nome);


    printf("A idade do %s é %d\n", nome, idade);
    printf("A idade do %s é %i\n", nome, idade);
    printf("A altura do %s é %f\n", nome, altura);
    printf("A altura do %s é %e\n", nome, altura);
    printf("A opcao do %s é %c\n", nome, opcao);

    printf("%s\n","Escreva sua altura");
    scanf("%f",&altura);
    printf("A altura digitada é: %f\n",altura);

    

    printf("%s\n","Escreva sua idade");
    scanf("%d",&idade);
    printf("A idade digitada é: %d\n",idade);


}