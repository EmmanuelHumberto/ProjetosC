#include<stdio.h>
#include<stdlib.h>
#include"jogopcman.h"

/*Declarando uma matrix de char. Os dois ** após o tipo da variável 
  decalra um ponteiro de ponteiro para char.
 */

struct mapa m;

void liberamapa(){


 	for (int i = 0; i < m.linhas; ++i){
     	/*Função free libera o espeçao de memoria aloacdo
     	   em mapa na posição i
     	 */
     	free(m.matriz[i]);
     	
     }
         /*Função free libera o espeçao de memoria aloacdo
     	    para mapa
     	  */
     	free(m.matriz);

 }

void alocamapa(){

 	 /* função molloc resposavel pela alocação de memória.
	  * função sizeof retorn a quantidade de bytes que o tipo declaro precisa.
	  * Variavel mapa recebe dinamicamente a qte de bytes necessarios para guaradar 
	  	 as linhas do ariovo mapa.txt.
      */
    m.matriz = malloc(sizeof(char*) * m.linhas);

     //percorre a qte de linhas no aquivo mapa.txt.
    for (int i =0; i < m.linhas;i++){

     	/*mapa na posição i irá alocar espço suficiente para caber a qte de byte
		   necessários para guardar ponteiros de char.
     	 */
     	m.matriz[i] = malloc(sizeof(char) * (m.colunas + 1));

     }
 }

void lemapa(){


 	FILE* f;
    //Abrindo Arquivo 'r+' = leitura e escrita.
	f = fopen("mapa.txt", "r");

	//caso f != 0 imprimi numero de linhas e colunas 
	if (f == 0){

		printf("Erro de leitura no mapa\n");
		exit(1);
     }

     	/*função para ler arquivos: 
	 	 * [f = variavel que recebe o aquivo]
	 	 */
     	fscanf(f, "%d %d", &(m.linhas), &(m.colunas));

 	 	alocamapa();

 	 	for (int i = 0; i < 5; ++i){

    	//lê o mapa na posição i
     	fscanf(f, "%s", m.matriz[i]);	
     	
     }


    
      //Fechando Arquivo mapa.txt
     fclose(f);

 }


void imprimemapa(){

 	for (int i = 0; i < 5; ++i){

    	//imprime o mapa na posição i
     	printf("%s\n", m.matriz[i]);

     }

}


int acabou(){

return 0;


}

void move(char direcao){

	int x;
	int y;

	//Acha a posição do foge foge

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

	lemapa();

	do{

		imprimemapa();
		char comando;
		scanf(" %c", &comando);
		move(comando);



	}while(!acabou());

       
    liberamapa();

 return 0;
}


