#include <stdio.h>

void main() {

    int index;

    char *nomeAlunos[3][3] = {
        {"Aluno 0", "Pt: 30","Mat: 50"},
        {"Aluno 1", "Pt: 60","Mat: 60"},
        {"Aluno 2", "Pt: 90","Mat: 300"}
    };
    
    printf("Digite o numero do aluno que queira vear as notas...\n");
    printf("Para o aluno 0 digite 0\n");
    printf("Para o aluno 1 digite 0\n");
    printf("Para o aluno 2 digite 0\n");

    scanf("%i", &index);

    printf("A nota do %s é %s, e %s\n0", nomeAlunos[index][0], nomeAlunos[index][1], nomeAlunos[index][2]);
    
}