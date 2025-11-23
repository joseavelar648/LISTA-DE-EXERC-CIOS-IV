#include <stdio.h>
#include <string.h>

struct Aluno {
    char nome[50];
    int idade;
    float nota;
};

int main() {
    struct Aluno alunos[5];
    
    printf("=== CADASTRO DE ALUNOS ===\n");
    
    for(int i = 0; i < 5; i++) {
        printf("\n--- Aluno %d ---\n", i + 1);
        
        printf("Digite o nome do aluno: ");
        fgets(alunos[i].nome, 50, stdin);
        alunos[i].nome[strcspn(alunos[i].nome, "\n")] = '\0';
        
        printf("Digite a idade do aluno: ");
        scanf("%d", &alunos[i].idade);
        
 
        printf("Digite a nota do aluno: ");
        scanf("%f", &alunos[i].nota);
        
        getchar();
    }
    
    printf("\n=== LISTA COMPLETA DE ALUNOS ===\n");
    for(int i = 0; i < 5; i++) {
        printf("\n--- Aluno %d ---\n", i + 1);
        printf("Nome: %s\n", alunos[i].nome);
        printf("Idade: %d anos\n", alunos[i].idade);
        printf("Nota: %.1f\n", alunos[i].nota);
    }
    
    return 0;
}
