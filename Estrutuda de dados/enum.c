#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

enum dias_da_semana{segunda,terca,quarta,quinta,sexta,sabado,domingo};

void main(void)
{
	enum dias_da_semana d1 ,d2;
	d1 = segunda;
	d2 = sexta;

	if (d1 ===d2)
	{
		printf("\nO mesmo dia");
	}
	else{
		printf("\nDias diferentes");
	}
}