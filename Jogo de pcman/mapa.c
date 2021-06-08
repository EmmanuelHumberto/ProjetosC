#include<stdio.h>
#include<stdlib.h>
#include<string.h>  
#include"mapa.h"

void copiamapa(MAPA* destino, MAPA* origem){

    destino->linhas = origem->linhas;
    destino->colunas = origem->colunas;

    alocamapa(destino);

    for (int i = 0; i < origem->linhas; i++) {

        for (int j= 0; j < origem->colunas; j++) {

            /*strcpy ccopia o valor da string na segunda posição do argumento para 
                uma variável string na primeira posição. O segundo argumento pode ser uma variável, 
                uma expressão string ou um valor literal string contido entre aspas
            */
            strcpy(destino->matriz[i], origem->matriz[i]);
          
        }
        
    }
   
}


 
void andandonomapa(MAPA* m, int xorigem, int yorigem, int xdestino, int ydestino){

    char personagem = m->matriz[xorigem][yorigem];
    m->matriz[xdestino][ydestino] = personagem;
    m->matriz[xorigem][yorigem] = VAZIO;
 }


int ehvalida(MAPA* m, int x, int y) {

//validando filtros
    if(x >= m->linhas)
        return 0;

    if(y >= m->colunas)
        return 0;

    return 1;

}


int ehvazia(MAPA* m, int x, int y) {

    return m->matriz[x][y] == VAZIO;

}
    


int encontramapa(MAPA* m, POSICAO* p, char c) {

    for (int i = 0; i < m->linhas; i++){

        for (int j = 0; j < m->colunas; j++){

            if (m->matriz[i][j] == c) {
                p->x = i;
                p->y = j;
                return 1;
	
            }

        }
    
    }

    return 0;

}

int ehparede(MAPA* m, int x, int y){

    return m->matriz[x][y] == PAREDE_VERT ||  m->matriz[x][y] == PAREDE_HOR;
}

int podeandar(MAPA *m,char personagem, int x, int y){

    return 
         ehvalida(m, x, y) && !ehparede(m, x, y) && !ehpersonagem(m, personagem, x, y);  

 }

 int ehpersonagem(MAPA* m, char personagem, int x, int y){

    return m->matriz[x][y] == personagem;


 }

/*
    Todas a funções abaixo recebem o mesmo agurmento (MAPA* m) 
      que é um ponteiro do tipo 'MAPA'.
      A variável MAPA encontra-se em outro arquivo. mapa.h.
 */

void liberamapa(MAPA* m){

 	for (int i = 0; i < (*m).linhas; i++){
     	/*Função free libera o espeçao de memoria alocadodo
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
	  * função sizeof retorna a quantidade de bytes que o tipo declarado precisa.
	  * Variavel (*m).matriz recebe dinamicamente a qte de bytes necessarios para guaradar 
	  	 as linhas do arquivo mapa.txt.
      */
    m->matriz = malloc(sizeof(char*) * m->linhas);

    //percorre a qte de linhas no aquivo mapa.txt.
    for (int i = 0; i < m->linhas; i++){

     	/*m.matriz na posição i irá alocar espço suficiente para caber a qte de byte
		   necessários para guardar ponteiros de char.
     	 */
     	m->matriz[i] = malloc(sizeof(char) * (m->colunas + 1));

     }
 }

/* Função Lemapa resposavel por abrir o aquivo que contem o mapa
    e le o seu conteudo, linhas e colunas e aloca seu conteudo na variavel n
    utilizando a função alocapama
 */
void lemapa(MAPA* m){

    //Definindo variavel ponteiro de f que irá receber o arquivo a ser aberto
 	FILE* f;
    //Abrindo Arquivo 'r+' = leitura e escrita.
	f = fopen("mapa.txt", "r");

	//caso f != 0 imprimi numero de linhas e colunas 
	if (f == 0){

        //caso o retorno de if seja zero a mensagem  de erro abaixo é impressa.
		printf("Erro de leitura no mapa\n");
		
        //Sai do programa
        exit(1);
     }

     	/*função para ler arquivos: 
	 	 * [f = variavel que recebe o aquivo]
	 	 */
     	fscanf(f, "%d %d", &(m->linhas), &(m->colunas));

 	 	alocamapa(m);

 	 	for (int i = 0; i < 11; ++i){

    	//lê o mapa na posição 
     	fscanf(f, "%s", m->matriz[i]);	
     	
     }


    
      //Fechando Arquivo mapa.txt
     fclose(f);

 }


void imprimemapa(MAPA* m){

 	for (int i = 0; i < 11; i++){

    	//imprime o mapa na posição i
     	printf("%s\n", m->matriz[i]);

     }

}
