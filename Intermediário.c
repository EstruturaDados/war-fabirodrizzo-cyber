#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>   // <- Adicione esta linha para strcmp e strcpy

// Criando uma estrutura (struct) chamada Territorio
// Ela guarda o nome do território, a cor do exército e a quantidade de tropas
struct Territorio {
    char nome[30];
    char cor[10];
    int tropas;
};

// Função que simula o ataque entre dois territórios
void atacar(struct Territorio *atacante, struct Territorio *defensor) {
    printf("\n>>> Ataque de %s (%s) contra %s (%s)\n",
           atacante->nome, atacante->cor, defensor->nome, defensor->cor);

    // Verifica se o jogador está tentando atacar um território da mesma cor
    if (strcmp(atacante->cor, defensor->cor) == 0) {
        printf("Não é possível atacar um território do mesmo exército!\n");
        return;
    }

    // Verifica se há tropas suficientes
    if (atacante->tropas <= 1) {
        printf("O território atacante precisa ter mais de 1 tropa para atacar!\n");
        return;
    }

    // Simulação dos dados (valores aleatórios entre 1 e 6)
    int dadoAtacante = rand() % 6 + 1;
    int dadoDefensor = rand() % 6 + 1;

    printf("Dado do atacante: %d | Dado do defensor: %d\n", dadoAtacante, dadoDefensor);

    // Resultado do ataque
    if (dadoAtacante > dadoDefensor) {
        printf(">>> O atacante venceu a batalha!\n");
        // O defensor muda de cor e recebe metade das tropas do atacante
        strcpy(defensor->cor, atacante->cor);
        defensor->tropas = atacante->tropas / 2;
        atacante->tropas = atacante->tropas / 2;
        printf("%s agora pertence ao exército %s!\n", defensor->nome, defensor->cor);
    } else {
        printf(">>> O defensor resistiu ao ataque!\n");
        atacante->tropas -= 1; // atacante perde uma tropa
    }

    // Exibe o resultado atualizado
    printf("\nApós o ataque:\n");
    printf("%s - Tropas: %d | Cor: %s\n", atacante->nome, atacante->tropas, atacante->cor);
    printf("%s - Tropas: %d | Cor: %s\n", defensor->nome, defensor->tropas, defensor->cor);
}

int main() {
    srand(time(NULL)); // Garante números aleatórios diferentes a cada execução

    struct Territorio *territorios;  // Ponteiro para armazenar os territórios
    int qtd, i;

    printf("Quantos territórios deseja cadastrar? ");
    scanf("%d", &qtd);
    getchar(); // limpa o ENTER

    // Alocação dinâmica com malloc
    territorios = (struct Territorio *)malloc(qtd * sizeof(struct Territorio));

    printf("\n=== CADASTRO DE TERRITÓRIOS ===\n\n");

    // Cadastro dos territórios
    for (i = 0; i < qtd; i++) {
        printf("Território %d\n", i + 1);

        printf("Digite o nome do território: ");
        scanf("%s", territorios[i].nome);  // lê nome sem espaços

        printf("Digite a cor do exército: ");
        scanf("%s", territorios[i].cor);

        printf("Digite a quantidade de tropas: ");
        scanf("%d", &territorios[i].tropas);

        printf("\n");
    }

    // Mostrando todos os territórios cadastrados
    printf("\n=== TERRITÓRIOS CADASTRADOS ===\n\n");
    for (i = 0; i < qtd; i++) {
        printf("%d - Nome: %s | Cor: %s | Tropas: %d\n",
               i + 1, territorios[i].nome, territorios[i].cor, territorios[i].tropas);
    }

    // Escolha dos territórios para ataque
    int atacante, defensor;
    printf("\nEscolha o número do território atacante: ");
    scanf("%d", &atacante);
    printf("Escolha o número do território defensor: ");
    scanf("%d", &defensor);

    // Ajustando para índices do vetor (começa do 0)
    atacante--;
    defensor--;

    // Executando o ataque
    atacar(&territorios[atacante], &territorios[defensor]);

    // Exibindo resultado final
    printf("\n=== SITUAÇÃO FINAL DOS TERRITÓRIOS ===\n");
    for (i = 0; i < qtd; i++) {
        printf("%d - Nome: %s | Cor: %s | Tropas: %d\n",
               i + 1, territorios[i].nome, territorios[i].cor, territorios[i].tropas);
    }

    // Liberando memória
    free(territorios);
    printf("\nMemória liberada. Programa encerrado.\n");

    return 0;
}
