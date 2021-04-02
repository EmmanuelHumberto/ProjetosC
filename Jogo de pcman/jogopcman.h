/*Declarando as funções  do aquivo jogopcman.c em ajogopcman.h para que o compilador
	possa compilar o codigo sem se preocupar cma ordem das funções dentro do programa.
 */
void liberamapa();
void alocamapa();
void lemapa();
void imprimemapa();
int acabou();
void move(char direcao);


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
