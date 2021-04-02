#include<stdio.h>
#include<stdlib.h>
#include"mapa.h"

/*
    Todas a funções abaixo recebem o mesmo agurmento (MAPA* m) 
      que é um ponteiro do tipo 'MAPA'.
      A variável MAPA encontra-se em outro arquivo. mapa.h.
 */

void liberamapa(MAPA* m){


 	for (int i = 0; i < (*m).linhas; ++i){
     	/*Função free libera o espeçao de memoria aloacdo
     	   no ponteiro (*m).matriz na posição i
     	 */
     	free(m->matriz[i]);
     	
     }
         /* outra maneira de usar ponteiros
            o atalho -> 
     	   
     	  */
     	free(m->matriz);

 }

void alocamapa(MAPA* m){

 	 /* função molloc resposavel pela alocação de memória.
	  * função sizeof retorn a quantidade de bytes que o tipo declarado precisa.
	  * Variavel (*m).matriz recebe dinamicamente a qte de bytes necessarios para guaradar 
	  	 as linhas do arquivo mapa.txt.
      */
    m->matriz = malloc(sizeof(char*) * m->linhas);

    //percorre a qte de linhas no aquivo mapa.txt.
    for (int i =0; i < m->linhas;i++){

     	/*m.matriz na posição i irá alocar espço suficiente para caber a qte de byte
		   necessários para guardar ponteiros de char.
     	 */
     	m->matriz[i] = malloc(sizeof(char) * (m->colunas + 1));

     }
 }

void lemapa(MAPA* m){


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
     	fscanf(f, "%d %d", &(m->linhas), &(m->colunas));

 	 	alocamapa(m);

 	 	for (int i = 0; i < 5; ++i){

    	//lê o mapa na posição i
     	fscanf(f, "%s", m->matriz[i]);	
     	
     }


    
      //Fechando Arquivo mapa.txt
     fclose(f);

 }


void imprimemapa(MAPA* m){

 	for (int i = 0; i < 5; ++i){

    	//imprime o mapa na posição i
     	printf("%s\n", m->matriz[i]);

     }

}