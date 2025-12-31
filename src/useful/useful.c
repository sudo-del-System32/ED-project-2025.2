#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Bibliotecas/useful.h"


void correctString(char *str)
{
    str[strlen(str) - 1] = '\0';
}

void clean()
{
    #ifdef LinuxDistro
    system("clear");
    #elif
    system("cls");
    #endif
}

void bufferCleanner()
{
    char x = 'x';
    while(x != '\n') x = getchar();

}

void await()
{
    printf("\n\t\tAperte Enter para continuar:");
    bufferCleanner();
    
}
