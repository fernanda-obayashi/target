#include <stdio.h>
#include <stdlib.h>
#include "cJSON.h"

#define MAX_DIAS 31

int main() {
    int faturamento_diario[MAX_DIAS];
    int num_dias = 0;
    int i;
    int menor_valor, maior_valor;
    int total_faturamento = 0;
    int num_dias_acima_media = 0;
    float media_mensal;

    // Inicializa menor e maior valor com um valor muito grande e muito pequeno, respectivamente
    menor_valor = 1000000000;
    maior_valor = -1000000000;

    // Lê os dados do arquivo JSON e armazena no vetor
    FILE *arquivo = fopen("faturamento.json", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo\n");
        exit(1);
    }

    fseek(arquivo, 0, SEEK_END);
    long tamanho_arquivo = ftell(arquivo);
    fseek(arquivo, 0, SEEK_SET);

    char *buffer = (char *) malloc(tamanho_arquivo + 1);
    if (fread(buffer, 1, tamanho_arquivo, arquivo) != tamanho_arquivo) {
        printf("Erro ao ler arquivo\n");
        exit(1);
    }
    fclose(arquivo);

    cJSON *root = cJSON_Parse(buffer);
    if (root == NULL) {
        printf("Erro ao parsear JSON\n");
        exit(1);
    }

    cJSON *faturamento = cJSON_GetObjectItem(root, "faturamento");
    if (faturamento == NULL) {
        printf("Erro ao obter dados de faturamento\n");
        exit(1);
    }

    cJSON *dia = NULL;
    cJSON_ArrayForEach(dia, faturamento) {
        int valor = cJSON_GetObjectItem(dia, "valor")->valueint;
        faturamento_diario[num_dias] = valor;
        num_dias++;
    }

    // Encontra o menor e o maior valor de faturamento diário
    for (i = 0; i < num_dias; i++) {
        int faturamento = faturamento_diario[i];
        if (faturamento < menor_valor) {
            menor_valor = faturamento;
        }
        if (faturamento > maior_valor) {
            maior_valor = faturamento;
        }
        total_faturamento += faturamento;
    }

    // Calcula a média mensal e conta quantos dias tiveram faturamento diário acima da média
    media_mensal = (float) total_faturamento / num_dias;
    for (i = 0; i < num_dias; i++) {
        if (faturamento_diario[i] > media_mensal) {
            num_dias_acima_media++;
        }
    }

    // Libera a memória alocada pela cJSON e pelo buffer
    cJSON_Delete(root);
    free(buffer);

}

