#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include "jogoforca.h"

//Variaveis Globais 

//Passanso para variavel palavra secrta uma conatsnte char 
char palavrasecreta[TAMANHO_PALAVRA];
char chutes[26];
int chutesdados = 0;

//****************************************************

void cabecalho(){

printf("\n");
printf("************************\n");
printf("* Ola! Eu sou a forca. *\n");
printf("************************\n");
printf("\n\n");


printf("Vamos comerçar?\n");
printf("\n\n");


}//fim void cabecalho

//************************************************
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
 	 	
}//fim chuta

//*************************************************S

void desenhaforca(){

int erros = chuteserrados();

//uso da função ifternário
//(condicao ? valor verdadeiro : valor falso)

printf("================================== \n");
printf("  _______       \n");
printf(" |/      |      \n");
printf(" |      %c%c%c  \n", (erros>=1?'(':' '), 
    (erros>=1?'_':' '), (erros>=1?')':' '));
printf(" |      %c%c%c  \n", (erros>=3?'/':' '), 
    (erros>=2?'|':' '), (erros>=3?'/': ' '));
printf(" |       %c     \n", (erros>=2?'|':' '));
printf(" |      %c %c   \n", (erros>=4?'/':' '), 
    (erros>=4?'\\':' '));
printf(" |              \n");
printf("_|___           \n");
printf("===================================\n");
printf("\n\n");

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
void adicionapalavra(){

char quer;

printf("Deseja adicionar uma nova palavra no jogo?\n");
printf("S Sim\n");
printf("N Não\n");
printf("\n");
scanf(" %c",&quer);

if(quer == 'S'){

	char novapalavra[TAMANHO_PALAVRA];
	printf("Qual a nova palavra?\n");
	scanf("%s", novapalavra);	

	FILE* f;

    //Abrindo Arquivo 'r+' = leitura e escrita.
	f = fopen("forcapalavras.txt", "r+");

	if (f == 0){

		printf("Palavra não dosponivel no banco de dados\n");
		exit(1);
	}

	int qte;
	fscanf(f, "%d", &qte);
	qte++;

	// Função responsavel por posiciona o cursor de leirura na posição zero
	//([variavel 'F'], [posição curosr], [const de referencia da posição])
	fseek(f, 0, SEEK_SET);

	//sobrescreve dado na posição referenciada 
	fprintf(f, "%d\n",qte);

    // Função responsavel por posiciona o cursor de leirura no fim do aquivo
	fseek(f, 0, SEEK_END);
	fprintf(f, "\n%s", novapalavra);

	fclose(f);

 }

}


//****************************************************************

void definepalavra(){

	FILE* f;


	//Abrindo Arquivo 'r' = leitura
	f = fopen("forcapalavras.txt", "r");
	if (f == 0){

		printf("Palavra não dosponivel no banco de dados\n");
		exit(1);
	}



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


int chuteserrados() {
    int erros = 0;

    for(int i = 0; i < chutesdados; i++) {

        int existe = 0;

        for(int j = 0; j < strlen(palavrasecreta); j++) {
            if(chutes[i] == palavrasecreta[j]) {
                existe = 1;
                break;
            }
        }

        if(!existe) erros++;
    }

    return erros;
}

int enforcou() {
    // usamos a função que acabamos de criar
    return chuteserrados() >= 5;
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

	 if(ganhou()){
	 
      printf("*******************************\n");
      printf("✅ *  Parabéns, você ganhou!  *\n");
      printf("*******************************\n");
      printf("\n");
      printf("       ___________      \n");
      printf("       '._==_==_=_.'    \n");
      printf("       .-\\:      /-.    \n");
      printf("      | (|:.     |) |   \n");
      printf("       '-|:.     |-'    \n");
      printf("         \\::.    /      \n");
      printf("          '::. .'       \n");
      printf("           ) (          \n");
      printf("          _.' '._       \n");
      printf("        '-------'       \n");
	  printf("                        \n");
	  printf("\n\n");
	  printf("Como premio voce poderá adicionar uma palavra ao jogo.\n\n");

	  adicionapalavra();

	}else{

		printf("\n");
        printf("*************************************\n");
        printf(" ❌ * Você Perdeu! E foi Enforcado! *\n");
        printf("*************************************\n");
        printf("\n");

        printf("A palavra secreta é ***%s***\n", palavrasecreta);



        printf("\n\n");
	 	printf("                              \n");
		printf(" ███▀░░░░░░░░░░░░░░░░░▀████   \n");
		printf(" ███│░░░░░░░░░░░░░░░░░░░│███  \n");
		printf(" ██▌│░░░░░░░░░░░░░░░░░░░│▐██  \n");
		printf(" ██░└┐░░░░░░░░░░░░░░░░░┌┘░██  \n");
		printf(" ██░░└┐░░░░░░░░░░░░░░░┌┘░░██  \n");
		printf(" ██░░┌┘▄▄▄▄▄░░░░░▄▄▄▄▄└┐░░██  \n");
		printf(" ██▌░│██████▌░░░▐██☭ ███│ ██\n");
		printf(" ███░│▐███▀▀░░▄░░▀▀███▌│░███  \n");
		printf(" ██▀─┘░░░░░░░▐█▌░░░░░░░└─▀██  \n");
		printf(" ██▄░░░▄▄▄▓░░▀█▀░░▓▄▄▄░░░▄██  \n");
		printf(" ████▄─┘██▌░░░░░░░▐██└─▄████  \n");
		printf(" █████░░▐█─┬┬┬┬┬┬┬─█▌░░█████  \n");
		printf(" ████▌░░░▀┬┼┼┼┼┼┼┼┬▀░░░▐████  \n");
		printf(" █████▄░░░└┴┴┴┴┴┴┴┘░░░▄█████  \n");
		printf(" ███████▄░░░░░░░░░░░▄███████  \n");
		printf("                              \n");
		printf("\n\n");

	 }

	 printf("Fim do jogo!\n\n");
 }
   