#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../Bibliotecas/garrafas.h"
 
int NUM_DE_PILHAS, MAX_SIZE;

bool vazia(garrafa *g)
{
    if(g->qnt != 0) return false; // False, não esta vazia.

    return true; // True, esta vazia.
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


void push(garrafa *g , char cor[])
{
    if(cheia(g)) return;
 
    g->top++;
    g->qnt++;
    strcpy(g->cores[g->top],cor);
    
}


char *pop(garrafa *g)
{
    if(vazia(g)){
        return "\0"; 
    }    

    g->qnt--;
    return g->cores[g->top--];
}    



char *peak(garrafa *g)
{
    return g->cores[g->top];
}



void tranferirCor(garrafa *g, garrafa *s)
{
    return push(g, pop(s));
}

void copiarPilha(garrafa *g, garrafa *s)
{
    int qnt = s->qnt;
    g->qnt = 0;
    g->top = -1;
    
    char cor[s->qnt][255];

    for(int i = 0; i < qnt; i++)
    {
        strcpy(cor[i], pop(s));
    }
    
    for(int i = qnt - 1; i >= 0; i--)
    {
        push(g, cor[i]);
        push(s, cor[i]);
    }
}

bool itensIguais(garrafa *g)
{
    if(cheia(g) != true && vazia(g) != true) return false;

    garrafa h;
    copiarPilha(&h, g);
    char *cor = peak(g);
    while(strcmp(cor, pop(&h)) ==  0)
    {
        if(vazia(&h)) return true;
    }

    return false;
}