/*-------------------------------------------------------*
*                      FATEC Ipiranga                    *
* Disciplina: Programaçao Estruturada e Modular          *
*          Prof. Veríssimo                               *
*--------------------------------------------------------*
* Objetivo do Programa:ordenar numeros com insertionsort *
* Data -    11/05/2025                                   *
* Autor: Matheus Rodrigues Frigola                       *
*--------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

void ordenacaoInsercao(int arr[], int n) {
    int i, chave, j;
    
    for (i = 1; i < n; i++) {
        chave = arr[i];
        j = i - 1;
        
        while (j >= 0 && arr[j] > chave) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = chave;
    }
}

int main() {
    int n, i;
    int *arr;
    
    printf("Digite o número de elementos que você quer ordenar: ");
    scanf("%d", &n);
    
    arr = (int*) malloc(n * sizeof(int));
    
    if (arr == NULL) {
        printf("Falha na alocação de memória.\n");
        return 1;
    }

    printf("Digite os %d elementos:\n", n);
    for (i = 0; i < n; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    
    ordenacaoInsercao(arr, n);
    
    printf("Array ordenado: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    
    return 0;
}
