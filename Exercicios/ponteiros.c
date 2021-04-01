#include<stdio.h>

//função recebe como parametro o endereço de memoria da variavel c (ponteiro)
//*c ponteiro que aponta para o edenreço de mermoria da variavel c
void calcula(int *c ){


printf("calcula %d\n",*c );

//(*c) ponteiro entre parentese = conteudo da variavel , valor.
(*c)++;
printf("calcula %d\n",(*c) );



}

int main(){


int c = 10;

printf("%d\n",c );
//passa como parametro o endereço de memoria da vaiavel c
calcula(&c);
printf("%d\n", c);




}