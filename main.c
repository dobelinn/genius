#include "push.h"
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

char resposta[999];
char vetor[999];
int contador = 0, aux = 1;
struct no *topo = NULL;

struct nome {
  char nome[20];
};

struct nome nome;
void empilhaAleatorios() {
  int i;
  for (i = 0; i < 1; i++) {
    vetor[i] = 97 + (char)(rand() % 26);
    push(vetor[i], &topo);
    contador = contador + 1;
  }
}

void MenuPrincipal() {
  int Opcao;
  char atual;
  int errar = 1, ver = 0, sair = 0, pontos = 0;
  do {
    printf("\n\n ------------Genius------------");
    printf("\n 1 - Jogar ");
    printf("\n 0 - Fechar Programa ");
    printf("\n\n Escolha uma opcao: ");
    scanf("%d", &Opcao);
    switch (Opcao) {
    case 0:
      system("cls");
      printf("ENCERRADO!");

      break;
    case 1:
      system("cls");
      printf("Digite seu nome: ");
      scanf(" %s", &nome.nome);
      system("cls");
      do {
        printf("\nDigite a proxima letra de A-Z: ");
        scanf("%s", &atual);
        push(atual, &topo);
        empilhaAleatorios();
        contador = contador - 1;
        vetor[contador + 1] = atual;
        aux++;
        printf("Proxima letra: %c. Voce tem 3 segundos para memorizar\n",
               vetor[contador]);
        Sleep(3000);
        system("cls");
        printf("Digite a sequencia: ");
        scanf("%s", resposta);
        for (int i = 0; i <= ver; i++) {
          if (vetor[i] != resposta[i]) {
            system("cls");
            printf("\nVoce perdeu!! %s \nSua pontuacao: %d", nome.nome, pontos);
            printf("\nSequencia correta: %s\n", vetor);
            system("pause");
            system("cls");
            MenuPrincipal();
          } else {
            system("cls");
            printf("Parabens %s! +10 pontos!\n", nome.nome);
            Sleep(3000);
            system("cls");
            pontos += 10;
          }
        }

      } while (contador <= 9);
      break;
    }
  } while (Opcao != 0);
}

int main() {
  MenuPrincipal();
  return 0;
}
