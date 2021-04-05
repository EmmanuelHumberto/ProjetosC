//Diretivas define: define constantes que poderão ser usada em qualquer parte do codigo.

#define CIMA 'w'
#define BAIXO 's'
#define DIREITA 'd'
#define ESQUERDA 'a'
#define BOMBA 'b'


/* Assinaturas das funções em jogopcman.c
	Com esse recurso o compilador não terá problemas em ler funções fora da ordem.
 */
void move(char direcao);
int acabou();
int ehdirecao(char direcao);
void fantasmas();
int caminhofantasma(int xatual, int yatual, int* xdestino, int* ydestino);
