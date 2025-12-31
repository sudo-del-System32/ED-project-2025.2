
typedef struct garrafa{

  char cores[3][255];
  int top;
  int qnt;

}garrafa;



#define MAX_SIZE 3;

//Funçao de verificar se a garrafa esta vazia.
bool vazia(garrafa *g);

//Função pra ver se ta cheia
bool cheia(garrafa *g);

//Funçao de retirar um item, retorna o item retirado.
char *pop(garrafa *g);

//Função pra adicionar uma cor a garrafa
bool push(garrafa *g , char *cor);

//Função pra desenhar
void desenhar(garrafa g[3]);

