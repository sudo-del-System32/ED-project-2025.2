#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "../Bibliotecas/garrafas.h"
#include "../Bibliotecas/cor.h"
 

bool vazia(garrafa *g)
{
    if(g->qnt != 0) return false; // False, esta vazia.

    return true; // True, não esta vazia.
}

bool cheia(garrafa *g)
{
    return g->qnt == MAX_SIZE;
}



char *pop(garrafa *g)
{
    if(vazia(g)){
         printf("A garrafa esta vazia!\n");
        return "\0";
    }

    g->qnt--;
    return g->cores[g->top--];
}

bool push(garrafa *g , char *cor){
 
    if(cheia(g)) return false;
 
    g->top++;
    g->qnt++;
    strcpy(g->cores[g->top],cor);
    
    return true;
}

void desenhar(garrafa g[3]) {
    printf("\n       ( 1 )            ( 2 )            ( 3 )\n");
    printf("       |   |            |   |            |   |\n");
    
    for (int nivel = 2; nivel >= 0; nivel--) {
        for (int i = 0; i < 3; i++) {
            printf("    |");
            if (nivel < g[i].qnt) {
                printf("%s", getColorCode(g[i].cores[nivel]));
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


