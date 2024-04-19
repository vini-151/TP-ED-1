#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NOME_TAM 60
#define CELULAR_TAM 15
#define CURSO_TAM 30

struct aluno {
    char nome[NOME_TAM];
    char telefone[CELULAR_TAM];
    char curso[CURSO_TAM];
    float nota1;
    float nota2;
};

const char* passouMedia(float media);

int main(void) {
    FILE *entrada, *saida;
    entrada = fopen("DadosEntrada.csv", "r");
    saida = fopen("DadosSaida.csv", "w");

    if (entrada != NULL && saida != NULL) {
        struct aluno x;
        char line[256]; 
        while (fgets(line, sizeof(line), entrada)) {
            sscanf(line, "%59[^,],%14[^,],%29[^,],%f,%f", x.nome, x.telefone, x.curso, &x.nota1, &x.nota2);
            printf("%s", line);
            if(strcmp(line, "Nome,Telefone,Curso,Nota1,Nota2\n") == 0){
                fprintf(saida, "Nome,media,situacao\n");
            }else{
                float valorDaMedia = (x.nota1 + x.nota2) / 2;
                if (valorDaMedia < 0 || valorDaMedia > 10) {
                    printf("Erro: média inválida para o aluno %s\n", x.nome);
                    continue; 
                }
                const char *situacao = passouMedia(valorDaMedia);
                fprintf(saida, "%s,%.2f,%s\n", x.nome, valorDaMedia, situacao);
            }
        }
        fclose(entrada);
        fclose(saida);
        printf("Arquivo 'DadosSaida.csv' criado com sucesso.\n");
    } else {
        printf("Erro ao abrir os arquivos.\n");
        exit(1);
    }

    return 0;
}

const char* passouMedia(float media) {
    return (media >= 7.0) ? "APROVADO" : "REPROVADO";
}
