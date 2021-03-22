#include<stdio.h>
#include<string.h>
#include "jogoforca.h"
#include<stdlib.h>
#include<time.h>

//variaveis globais

char palavrasecreta[20];
char chutes[26];
int chutesdados = 0;


//*********************************************

//Função cabeçalho: imprimi o cabeçalho do jogo 

void cabecalho(){

printf("\n");
printf("************************\n");
printf("* Ola! Eu sou a forca. *\n");
printf("************************\n");
printf("\n\n");


printf("Vamos comerçar?\n");
printf("\n\n");


}//fim void cabecalho

//
//Fuunção resposavel por receber o chute  

void chuta(){

char chute;
scanf(" %c",&chute);
chutes[chutesdados] = chute;
chutesdados++;

}//fim void chuta

//***********************************************


int chutou(char letra){

	int achou = 0;

	//conta J se menor que tentativas 			
	for(int j = 0; j < chutesdados ;j++){

		//compara se o chute na variavel J é igual a letra na posição i	
		if(chutes[j] == letra){

			//se verdadeiro achou trorna-se true 
			achou = 1;

		break;
		 }//fim if 

	 }//fim for tentativas

//retorna o resultado da variálvel cachou 
return achou;
 	 	
}//fim chuta.

//*************************************************

void desenhaforca(){

//função strlen irá varrer o array e 
//retornar o numero de posições preenchidas
for(int i = 0; i < strlen(palavrasecreta);i++){

	int achou = chutou(palavrasecreta[i]);

	if(achou){

		printf("%c ",palavrasecreta[i]);

	 }else{

		printf("_ ");


	 }//fim else
		
 	

 }//fim for palavrasecreta

 printf("\n");

}//fimdesenhaforca


//***************************************************************

void definepalavra(){

	FILE* f;


	//Abrindo Arquivo 'r' = leitura
	f = fopen("forcapalavras.txt", "r");



	int quantpalavras;

	//função para ler arquivos: 
	//[f = variavel que recebe o aquivo]

	fscanf(f, "%d", &quantpalavras);


    srand(time(0));

    int randomico = rand()  % quantpalavras;

    for (int i = 0; i < randomico; i++){

    	fscanf(f, "%s", palavrasecreta);
    }


	fclose(f);

}//fim definepalavra

//****************************************************************

int enforcou(){

	int erros = 0;

	for (int i = 0; i < chutesdados; ++i){

		int existe = 0;
	
		for (int j = 0; j < strlen(palavrasecreta); ++j){
			
			if (chutes[i] == palavrasecreta[j]){
				existe = 1;
				break;
			}

		}

		if (!existe) erros++;
	 }

		return erros >= 5;
 
 }

 //**************************************************************

 int ganhou(){

 	for (int i = 0; i < strlen(palavrasecreta); ++i){


 		if (!chutou(palavrasecreta[i])){
 			
 			return 0;
 		}
 	}

 	return 1;

 }

int main()

{
	
	
    definepalavra();
	cabecalho();

	do{
		
     
		 desenhaforca();
         chuta();

 		
	 }while(!ganhou() && !enforcou());	
 }
   