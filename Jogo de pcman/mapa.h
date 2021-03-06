#define COMEDOR '@'
#define GELEIA_FANTASMA 'Z'
#define VAZIO '.'
#define PAREDE_VERT '|'
#define PAREDE_HOR '-'
#define PILULA 'P'


/*função struct: permite agrupar uma "coleção" de variáveis do "tipo" Mapa.
    essa struct quando chamada terá uma matrix, mais duas variaveis do tipo int.
 */
struct mapa{

    /*Declarando uma matrix de char. Os dois ** após o tipo da variável 
      decalra um ponteiro de ponteiro para char.
     */
    char** matriz;
    int linhas;
    int colunas;
};
//define um "apelido" para a variável declarada
typedef struct mapa MAPA;


struct posicao {

	 int x;
	 int y;

};

typedef struct posicao POSICAO;


/*Declarando as funções  do aquivo jogopcman.c em ajogopcman.h para que o compilador
    possa compilar o codigo sem se preocupar cma ordem das funções dentro do programa.
 */
void liberamapa(MAPA* m);
void alocamapa(MAPA* m);
void lemapa(MAPA* m);
void imprimemapa(MAPA* m);
void andandonomapa(MAPA* m, int xorigem, int yorigem, int xdestino, int ydestino);
void copiamapa(MAPA* destino, MAPA* origem);
int encontramapa(MAPA* m, POSICAO* p, char c);
int ehvalida(MAPA* m, int x, int y);
int ehvazia(MAPA* m, int x, int y);
int caminhofantasma(int xatual, int yatual, int* xdestino, int* ydestino);
int podeandar(MAPA *m,char personagem, int x, int y);
int ehparede(MAPA* m, int x, int y);
int ehpersonagem(MAPA* m, char personagem, int x, int y);
 void explodepilula();