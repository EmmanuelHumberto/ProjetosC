#include<stdio.h>
#include<stdlib.h>
#include"jogopcman.h"
#include"mapa.h"



//Apelido para struct mapa. definida dentro de jogopcman.h
MAPA m;



int acabou(){

return 0;


}

void move(char direcao){

	int x;
	int y;

	//Acha a posição do foge foge no mapa

	for (int i = 0; i < m.linhas; i++){

		for (int j = 0; j < m.colunas; j++){

			if (m.matriz[i][j] == '@'){

				x =i;
				y=j;
				break;

			}

		}
	
	}

	/* Move o foge foge pelas teclas abaixo:

	 *'a' esquerda
	 *'w' direira 
	 *'s' p/cima 
	 *'d' p/baixo 

	 */
	switch(direcao){

		// Caso a tecla 'a' seja pressionada o simbolo '@' 'se desloca uma posição para a esquerda.
		case 'a':
		m.matriz[x][y-1] = '@';
		break;

		// Caso a tecla 'd' seja pressionada o simbolo '@' 'se desloca uma posição para a direita.
		case 'w':
		m.matriz[x-1][y] = '@';
		break;

		// Caso a tecla 'w' seja pressionada o simbolo '@' 'se desloca uma posição para a cima.
		case 's':
		m.matriz[x+1][y] = '@';
		break;

		// Caso a tecla 's' seja pressionada o simbolo '@' 'se desloca uma posição para a baixo.
		case 'd':
		m.matriz[x][y+1] = '@';
		break;

	 }

	 //imprime o ponto final na posoção iy
	 m.matriz[x][y] = '.';

}

int main(){

	lemapa(&m);

	do{

		imprimemapa(&m);
		char comando;
		scanf(" %c", &comando);
		move(comando);



	}while(!acabou());

       
    liberamapa(&m);

 return 0;
}


