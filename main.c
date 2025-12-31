#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "src/Bibliotecas/useful.h"

#include "src/Bibliotecas/garrafas.h"
#include "src/Bibliotecas/cor.h"

void hardCode(garrafa *g);
void gameMenu(garrafa *g);


int main()
{
    garrafa g[NUM_DE_PILHAS];
    
    for(int i = 0; i < NUM_DE_PILHAS; i++){
        inicializar(&g[i]);
    }
    
    hardCode(g);
    
    gameMenu(g);
    
    return 0;
}


void hardCode(garrafa *g)
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


void gameMenu(garrafa *g)
{
    int opcao;
    bool opcaoValida = true, saida = false;
    

    while(saida == false){
        desenhar(g);
        printf("\n Digite a origem e o destino (ex: 13) ou '00' para sair:\n ");
        if(opcaoValida == false)
        { 

            if(vazia(&g[opcao/10 - 1])) printf("             Erro:A garrafa %d esta vazia", opcao/10);
            else if (cheia(&g[opcao%10 - 1]))  printf("             Erro: A garrafa %d esta cheia", opcao%10);
            else printf("\t\t Opcao invalida!\n\t\t Tente novamente");
            
            printf("\n");
            opcaoValida = true;
        }
        
        printf(">> ");
        scanf("%d", &opcao);
        bufferCleanner();
        
        while(true){
            //saida
            if(opcao == 00)     
            {
                saida = true;
                break;
            }       


            opcaoValida = false;
            //Verificaçao se a garrafa pode dar ou receber a cor.
            if (vazia(&g[opcao/10 - 1])) 
            {
                break;
            }
            else if (cheia(&g[opcao%10 - 1])) 
            {
                break;
            }
            else if (opcao%10 < 1 || opcao%10 > NUM_DE_PILHAS || opcao/10 < 1 || opcao/10 > NUM_DE_PILHAS)
            {
                break;
            }
            
            opcaoValida = true;
            tranferirCor(&g[opcao%10 - 1], &g[opcao/10 - 1]);
            break;
        }
    }
}
