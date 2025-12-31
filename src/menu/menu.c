#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../Bibliotecas/useful.h"

#include "../Bibliotecas/garrafas.h"
#include "../Bibliotecas/menu.h"


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
                printfVezes(" ", (9 - tamDaCor) / 2 + (tamDaCor % 2? 0 : 1));
                printf("%s", conseguirCor(cor));
                printf("%s", cor);
                printf("%s", RESET);
                printfVezes(" ", 9 - tamDaCor - (9 - tamDaCor) / 2 - (tamDaCor % 2? 0 : 1));
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



void gameMenu(garrafa *g)
{
    int opcao;
    bool opcaoValida = true, saida = false, possivelErroDeSegmento = false;
    
    
    while(saida == false){
        desenhar(g);
        if(saida == false && possivelErroDeSegmento == false)
        {
            for(int i = 0; i <= NUM_DE_PILHAS - 1; i++)
            {
                saida = itensIguais(&g[i]);
                if(saida == false) break;
            }
            if(saida == true) break;
        }


        printf("\n Digite a origem e o destino (ex: 13) ou '00' para sair:\n ");
        if(opcaoValida == false)
        { 
            
            if(possivelErroDeSegmento == false && vazia(&g[opcao/10 - 1])) printf("             Erro:A garrafa %d esta vazia", opcao/10);
            else if (possivelErroDeSegmento == false && cheia(&g[opcao%10 - 1]))  printf("             Erro: A garrafa %d esta cheia", opcao%10);
            else printf("\t\t Opcao invalida!\n\t\t Tente novamente");
            
            printf("\n");
            opcaoValida = true;
            possivelErroDeSegmento = false; 
        }
        

        printf(">> ");
        scanf("%d", &opcao);
        bufferCleanner();
        
        while(true){
            //saida
            if(opcao == 00 )     
            {
                saida = true;
                break;
            }       


            opcaoValida = false;
            //Verificaçao se a garrafa pode dar ou receber a cor.
            if (opcao%10 < 1 || opcao%10 > NUM_DE_PILHAS || opcao/10 < 1 || opcao/10 > NUM_DE_PILHAS)
            {
                possivelErroDeSegmento = true;
                break;
            }
            else if (vazia(&g[opcao/10 - 1])) 
            {
                break;
            }
            else if (cheia(&g[opcao%10 - 1])) 
            {
                break;
            }
            
            opcaoValida = true;
            tranferirCor(&g[opcao%10 - 1], &g[opcao/10 - 1]);
            break;
        }
    }
}
