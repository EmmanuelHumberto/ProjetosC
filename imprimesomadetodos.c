#include<stdio.h>


int main()

{


int contagem = 1;
int soma;
int resultado;


while(contagem < 100){


contagem++;	

soma = soma + contagem; 	


//printf("%d\n",soma);




}

printf("%d\n",(contagem*(contagem+1))/2);

}