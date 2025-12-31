
#define MAX_SIZE 3;
typedef struct garrafa{

char cores[3][255];
int top;
int qnt;

}garrafa;


//Funçao de verificar se a garrafa esta vazia.
bool vazia(garrafa *g);

//Funçao de retirar um item, retorna o item retirado.
char *pop(garrafa *g);
