#include<stdio.h>
#include<string.h>

//variaveis globais

char palavrasecreta[20];
char chutes[26];
int tentativas = 0;


//*********************************************

//Função cabeçalho: imprimi o cabeçalho do jogo 

void cabecalho(){

printf("\n");
printf("************************\n");
printf("* Ola! Eu sou a forca. *\n");
printf("************************\n");
printf("\n\n");


printf("Quer brincar?\n");
printf("\n\n");


}//fim void cabecalho

//
//Fuunção resposavel por checar se o chute 

void chuta(){

char chute;
scanf(" %c",&chute);
chutes[tentativas] = chute;
tentativas++;

}//fim void chuta

//***********************************************


int chutou(char letra,){

	int achou = 0;

	//conta J se menor que tentativas 			
	for(int j = 0; j < tentativas; j++){

		//compara se o chute na variavel J é igual a letra na posição i	
		if(chutes[j] == letra[i]){

			//se verdadeiro achou trorna-se true 
			achou = 1;

		break;
		 }//fim if 

	 }//fim for tentativas

//retorna o resultado da variálvel cachou 
return achou;
 	 	
}//fim int chuta.

//*************************************************

void desenhaforca();
{

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


}//fimdesenhaforca


//***************************************************************

void definepalavra(){

	sprintf(palavrasecreta, "MELANCIA");


}//fim definepalavra

int main()

{
	
	int acertou = 0;
	int enforcou = 0; 
    
    definepalavra();
	cabecalho();

	do{
		
     
		 desenhaforca();
         chuta();

 		
	 }while(!acertou && !enforcou);

}//fim main

   