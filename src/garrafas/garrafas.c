#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../Bibliotecas/garrafas.h"
 

bool vazia(garrafa *g)
{
    if(s->qnt != 0) return false; // False, esta vazia.

    return true; // True, não esta vazia.
}

bool cheia(garrafa *g)
{
    return s->qnt == MAX_SIZE;
}



char *pop(garrafa *g)
{
    if(vazia(s)){
         printf("A garrafa esta vazia!\n");
        return "\0";
    }

    s->qnt--;
    return s->cores[s->top--];
}

bool push(garrafa *g , char *cor){
    if(cheia) return false;
    g->top++;
    strcpy(g->cores[s->top],cor);
    g->qnt++;
    return true;
}




