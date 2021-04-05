//Bibliotecas 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"jogopcman.h"
#include"mapa.h"


/* Apelido para struct mapa. definida dentro de jogopcman.h.
 * declarando uma variavel m do tipo MAPA: A variaavel do tipo mapa 
 	é uma variaavel do tipo struturada, um Array, que recebe um array
 	multidimensional (uma matriz) e duas variavel do tipo inteiro. 
 	Isso é uma variavel do Tipo MAPA, recebe um papa bidmensional e duas coordenadas
 	para que, com isso possa ser definido uma posição no mapa.

 */
MAPA m;

/* Declarando uma variável comedor do tipo posição: 
	variável do tipo estruturado que recebe dois inteiros 
	para posição cordenada x e cordenada Y.

 */
POSICAO	comedor;

int tempilula = 0;


int caminhofantasma(int xatual, int yatual, int* xdestino, int* ydestino){

	int opcoes[4][2] = {
		{xatual, yatual + 1},
		{xatual + 1, yatual},
		{xatual, yatual - 1},
		{xatual - 1, yatual}
	 };

	srand(time(0));

	for(int i = 0; i < 10; i++) {
		int posicao = rand() % 4;

		if(podeandar(&m,  GELEIA_FANTASMA, opcoes[posicao][0], opcoes[posicao][1])){
		
			*xdestino = opcoes[posicao][0];
			*ydestino = opcoes[posicao][1];

			return 1;

		 }
     }
 }


//função responsavel por fazer os fantasmas deslocarem dentro do mapa
void fantasmas(){

	MAPA copia;

	copiamapa(&copia, &m);	

	for (int i = 0; i < m.linhas; i++) {

		for (int j = 0; j < m.colunas; j++)	{

			if(copia.matriz[i][j] == GELEIA_FANTASMA){

				int xdestino;
				int ydestino;

				int encontrou = caminhofantasma(i, j, &xdestino, &ydestino);

				if(encontrou){

					andandonomapa(&m, i, j, xdestino, ydestino);


		         }
			 }
		 }
	 }

	 liberamapa(&copia);
 }

int acabou() {

	POSICAO pos;

	int comedornopama = encontramapa(&m, &pos, COMEDOR);

  	return !comedornopama;

 }

 int ehdirecao(char direcao){

 	return direcao == ESQUERDA ||
		direcao == DIREITA ||
		direcao == CIMA ||
		direcao == BAIXO;

 }

void move(char direcao) {


	//trantando dados de entarda.
	if (!ehdirecao(direcao))

		return;

	int proximox = comedor.x;
	int proximoy = comedor.y;

	/* Move o foge foge pelas teclas abaixo:
	 *'a' esquerda.
	 *'w' direita.
	 *'s' p/cima. 
	 *'d' p/baixo.
	 */

	switch(direcao){

		// Caso a tecla 'a' seja pressionada o simbolo '@' 'se desloca uma posição para a esquerda.
		case ESQUERDA:
		proximoy--;
		break;

		// Caso a tecla 'd' seja pressionada o simbolo '@' 'se desloca uma posição para a direita.
		case CIMA:
		proximox--;
		break;

		// Caso a tecla 'w' seja pressionada o simbolo '@' 'se desloca uma posição para a cima.
		case BAIXO:
		proximox++;
		break;

		// Caso a tecla 's' seja pressionada o simbolo '@' 'se desloca uma posição para a baixo.
		case DIREITA:
		proximoy++;
		break;
	 }

	if(!podeandar(&m , COMEDOR, proximox, proximoy))
		return;

	if (ehpersonagem(&m, PILULA, proximox, proximoy)){

		tempilula = 1;

	}



	andandonomapa(&m, comedor.x, comedor.y, proximox, proximoy);

		comedor.x = proximox;
		comedor.y = proximoy;
 } 

 void explodepilula(){

 	printf("Explodiu!\n");
 }
	 
int main() {

	lemapa(&m);

	//recebe o mapa e qurda a posicão do comedor @.
	encontramapa(&m, &comedor, COMEDOR);

	do{

		printf("Tem pililula: %s\n", (tempilula ? "SIM":"NAO"));

		imprimemapa(&m);

		char comando;
		scanf(" %c", &comando);
		move(comando);

		if(comando == BOMBA) explodepilula();

		fantasmas();



	 }while(!acabou());

       
    liberamapa(&m);

  return 0;

 }