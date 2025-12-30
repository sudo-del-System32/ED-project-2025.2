#include <stdio.h>
#include <stdbool.h>

#include "../Bibliotecas/garrafas.h"

bool vazia(garrafa *s)
{
    if(s->qnt != 0) return false; // False, esta vazia.

    return true; // True, não esta vazia.
}


char pop(garrafa *s)
{
    if(vazia(s)){
         printf("A garrafa esta vazia!\n");
        return '\0';
    }
    s->qnt--;
    return s->cores[s->top--];
}
