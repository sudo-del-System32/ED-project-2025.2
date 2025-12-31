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
    if (strcmp(nome_cor, "vermelho") == 0) return VERMELHO;
    if (strcmp(nome_cor, "rosa") == 0) return ROSA;
    if (strcmp(nome_cor, "ciano") == 0) return CIANO;
    return RESET; 
}


void printfVezes(const char *str, int numVezes)
{
    for(int i = 0; i <= numVezes - 1; i++) printf("%s",str);
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
