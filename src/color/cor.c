#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../Bibliotecas/garrafas.h"
#include "../Bibliotecas/cor.h"


const char* conseguirCor(const char* nome_cor) {
    if (strcmp(nome_cor, "verde") == 0) return VERDE;
    if (strcmp(nome_cor, "azul") == 0) return AZUL;
    if (strcmp(nome_cor, "amarelo") == 0) return AMARELO;
    return RESET; 
}


void printfVezes(const char *str, int numVezes)
{
    for(int i = 0; i <= numVezes - 1; i++) printf("%s",str);
}

void printfVezesENumMuda(const char *str, int numVezes)
{
    for(int i = 0; i <= numVezes - 1; i++) printf("            ( %d )",i);
}

//refactor essa funçao
void desenhar(garrafa s[]) 
{
    garrafa g[NUM_DE_PILHAS];
    for(int i = 0; i < NUM_DE_PILHAS; i++)
    {
        copiarPilha(&g[i], &s[i]);
    }


    for(int i = 1; i <= NUM_DE_PILHAS; i++) printf("            ( %d )",i);
    printf("\n");
    printfVezes("            |   |", NUM_DE_PILHAS);
    printf("\n");
    for (int nivel = MAX_SIZE; nivel >= 1; nivel--) {
        printf("         ");
        for (int i = 0; i < NUM_DE_PILHAS; i++) {
            printf("|");
            if (g[i].top + 1 == nivel) {
                const char *cor = pop(&g[i]);
                int tamDaCor = strlen(cor);
                printfVezes(" ", (9 - tamDaCor) / 2);
                printf("%s", cor);
                printfVezes(" ", 9 - tamDaCor - (9 - tamDaCor) / 2);
            } 
            else {
                printf("         "); 
            }
            printf("|      ");
        }
        printf("\n         ");
        printfVezes("'---------'      ", NUM_DE_PILHAS);
        printf("\n");
    }

}
/*
void desenhar(garrafa g[3]) {
    printf("\n       ( 1 )            ( 2 )            ( 3 )\n");
    printf("       |   |            |   |            |   |\n");
    
    for (int nivel = 2; nivel >= 0; nivel--) {
        for (int i = 0; i < 3; i++) {
            printf("    |");
            if (nivel < g[i].qnt) {
                printf("%s", conseguirCor(g[i].cores[nivel]));
                int espacos_antes = (9 - strlen(g[i].cores[nivel])) / 2;
                int espacos_depois = 9 - strlen(g[i].cores[nivel]) - espacos_antes;
                for (int e = 0; e < espacos_antes; e++) printf(" ");
                printf("%s", g[i].cores[nivel]);
                for (int e = 0; e < espacos_depois; e++) printf(" ");
                printf("%s", RESET);
            } else {
                printf("         "); 
            }
            printf("|  ");
        }
        printf("\n");
        printf("    '---------'      '---------'      '---------'\n");
    }
}
*/
