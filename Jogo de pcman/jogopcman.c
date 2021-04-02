#include<stdio.h>
#include<stdlib.h>

int main()
{
	//matrix de 5 x 10
	char mapa[5][11];

	FILE* f;

	f = fopen("mapa.txt", "r");

	if (f == 0)
	{
		printf("Erro de leitura no mapa\n");
		exit(1);

     }

    for (int i = 0; i < 5; ++i)

    {

     	fscanf(f, "%s", mapa[i]);

     }

    for (int i = 0; i < 5; ++i)

    {

     	printf("%s\n", mapa[i]);

     }

     fclose(f);

 return 0;
}


