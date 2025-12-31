#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "src/Bibliotecas/garrafas.h"



int main()
{
    garrafa s[3];
    strcpy((s[0]).cores[0],"azul");
    (s[0]).qnt = 0;
    (s[0]).top = 0;
    printf("%s\n",pop(&s[0]));
    return 0;
}