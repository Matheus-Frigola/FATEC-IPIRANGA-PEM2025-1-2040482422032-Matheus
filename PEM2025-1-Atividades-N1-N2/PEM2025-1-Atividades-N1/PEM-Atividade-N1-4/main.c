/*-------------------------------------------------------*
*                      FATEC Ipiranga                    *
* Disciplina: Programaçao Estruturada e Modular          *
*          Prof. Veríssimo                               *
*--------------------------------------------------------*
* Objetivo do Programa:Ponto de entrada                  *
* Data -    27/03/2025                                   *
* Autor: Matheus Rodrigues Frigola                       *
*--------------------------------------------------------*/
#include <stdio.h>
#include "directory_utils.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Uso: %s <diretório>\n", argv[0]);
        return 1;
    }

    printf("Estrutura de Diretórios de: %s\n", argv[1]);
    explore_directory(argv[1], 0);
    
    return 0;
}
