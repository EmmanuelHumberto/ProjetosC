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

	if(!ehvalida(&m , proximox, proximoy))
		return;
	if(!ehvazia(&m, proximox, proximoy))
	 	return;

	andandonomapa(&m, comedor.x, comedor.y, proximox, proximoy);

		comedor.x = proximox;
		comedor.y = proximoy;
 } 
	 
int main() {

	lemapa(&m);

	//recebe o mapa e qurda a posicão do comedor @.
	encontramapa(&m, &comedor, COMEDOR);

	do{

		imprimemapa(&m);

		char comando;
		scanf(" %c", &comando);
		move(comando);



	 }while(!acabou());

       
    liberamapa(&m);

  return 0;

 }