#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
char nome[30];
char cor[10];
int tropas;
} Territorio;

void atribuirMissao(char *destino, char *missoes[], int totalMissoes) {
int indice = rand() % totalMissoes;
strcpy(destino, missoes[indice]);
}

void exibirMissao(char *missao) {
printf("\n=== SUA MISSÃO SECRETA ===\n%s\n\n", missao);
}

void atacar(Territorio *atacante, Territorio *defensor) {
printf("\n>>> ATAQUE DE %s (%s) CONTRA %s (%s)\n", atacante->nome, atacante->cor, defensor->nome, defensor->cor);
if (strcmp(atacante->cor, defensor->cor) == 0) {
printf("Não é possível atacar um território do mesmo exército!\n");
return;
}
if (atacante->tropas <= 1) {
printf("O território atacante precisa ter mais de 1 tropa!\n");
return;
}
int dadoAtacante = rand() % 6 + 1;
int dadoDefensor = rand() % 6 + 1;
printf("Dado atacante: %d | Dado defensor: %d\n", dadoAtacante, dadoDefensor);
if (dadoAtacante > dadoDefensor) {
printf(">>> O atacante venceu!\n");
strcpy(defensor->cor, atacante->cor);
defensor->tropas = atacante->tropas / 2;
atacante->tropas = atacante->tropas / 2;
} else {
printf(">>> O defensor resistiu!\n");
atacante->tropas -= 1;
}
printf("Após o ataque:\n");
printf("%s - Tropas: %d | Cor: %s\n", atacante->nome, atacante->tropas, atacante->cor);
printf("%s - Tropas: %d | Cor: %s\n", defensor->nome, defensor->tropas, defensor->cor);
}

int verificarMissao(char *missao, Territorio *mapa, int tamanho) {
if (strstr(missao, "3 territórios")) {
for (int i = 0; i < tamanho; i++) {
int cont = 1;
for (int j = i + 1; j < tamanho; j++) {
if (strcmp(mapa[i].cor, mapa[j].cor) == 0)
cont++;
}
if (cont >= 3) return 1;
}
}
if (strstr(missao, "4 territórios")) {
int cont = 0;
for (int i = 0; i < tamanho; i++) {
if (mapa[i].tropas > 3) cont++;
}
if (cont >= 4) return 1;
}
return 0;
}

void liberarMemoria(Territorio *territorios, char *missaoJogador) {
free(territorios);
free(missaoJogador);
printf("\nMemória liberada com sucesso!\n");
}

int main() {
srand(time(NULL));
}
