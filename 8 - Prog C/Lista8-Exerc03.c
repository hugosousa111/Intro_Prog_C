#include <stdio.h>
#include <stdlib.h>
main(){
	int x, y, aux;
	printf("Digite um numero para x\n");
	scanf("%d",&x);
	printf("Digite um numero para y\n");
	scanf("%d",&y);
	printf("o valor de x ---> %d\no valor de y ---> %d\n",x,y);
	aux=x;
	x=y;
	y=aux;
	printf("Novos valores\no valor de x ---> %d\no valor de y ---> %d\n",x,y);
	system("pause");
	return(0);
}
