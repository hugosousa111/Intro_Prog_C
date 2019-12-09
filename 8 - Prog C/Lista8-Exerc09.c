#include <stdio.h>
#include <stdlib.h>
main(){
	int a,b,somat,aux;
	printf("digite o intervalo\n");
	scanf("%d %d",&a, &b);
	aux=somat=0;
	if (a<b){
		int	cont = a;
		while(cont<=b){
			somat=somat+(a+aux);
			aux++;
			cont++;
		}
	}else{
		int	cont = b;
		while(cont<=a){
			somat=somat+(b+aux);
			aux++;
			cont++;
		}
	}
	printf("soma ---> %d\n",somat);
	system("pause");
	return(0);
}
