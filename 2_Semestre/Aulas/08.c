#include <stdio.h>
#include <locale.h>/*Biblioteca para aparacer sinais ortográficos*/
#include <stdlib.h>
#include <math.h>
#include <unistd.h>


double f(double x){

	return 4*cos(x) - exp(x);
	
}

double df(double x){

	return -4*sin(x) -exp(x);
}

int main()
{
	double x0 =2; // chute inicial
	double E = 0.01; // precisão
	double xnovo,erro;
	int k = 1; //contador de interação

		do
		{
			xnovo = x0 -f(x0) / df(x0);
			erro = (fabs(xnovo -x0)/xnovo);

			x0 +=xnovo;

			printf("x%d =%lf\n",k,xnovo );
			k++;


		} while (erro >= E);

		printf("\nSolução = %lf",xnovo);	
	

	return 0;
}