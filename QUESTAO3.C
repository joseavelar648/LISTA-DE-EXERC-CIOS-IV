#include <stdio.h>
#include <string.h>

struct Aluno {
    char nome[50];
    int idade;
    float nota;
};

int main() {

    struct Aluno alunos[5] = {
        {"José Avelar", 22, 5.5},
        {"Maria Santos", 19, 9.2},
        {"Pedro Oliveira", 21, 7.8},
        {"Ana Costa", 18, 8.9},
        {"Lucas Pereira", 22, 6.5}
    };
    
    int indice;
    float nova_nota;
    
    printf("=== LISTA DE ALUNOS ===\n");
    for(int i = 0; i < 5; i++) {
        printf("\nÍndice %d:\n", i);
        printf("Nome: %s\n", alunos[i].nome);
        printf("Idade: %d anos\n", alunos[i].idade);
        printf("Nota: %.1f\n", alunos[i].nota);
        printf("--------------------\n");
    }
    
    printf("\nDigite o índice do aluno que deseja atualizar (0 a 4): ");
    scanf("%d", &indice);
    
    if(indice < 0 || indice >= 5) {
        printf("Erro: Índice inválido! Deve ser entre 0 e 4.\n");
        return 1;
    }
    
    printf("\n=== ALUNO SELECIONADO ===\n");
    printf("Nome: %s\n", alunos[indice].nome);
    printf("Idade: %d anos\n", alunos[indice].idade);
    printf("Nota atual: %.1f\n", alunos[indice].nota);
    
    printf("\nDigite a nova nota para %s: ", alunos[indice].nome);
    scanf("%f", &nova_nota);
    
    if(nova_nota < 0 || nova_nota > 10) {
        printf("Erro: Nota inválida! Deve ser entre 0 e 10.\n");
        return 1;
    }
    
    alunos[indice].nota = nova_nota;
    
    printf("\n=== DADOS ATUALIZADOS ===\n");
    printf("Nome: %s\n", alunos[indice].nome);
    printf("Idade: %d anos\n", alunos[indice].idade);
    printf("Nova nota: %.1f\n", alunos[indice].nota);
    
    return 0;
}
