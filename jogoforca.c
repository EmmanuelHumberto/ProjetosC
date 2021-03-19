#include<stdio.h>
#include<string.h>

int main()
{


	char palavrasecreta[20];

	// função coloca a palavra melancia dentro do arrey.
	sprintf(palavrasecreta,"MELANCIA");


	int acertou = 0;

	int enforcou = 0; 

	do{
		
     
		//função strlen irá varrer o array e 
		//retornar o numero de posições preenchidas
		for(int i = 0; i < strlen(palavrasecreta);i++){
			printf("_ ");
         }
         printf("\n");

         char chute;
		 scanf("%c",&chute);


			/*//compara se a palavra secreta na posição 'i' é igual ao chute 
			if(palavrasecreta[i] == chute){

				printf("Aposição %d tem essa letra!\n",i);


             }*/

	}while(!acertou && !enforcou);

		


 }

   