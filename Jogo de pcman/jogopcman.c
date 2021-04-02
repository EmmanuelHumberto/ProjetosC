#include<stdio.h>
#include<stdlib.h>
#include"jogopcman.h"
#include"mapa.h"


//Apelido para struct mapa. definida dentro de jogopcman.h.
MAPA m;

POSICAO	comedor;

int acabou() {

  return 0;

 }

void move(char direcao) {

	int x;
	int y;

	//imprime o ponto final na posoção iy.
	m.matriz[comedor.x][comedor.y] = '.';

	 /* Move o foge foge pelas teclas abaixo:
	 *'a' esquerda.
	 *'w' direita.
	 *'s' p/cima. 
	 *'d' p/baixo.
	 */

	switch(direcao){

		// Caso a tecla 'a' seja pressionada o simbolo '@' 'se desloca uma posição para a esquerda.
		case 'a':
		m.matriz[comedor.x][comedor.y-1] = '@';
		comedor.y--;
		break;

		// Caso a tecla 'd' seja pressionada o simbolo '@' 'se desloca uma posição para a direita.
		case 'w':
		m.matriz[comedor.x-1][comedor.y] = '@';
		comedor.x--;
		break;

		// Caso a tecla 'w' seja pressionada o simbolo '@' 'se desloca uma posição para a cima.
		case 's':
		m.matriz[comedor.x+1][comedor.y] = '@';
		comedor.x++;
		break;

		// Caso a tecla 's' seja pressionada o simbolo '@' 'se desloca uma posição para a baixo.
		case 'd':
		m.matriz[comedor.x][comedor.y+1] = '@';
		comedor.y++;
	 }

 } 
	 
int main() {

	lemapa(&m);

	//recebe o mapa e qurda a posicão do comedor @.
	encontramapa(&m, &comedor, '@');

	do{

		imprimemapa(&m);

		char comando;
		scanf(" %c", &comando);
		move(comando);



	 }while(!acabou());

       
    liberamapa(&m);

  return 0;

 }