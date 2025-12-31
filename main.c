#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "src/Bibliotecas/garrafas.h"


int main()
{
    garrafa g[3];
    strcpy((g[0]).cores[0],"azul");
    (g[0]).qnt = 0;
    (g[0]).top = 0;
    printf("%s\n",pop(&g[0]));
    return 0;
}