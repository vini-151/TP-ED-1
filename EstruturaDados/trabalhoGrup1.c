#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aluno{
    char nome[60];
    char telefone[15];
    char curso[30];
    float nota1;
    float nota2;
 };

int main(void) {
  FILE *fp;
  fp = fopen("DadosEntrada.csv", "r");

  if (fp != NULL) {
    struct aluno x;
    float valorDaMedia = 0.0;
    int i = 0;
    while (fscanf(fp, "%s,%s,%s,%f,%f", x.nome, x.telefone, x.curso, &x.nota1, &x.nota2) != EOF) {
      float valorDaMedia = x.nota1 + x.nota2 / 2;
      printf("%s,%s,%s,%f,%f", x.nome, x.telefone, x.curso, x.nota1, x.nota2);
    }

    printf("Valor total: R$ %.2f", valorDaMedia);

  } else {
    printf("Erro ao abrir o arquivo");
    exit(1);
  }

  return 0;
}