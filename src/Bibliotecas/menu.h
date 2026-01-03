//Definições para que o menu tenha cor no terminal.
#define VERMELHO     "\x1b[31m"
#define VERDE        "\x1b[32m"
#define AZUL         "\x1b[34m"
#define AMARELO      "\x1b[33m"
#define ROSA         "\x1b[35m"
#define CIANO        "\x1b[36m"
#define RESET        "\x1b[0m"

//Função para conseguir o codigo da cor.
const char* conseguirCor(const char* nome_cor);

//Função de print do menu
void desenhar(garrafa *g);

//Funçao para dar multiplos printfs.
void printfVezes(const char *str, int numVezes);

//Função do menu do jogo.
bool gameMenu(garrafa *g);
