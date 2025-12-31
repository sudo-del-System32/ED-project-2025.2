#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../Bibliotecas/cor.h"

const char* getColorCode(const char* nome_cor) {
    if (strcmp(nome_cor, "verde") == 0) return VERDE;
    if (strcmp(nome_cor, "azul") == 0) return AZUL;
    if (strcmp(nome_cor, "amarelo") == 0) return AMARELO;
    return RESET; 
}

