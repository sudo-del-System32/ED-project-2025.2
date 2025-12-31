#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "src/Bibliotecas/garrafas.h"
#include "src/Bibliotecas/cor.h"

void hardCode(garrafa *g)
{
    push((g) , "verde");
    push((g) , "azul");
    push((g) , "amarelo");

    push((g) + 1, "azul");
    push((g) + 1, "amarelo");
    push((g) + 1, "verde");

}


int main()
{
    garrafa g[3];

    for(int i = 0; i < 3; i++){
        inicializar(&g[i]);
    }

    hardCode(g);
    
    int de;
    int pra;
    char corTemp[255];

    while(true){
        desenhar(g);
        printf("\n digite a origem e o destino (ex: 1 3) ou '0 0' para sair:\n ");
        printf(">> ");
        if (scanf("%d %d", &de, &pra) != 2 || de == 0){
            break;
        } 
        de--;
        pra--;
        if (de < 0 || de > 2 || pra < 0 || pra > 2) {
            printf("\n opcao invalida\n");
            continue;
        }
        if (vazia(&g[de])) {
            printf("\n Erro: A garrafa %d esta vazia\n ", de + 1);
        } else if (cheia(&g[pra])) {
            printf("\n Erro: A garrafa %d esta cheia\n ", pra + 1);
        } else {
            strcpy(corTemp, pop(&g[de]));
            push(&g[pra], corTemp);
            printf("\n Sscesso: Cor movidfa!\n ");
        }
    }
    return 0;
}