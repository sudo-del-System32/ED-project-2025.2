
typedef struct garrafa garrafa;
struct garrafa{

char cores[3];
int top;
int qnt;

};

//Funçao de verificar se a garrafa esta vazia.
bool vazia(garrafa *s);

//Funçao de retirar um item, retorna o item retirado.
char pop(garrafa *s);
