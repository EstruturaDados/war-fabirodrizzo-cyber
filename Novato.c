#include <stdio.h>

// Criando uma estrutura (struct) chamada Territorio
// Ela guarda o nome do território, a cor do exército e a quantidade de tropas
struct Territorio {
    char nome[30];
    char cor[10];
    int tropas;
};

int main() {
    struct Territorio territorios[5];  // Vetor para armazenar 5 territórios
    int i;

    printf("=== CADASTRO DE TERRITORIOS ===\n\n");

    // Laço para cadastrar 5 territórios
    for (i = 0; i < 5; i++) {
        printf("Território %d\n", i + 1);

        printf("Digite o nome do território: ");
        scanf("%s", territorios[i].nome);  // Lê o nome (sem espaços)

        printf("Digite a cor do exército: ");
        scanf("%s", territorios[i].cor);   // Lê a cor (sem espaços)

        printf("Digite a quantidade de tropas: ");
        scanf("%d", &territorios[i].tropas);  // Lê o número de tropas

        printf("\n");  // Pula uma linha
    }

    // Mostrando todos os territórios cadastrados
    printf("\n=== TERRITORIOS CADASTRADOS ===\n\n");

    for (i = 0; i < 5; i++) {
        printf("Território %d:\n", i + 1);
        printf("Nome: %s\n", territorios[i].nome);
        printf("Cor do exército: %s\n", territorios[i].cor);
        printf("Quantidade de tropas: %d\n", territorios[i].tropas);
        printf("-------------------------------\n");
    }

    return 0;
}