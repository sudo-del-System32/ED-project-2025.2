#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "src/Bibliotecas/useful.h"


#include "src/Bibliotecas/garrafas.h"
#include "src/Bibliotecas/menu.h"

void inserirValores(garrafa *g);


int main()
{  
    do{
    printf("\nINFORME O NUMERO DE GARRAFAS QUE DESEJA(entre 3 e 7): \n");
    printf(">>  ");

    scanf("%d", &NUM_DE_PILHAS);
    MAX_SIZE = (NUM_DE_PILHAS - 1);
    }while(NUM_DE_PILHAS < 3 || NUM_DE_PILHAS > MAX_NUM_DE_PILHAS);

    garrafa g[NUM_DE_PILHAS];
    
    for(int i = 0; i < NUM_DE_PILHAS; i++){
        inicializar(&g[i]);
    }
    
    inserirValores(g);
    
    gameMenu(g);
    
    printf("GANHOU🎉🎉\n");
    return 0;
}


void inserirValores(garrafa *g)
{
    for(int i = 0; i < NUM_DE_PILHAS - 1; i++)
    {
        push(g + i, "azul");
        push(g + i, "amarelo");
        push(g + i, "verde");
        push(g + i, "vermelho");
        push(g + i, "rosa");
        push(g + i, "ciano");
        (g + i)->qnt = MAX_SIZE;    
        (g + i)->top = MAX_SIZE - 1;    
    }

    (g + NUM_DE_PILHAS)->qnt = 0;    
    (g + NUM_DE_PILHAS)->top = -1;    
    
}


