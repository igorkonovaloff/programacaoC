#include <stdio.h>

int main(){

    unsigned int numero_1, resto;

    printf("Digite o número: \n");
    scanf("%i", &numero_1);

    resto = numero_1 % 2;

    if (numero_1 == 0){
        printf("Número 0 não é nem par nem ímpar");
        return 0;
    }

    if (resto == 0) {
        printf("Número %d é par \n",  numero_1);
    } else {
        printf("Número %d é ímpar \n", numero_1);
    }

    return 0;
}


