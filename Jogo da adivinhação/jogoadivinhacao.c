    #include<stdio.h>
#include<stdlib.h>
#include<time.h>


void cabecalhoBV(){

  //Imprime o cabeçalho do jogo.

	printf("\n");
	printf("**************************************************\n");
	printf("*  Seja bem vindo! Ao nosso jogo de Adivinhacao! *\n");
   	printf("**************************************************\n");
   	printf("\n");





    printf("               | >>>                                                   \n");
    printf("                              |                                        \n");
    printf("                | >>> _ _ | _ _ | >>>                                  \n");
    printf("                | |; | |; | |; | |                                     \n");
    printf("            _ _ | _ _ \\. . / _ _ | _ _                                \n");
    printf("           \\ .. / ||; . | \\. . /                                     \n");
    printf("            \\. , / ||:. | \\:. /                                      \n");
    printf("             ||: | _ _ || _. _ | _ _ ||: |                             \n");
    printf("             ||:. ||| _ |; | _ |; | _ |; | _ |; | _ |; || :. |         \n");
    printf("             ||: ||. . . . ||:. |                                      \n");
    printf("             ||:. || . . . . , ||: | \\, /                             \n");
    printf("             ||: ||:, _______. ||:, | / `\\                            \n");
    printf("             ||: || . / +++++++ \\. ||: |                              \n");
    printf("             ||: ||. | +++++++ | . ||:. |                              \n");
    printf("          __ ||:. ||:, | +++++++ |. . _ || _ |                         \n");
    printf(" ____-- `~ '- ~~ __ |. | +++++ __ | ---- ~ ~ `---, ___                 \n");
    printf("- ~ - ~ ~ ---__ |, - ~ '~~ ----_____- ~' `~ ---- ~~                    \n");
    printf(" \n\n");


	printf("☭ ʕ•̫͡•ʕ•̫͡•ʔ•̫͡•ʔ•̫͡•ʕ•̫͡•ʔ•̫͡•ʕ•̫͡•ʕ•̫͡•ʔ•̫͡•ʔ•̫͡•ʕ•̫͡•ʔ•̫͡•ʔ ☭\n\n");

    printf("Tente adivinhar o numero que estou pensando.\n");

    printf("\n");
}


void cabecalhoacerto(){

	//Imprime o cabeçalho de vitória

    	printf("\n\n");
	printf("***************************\n");
	printf("✅ ");
	printf(" Parabens você ganhou! *\n");
    	printf("***************************\n");
   	 printf("\n");

	printf("   ☆┌─┐　─┐☆           \n");
	printf("  　│▒│ /▒/           \n");
	printf("  　│▒│/▒/            \n");
	printf("  　│▒ /▒/─┬─┐        \n");
	printf("  　│▒│▒|▒│▒│ =]~~    \n");
	printf("  ┌┴─┴─┐-┘─┘          \n");
	printf("  │▒┌──┘▒▒▒│          \n");
	printf("  └┐▒▒▒▒▒▒┌┘          \n");
	printf("  　└┐▒▒▒▒┌┘       ☭  \n");
	printf("                      \n");

}


void cabecalhoerro(){

	//Imprime o cabeçalho de erro.

    printf("\n\n");
    printf("*****************************\n");
    printf("* Infelizmente você errou!  *\n");
    printf("*****************************\n");
    printf("\n");
}

int main(){

    cabecalhoBV();

    int segundos = time(0);

    srand(segundos);

    int numerogrande = rand();

    int numerosecreto = numerogrande % 100;
    
    int chute;

    int tentativas = 1;

    double pontos = 1000;

    int ganhou = 0;

    int numerodetentativas;

    int acertou=0; 
    
    int nivel;

    printf("Escolha o nível de dificuldade?\n\n");
    printf("(1) Fácil\n");
    printf("(2) Médio\n");
    printf("(3) Difícil\n");
    printf("\nEscolha: ");
    scanf("%d", &nivel);

    switch(nivel) {
        case 1:
            numerodetentativas = 20;
            break;

        case 2:
            numerodetentativas = 15;
            break;

        default:
            numerodetentativas = 6;
            break;

     }
    
   for (int i = 1; i <= numerodetentativas;i++){

        printf("\n\n");
   	
        printf("Tetantiva %d \n",tentativas);

        printf("===================\n");

	    printf("Qual é o seu chute?\n");

	    scanf("%d",&chute);

	    if(chute < 0){

	    	printf("Não permitido chutar numeros negativos");
	    	
	    	continue;

	    }	

	 	acertou = (chute == numerosecreto);

	    int erroumenos = (chute < numerosecreto);
 
	    if(acertou){

	    	cabecalhoacerto;

	    	break;
	    }
  	
	    else if(erroumenos){	
	    	 
			 cabecalhoerro();
			 printf("❌ ");	
			 printf("%d foi MENOR que o numero secreto\n",chute);
		     printf("\n");

		     }

		else {

			  
		     cabecalhoerro();
		     printf("❌ ");	
		     printf("%d foi MAIOR que o numero secreto\n",chute);
	         printf("\n");

	         }

	     tentativas++;

	     double pontosperdidos = abs(chute - numerosecreto)/(double)2;
	     pontos = pontos - pontosperdidos;
     
	 
	 }

    printf("Fim de jogo!\n");

    if(acertou) {

    	cabecalhoacerto();
        printf("Você acertou em %d tentativas!\n", tentativas);
        printf("Total de pontos: %.1f\n", pontos);

    } else {

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



    printf("Você perdeu! Tente de novo!\n");

    }


}	
