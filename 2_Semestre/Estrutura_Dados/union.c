#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#define GRAUS 'G'
#define RAD 'R'

union angulo{

	int graus;
	float radianos

};

void main()
{
	union angulo ang;
	char op;
	printf("\nNumeros em graus ou radianos ?(G/R) :");
	scanf("%c",&op);

	if (op == GRAUS)
	{
		ang.graus = 180;
		printf("\nAngulo : %d\n",ang.graus);
	}
	else
	{
		if (op == RAD)
		{
			ang.radianos = 3.1415;
			printf("\nAngulo : %f\n",ang.radianos);
		}
		else
		{
			printf("\nEntrada invalida!", );
		}

	}
	return 0;
}