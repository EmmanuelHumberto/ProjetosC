
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
void encontramapa(MAPA* m, POSICAO* p, char c);