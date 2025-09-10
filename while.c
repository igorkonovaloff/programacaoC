#include <stdio.h>

void loop_while(int num) {
    printf("Digite um número (negativo para sair): \n");
    scanf("%d", &num);
        
    while (num >= 0) {
        printf("Você digitou: %d\n", num);
       
        printf("Digite um número (negativo para sair): \n");
        scanf("%d", &num);
    }
}


void loop_do_while(int num) {

    do {
        printf("Digite um número (negativo para sair): \n");
        scanf("%d", &num);
        printf("Você digitou: %d\n", num);
    } while (num >= 0); 
}

int menu() {
    int option;    
    do {
        printf("Menu:\n");
        printf("1. Opção 1\n");
        printf("2. Opção 2\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: \n");
        scanf("%d", &option);
       
        switch(option) {
            case 1:
                printf("Você escolheu a opção 1\n");
                break;
            case 2:
                printf("Você escolheu a opção 2\n");
                break;
            case 3:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (option != 3);   
}

int main() {
    int num;

    printf("ESTRUTURA WHILE \n");
    loop_while(num);
   
    printf("ESTRUTURA DO WHILE \n");
    loop_do_while(num);

    printf("MENU \n");
    menu();

    return 0;
}

