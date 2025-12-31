
typedef struct garrafa{
char cores[3][255];
int top;
int qnt;
}garrafa;

//Funçao de verificar se a garrafa esta vazia.
bool vazia(garrafa *g);

//Função de verificar se a garrafa esta cheia.
bool cheia(garrafa *s);

//Funçao de retirar um item, retorna o item retirado.
char *pop(garrafa *g);
