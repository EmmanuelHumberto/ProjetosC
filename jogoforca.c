#include<stdio.h>
#include<string.h>



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

void chuta(char chutes[26], int *tentativas){

char chute;
scanf(" %c",&chute);
chutes[(*tentativas)] = chute;
(*tentativas)++;

}//fim void chuta

//***********************************************


int chutou(char letra, char chutes[26], int tentativas){

	int achou = 0;

			
	for(int j = 0; j < tentativas; j++){

			
		if(chutes[j] == letra[i]){

			achou = 1;

		break;
		 }//fim if 

	 }//fim for tentativas

return achou;
 	 	
}//fim int chuta.

//*************************************************

int main()

{
	cabecalho();
	
	char palavrasecreta[20];

	// função coloca a palavra melancia dentro do arrey.
	sprintf(palavrasecreta,"MELANCIA");


	int acertou = 0;

	int enforcou = 0; 

	char chutes[26];

	int tentativas = 0;

	do{
		
     
		//função strlen irá varrer o array e 
		//retornar o numero de posições preenchidas
		for(int i = 0; i < strlen(palavrasecreta);i++){

		int achou = chutou(palavrasecreta, chutes, tentativas);

			if(achou){

				printf("%c ",palavrasecreta[i]);

			}else{

				printf("_ ");

			}//fim else

			
         }//fim for palavrasecreta

         printf("\n");

         chuta(chutes,&tentativas);

 		
	 }while(!acertou && !enforcou);

}//fim main
   