#include <stdio.h>
#include <stdbool.h>

#include "../Bibliotecas/garrafas.h"

#define MAX_SIZE 3;

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




