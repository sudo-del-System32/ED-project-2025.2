
#define NUM_DE_PILHAS 4
#define MAX_SIZE (NUM_DE_PILHAS - 1)


typedef struct garrafa{

  char cores[MAX_SIZE][255];
  int top;
  int qnt;

}garrafa;


//Funçao de verificar se a pilha esta vazia.
bool vazia(garrafa *g);

//Função pra verifica se a pilha esta cheia.
bool cheia(garrafa *g);

//Inicializa uma garrafa.
void inicializar(garrafa *g); 

//Função pra adicionar um item, retorna se funcionou ou nao.
void push(garrafa *g , char cor[]);

//Funçao de retirar um item, retorna o item retirado.
char *pop(garrafa *g);

//Retira um item de s e coloca-o em g.
void tranferirCor(garrafa *g, garrafa *s);

//Copia uma pilha em outra, com o conceito de pilha intactio :) .
void copiarPilha(garrafa *g, garrafa *s);
