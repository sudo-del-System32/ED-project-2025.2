
typedef struct garrafa{

  char cores[3][255];
  int top;
  int qnt;

}garrafa;

#define MAX_SIZE 3;

//Funçao de verificar se a pilha esta vazia.
bool vazia(garrafa *g);

//Função pra verifica se a pilha esta cheia.
bool cheia(garrafa *g);

//Inicializa uma garrafa.
void inicializar(garrafa *g); 

//Função pra adicionar um item, retorna se funcionou ou nao.
bool push(garrafa *g , char cor[]);

//Funçao de retirar um item, retorna o item retirado.
char *pop(garrafa *g);

//Retira um item de s e coloca-o em g.
bool tranferirCor(garrafa *g, garrafa *s);

