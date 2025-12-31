#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../Bibliotecas/garrafas.h"
 

bool vazia(garrafa *g)
{
    if(g->qnt != 0) return false; // False, esta vazia.

    return true; // True, não esta vazia.
}

bool cheia(garrafa *g)
{
    return g->qnt == MAX_SIZE;
}

void inicializar(garrafa *g) 
{
    g->top = -1;
    g->qnt = 0;
}



bool push(garrafa *g , char cor[])
{
 
    if(cheia(g)) return false;
 
    g->top++;
    g->qnt++;
    strcpy(g->cores[g->top],cor);
    
    return true;
}



char *pop(garrafa *g)
{
    if(vazia(g)){
        return "\0"; 
    }    

    g->qnt--;
    return g->cores[g->top--];
}    


bool tranferirCor(garrafa *g, garrafa *s)
{
    return push(g, pop(s));
}