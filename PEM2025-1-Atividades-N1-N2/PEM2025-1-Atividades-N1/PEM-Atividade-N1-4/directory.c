/*-------------------------------------------------------*
*                      FATEC Ipiranga                    *
* Disciplina: Programaçao Estruturada e Modular          *
*          Prof. Veríssimo                               *
*--------------------------------------------------------*
* Objetivo do Programa:Implementação do codigo           *
* Data -    27/03/2025                                   *
* Autor: Matheus Rodrigues Frigola                       *
*--------------------------------------------------------*/
#include <windows.h>
#include <stdio.h>

void ListDirectoryContents(const char *sDir, int level, int *num_diretorios, int *num_arquivos)
{
    WIN32_FIND_DATA findFileData;
    HANDLE hFind;
    char path[MAX_PATH];

    snprintf(path, MAX_PATH, "%s\\*", sDir);
    hFind = FindFirstFile(path, &findFileData);

    if (hFind == INVALID_HANDLE_VALUE) {
        printf("Erro ao acessar o diretório: %s\n", sDir);
        return;
    }

    do {
        if (strcmp(findFileData.cFileName, ".") != 0 && strcmp(findFileData.cFileName, "..") != 0) {
            for (int i = 0; i < level; i++)
                printf("  ");

            printf("|-- %s", findFileData.cFileName);

            if (findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
                printf(" [PASTA]\n");
                (*num_diretorios)++;
                snprintf(path, MAX_PATH, "%s\\%s", sDir, findFileData.cFileName);
                ListDirectoryContents(path, level + 1, num_diretorios, num_arquivos);
            }
            else {
                printf(" [ARQUIVO]\n");
                (*num_arquivos)++;
            }
        }
    } while (FindNextFile(hFind, &findFileData));

    FindClose(hFind);

    if (level == 0) {
        printf("\n[->] Total de arquivos: %d\n", *num_arquivos);
        printf("[->] Total de diretorios: %d\n", *num_diretorios);
    }
}

int main(int argc, char *argv[]) {
    char diretorio_inicial[MAX_PATH];
    int num_diretorios = 0;
    int num_arquivos = 0;

    if (argc > 1) {
        snprintf(diretorio_inicial, MAX_PATH, "%s", argv[1]);
    }
    else {
        puts("[->] Digite o caminho do diretório:");
        scanf("%s", diretorio_inicial);
    }

    printf("\nExplorando diretório: %s\n\n", diretorio_inicial);
    ListDirectoryContents(diretorio_inicial, 0, &num_diretorios, &num_arquivos);
    return 0;
}