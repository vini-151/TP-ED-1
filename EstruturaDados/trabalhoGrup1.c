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

const char* passouMedia(float media) {
    if (media >= 7.0) {
        return "APROVADO";
    } else {
        return "REPROVADO";
    }
}

int main(void) {
    FILE *entrada, *saida;
    entrada = fopen("DadosEntrada.csv", "r");
    saida = fopen("DadosSaida.csv", "w");

    if (entrada != NULL && saida != NULL) {
        struct aluno x;
        while (fscanf(entrada, "%s,%s,%s,%f,%f", x.nome, x.telefone, x.curso, &x.nota1, &x.nota2) != EOF) {
            float valorDaMedia = (x.nota1 + x.nota2) / 2;
            const char *situacao = passouMedia(valorDaMedia);
            fprintf(saida, "%s,%.2f,%s\n", x.nome, valorDaMedia, situacao);
        }
        fclose(entrada);
        fclose(saida);
        printf("Arquivo 'DadosSaida.csv' foi criado\n");
    } else {
        printf("Erro ao abrir os arquivos.\n");
        exit(1);
    }

    return 0;
}
