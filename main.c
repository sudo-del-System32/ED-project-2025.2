#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "src/Bibliotecas/garrafas.h"



int main()
{
    garrafa s;
    s.cores[0] = 'b';
    s.qnt = 0;
    s.top = 0;
    printf("%c\n",pop(&s));
    return 0;
}