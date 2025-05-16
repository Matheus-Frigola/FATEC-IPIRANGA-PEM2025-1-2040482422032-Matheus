/*-------------------------------------------------------*
*                      FATEC Ipiranga                    *
* Disciplina: Programaçao Estruturada e Modular          *
*          Prof. Veríssimo                               *
*--------------------------------------------------------*
* Objetivo do Programa:ordenar numeros com bubblesort    *
* Data -    11/05/2025                                   *
* Autor: Matheus Rodrigues Frigola                       *
*--------------------------------------------------------*/

#include <stdio.h>

void bubbleSort(int *arr, int tamanho) {
    int temp;
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void imprimirArray(int *arr, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int tamanho;

    printf("Digite o número de elementos: ");
    scanf("%d", &tamanho);

    if (tamanho <= 0) {
        printf("Tamanho inválido. Encerrando...\n");
        return 1;
    }

    int arr[tamanho];

    printf("Digite os %d elementos:\n", tamanho);
    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Array original: ");
    imprimirArray(arr, tamanho);

    bubbleSort(arr, tamanho);

    printf("Array ordenado: ");
    imprimirArray(arr, tamanho);

    return 0;
}
