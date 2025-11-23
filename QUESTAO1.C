#include <stdio.h>
#include <string.h>

struct Aluno {
    char nome[50];
    int idade;
    float nota;
};

int main() {
    struct Aluno aluno1 = {
        "José Avelar", 
        22,           
        5.5           
    };
    

    printf("=== DADOS DO ALUNO ===\n");
    printf("Nome: %s\n", aluno1.nome);
    printf("Idade: %d anos\n", aluno1.idade);
    printf("Nota: %.1f\n", aluno1.nota);
    
    return 0;
}
