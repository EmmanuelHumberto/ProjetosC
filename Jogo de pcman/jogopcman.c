#include<stdio.h>
#include<stdlib.h>

/*Declarando uma matrix de char. Os dois ** após o tipo da variável 
  decalra um ponteiro de ponteiro para char.
 */
char** mapa;

int linhas;
int colunas;

void liberamapa(){


 	for (int i = 0; i < linhas; ++i){
     	/*Função free libera o espeçao de memoria aloacdo
     	   em mapa na posição i
     	 */
     	free(mapa[i]);
     	
     }
         /*Função free libera o espeçao de memoria aloacdo
     	    para mapa
     	  */
     	free(mapa);

 }

void alocamapa(){

 	 /* função molloc resposavel pela alocação de memória.
	  * função sizeof retorn a quantidade de bytes que o tipo declaro precisa.
	  * Variavel mapa recebe dinamicamente a qte de bytes necessarios para guaradar 
	  	 as linhas do ariovo mapa.txt.
      */
    mapa = malloc(sizeof(char*) * linhas);

     //percorre a qte de linhas no aquivo mapa.txt.
    for (int i =0; i < linhas;i++){

     	/*mapa na posição i irá alocar espço suficiente para caber a qte de byte
		   necessários para guardar ponteiros de char.
     	 */
     	mapa[i] = malloc(sizeof(char) * (colunas + 1));

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
     	fscanf(f, "%d %d", &linhas, &colunas);

 	 	alocamapa();


    for (int i = 0; i < 5; ++i){

    	//lê o mapa na posição i
     	fscanf(f, "%s", mapa[i]);

     }

      //Fechando Arquivo mapa.txt
     fclose(f);

 }





int main(){

	lemapa();

    for (int i = 0; i < 5; ++i)

    {
    	//imprime o mapa na posição i
     	printf("%s\n", mapa[i]);

     }
    
    liberamapa();

 return 0;
}


