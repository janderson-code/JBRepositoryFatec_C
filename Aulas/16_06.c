#include <stdio.h>
#include <locale.h>
#include<stdlib.h>
#include<math.h>
#include <unistd.h>

int somatoria (int x){

if (x==0)
	return 0;
else
	return x+somatoria(x-1);


}

long double fatorial(long double x){

if(x<=0)
	return 1;
else
	return x*fatorial(x-1);
}

int main()
{		
		long double num;
		printf("%\nDigite o numero que deseja saber o fatorial\n");
		scanf(" %lf",&num);
		printf("\n O fatorial de % = %le\n",num,fatorial(num));

	

	sleep(2);
	return 0;
}