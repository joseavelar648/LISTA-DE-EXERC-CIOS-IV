#include <stdio.h>
#include <string.h>

#define MAX_ALUNOS 4
struct Aluno {
    char nome[50];
    int idade;
    float nota;
};

void exibirMenu();
void exibirAlunos(struct Aluno alunos[], int quantidade);
int criarAluno(struct Aluno alunos[], int quantidade);
int removerAluno(struct Aluno alunos[], int quantidade);

int main() {
    struct Aluno alunos[MAX_ALUNOS];
    int quantidade = 0;
    int opcao;
    
    do {
        exibirMenu();
        printf("\nDigite sua opção: ");
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1:
                exibirAlunos(alunos, quantidade);
                break;
            case 2:
                quantidade = criarAluno(alunos, quantidade);
                break;
            case 3:
                quantidade = removerAluno(alunos, quantidade);
                break;
            case 4:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
        
        if(opcao != 4) {
            printf("\nPressione Enter para continuar...");
            getchar();
            getchar();
        }
        
    } while(opcao != 4);
    
    return 0;
}

void exibirMenu() {
    printf("\n=== SISTEMA DE GERENCIAMENTO DE ALUNOS ===\n");
    printf("1. Exibir todos os alunos\n");
    printf("2. Criar novo aluno\n");
    printf("3. Remover aluno\n");
    printf("4. Sair\n");
}

void exibirAlunos(struct Aluno alunos[], int quantidade) {
    printf("\n=== LISTA DE ALUNOS ===\n");
    
    if(quantidade == 0) {
        printf("Nenhum aluno cadastrado.\n");
        return;
    }
    
    for(int i = 0; i < quantidade; i++) {
        printf("\n--- Aluno %d ---\n", i + 1);
        printf("Nome: %s\n", alunos[i].nome);
        printf("Idade: %d anos\n", alunos[i].idade);
        printf("Nota: %.1f\n", alunos[i].nota);
    }
    printf("\nTotal de alunos: %d/%d\n", quantidade, MAX_ALUNOS);
}

int criarAluno(struct Aluno alunos[], int quantidade) {
    printf("\n=== CRIAR NOVO ALUNO ===\n");
    
    if(quantidade >= MAX_ALUNOS) {
        printf("Erro: Limite máximo de %d alunos atingido!\n", MAX_ALUNOS);
        return quantidade;
    }
    
    getchar();
    
    printf("Digite o nome do aluno: ");
    fgets(alunos[quantidade].nome, 50, stdin);
    alunos[quantidade].nome[strcspn(alunos[quantidade].nome, "\n")] = '\0';
    

    printf("Digite a idade do aluno: ");
    scanf("%d", &alunos[quantidade].idade);
    
    printf("Digite a nota do aluno: ");
    scanf("%f", &alunos[quantidade].nota);
    
    if(alunos[quantidade].nota < 0 || alunos[quantidade].nota > 10) {
        printf("Erro: Nota deve estar entre 0 e 10!\n");
        return quantidade;
    }
    
    printf("\nAluno cadastrado com sucesso!\n");
    return quantidade + 1;
}

int removerAluno(struct Aluno alunos[], int quantidade) {
    printf("\n=== REMOVER ALUNO ===\n");
    
    if(quantidade == 0) {
        printf("Nenhum aluno cadastrado para remover.\n");
        return quantidade;
    }
    
    exibirAlunos(alunos, quantidade);
    
    int indice;
    printf("\nDigite o número do aluno que deseja remover (1 a %d): ", quantidade);
    scanf("%d", &indice);
    
    if(indice < 1 || indice > quantidade) {
        printf("Erro: Número de aluno inválido!\n");
        return quantidade;
    }
    
    getchar();
    

    char confirmacao;
    printf("Tem certeza que deseja remover %s? (s/n): ", alunos[indice-1].nome);
    scanf("%c", &confirmacao);
    
    if(confirmacao == 's' || confirmacao == 'S') {
        for(int i = indice - 1; i < quantidade - 1; i++) {
            strcpy(alunos[i].nome, alunos[i + 1].nome);
            alunos[i].idade = alunos[i + 1].idade;
            alunos[i].nota = alunos[i + 1].nota;
        }
        
        printf("Aluno removido com sucesso!\n");
        return quantidade - 1;
    } else {
        printf("Remoção cancelada.\n");
        return quantidade;
    }
}
