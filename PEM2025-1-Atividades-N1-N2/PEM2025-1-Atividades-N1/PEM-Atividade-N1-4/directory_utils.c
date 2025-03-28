/*-------------------------------------------------------*
*                      FATEC Ipiranga                    *
* Disciplina: Programaçao Estruturada e Modular          *
*          Prof. Veríssimo                               *
*--------------------------------------------------------*
* Objetivo do Programa:Implementação do codigo           *
* Data -    27/03/2025                                   *
* Autor: Matheus Rodrigues Frigola                       *
*--------------------------------------------------------*/
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/types.h>
#include "directory_utils.h"

void explore_directory(const char *path, int depth) {
    struct dirent *entry;
    DIR *dir = opendir(path);
    
    if (dir == NULL) {
        printf("Erro ao abrir diretório: %s\n", path);
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Exibir a hierarquia com recuo
        for (int i = 0; i < depth; i++) {
            printf("  ");
        }
        printf("|-- %s\n", entry->d_name);

        // Se for diretório, chamar recursivamente
        if (entry->d_type == DT_DIR) {
            char new_path[1024];
            snprintf(new_path, sizeof(new_path), "%s/%s", path, entry->d_name);
            explore_directory(new_path, depth + 1);
        }
    }
    closedir(dir);
}
