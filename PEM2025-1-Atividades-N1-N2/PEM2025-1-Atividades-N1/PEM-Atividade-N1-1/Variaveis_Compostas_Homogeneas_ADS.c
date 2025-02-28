/*-------------------------------------------------------*
*                      FATEC Ipiranga                    *
* Disciplina: Programaçao Estruturada e Modular          *
*          Prof. Veríssimo                               *
*--------------------------------------------------------*
* Objetivo do Programa:selecionar Residentes de medicina *
* Data - 27/02/2025                                      * 
* Autor: Matheus Rodrigues Frigola                       *
*--------------------------------------------------------*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CANDIDATOS 50
#define TOP_CANDIDATOS 15

void ordenar(float *notas, int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (notas[j] > notas[j + 1]) {
                float temp = notas[j];
                notas[j] = notas[j + 1];
                notas[j + 1] = temp;
            }
        }
    }
}

float calcularMediaCentral(float *notas, int tamanho) {
    ordenar(notas, tamanho);
    float soma = 0;
    for (int i = 1; i < tamanho - 1; i++) {
        soma += notas[i];
    }
    return soma / (tamanho - 2);
}

void obterNotas(float *notas, int tamanho, const char *descricao) {
    printf("Digite as notas de %s (%d notas):\n", descricao, tamanho);
    for (int i = 0; i < tamanho; i++) {
        scanf("%f", &notas[i]);
    }
}

int main() {
    int n;
    char nomes[MAX_CANDIDATOS][100];
    float notasPE[MAX_CANDIDATOS][4], notasAC[MAX_CANDIDATOS][5], notasPP[MAX_CANDIDATOS][10], notasEB[MAX_CANDIDATOS][3];
    float notasFinais[MAX_CANDIDATOS];
    
    printf("Digite o número de candidatos (máximo %d): ", MAX_CANDIDATOS);
    scanf("%d", &n);
    
    if (n > MAX_CANDIDATOS) {
        printf("O número máximo de candidatos é %d!\n", MAX_CANDIDATOS);
        return 1;
    }
    
    for (int i = 0; i < n; i++) {
        printf("\nCandidato %d:\n", i + 1);
        printf("Digite o nome do candidato: ");
        getchar(); // Limpar buffer do teclado
        fgets(nomes[i], sizeof(nomes[i]), stdin);
        nomes[i][strcspn(nomes[i], "\n")] = 0; // Remover nova linha
        
        obterNotas(notasPE[i], 4, "Prova Escrita");
        obterNotas(notasAC[i], 5, "Análise Curricular");
        obterNotas(notasPP[i], 10, "Prova Prática");
        obterNotas(notasEB[i], 3, "Entrevista");
        
        float mediaPE = calcularMediaCentral(notasPE[i], 4);
        float mediaAC = calcularMediaCentral(notasAC[i], 5);
        float mediaPP = calcularMediaCentral(notasPP[i], 10);
        float mediaEB = calcularMediaCentral(notasEB[i], 3);
        
        notasFinais[i] = (mediaPE * 0.3) + (mediaAC * 0.1) + (mediaPP * 0.4) + (mediaEB * 0.2);
    }
    
    // Ordenar candidatos por nota final (Bubble Sort)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (notasFinais[j] < notasFinais[j + 1]) {
                // Trocar notas
                float tempNota = notasFinais[j];
                notasFinais[j] = notasFinais[j + 1];
                notasFinais[j + 1] = tempNota;
                
                // Trocar nomes
                char tempNome[100];
                strcpy(tempNome, nomes[j]);
                strcpy(nomes[j], nomes[j + 1]);
                strcpy(nomes[j + 1], tempNome);
            }
        }
    }
    
    printf("\nClassificação dos 15 melhores candidatos:\n");
    for (int i = 0; i < (n < TOP_CANDIDATOS ? n : TOP_CANDIDATOS); i++) {
        printf("%d. %s - Nota Final: %.2f\n", i + 1, nomes[i], notasFinais[i]);
    }
    
    return 0;
}
