#include <stdio.h>
#include <stdlib.h>
main(){
	int x,y;
	printf("Digite o valor de x\n");
	scanf("%d",&x);
	printf("Digite o valor de y\n");
	scanf("%d",&y);
	printf("o valor de x ---> %d\no valor de y ---> %d\n",x,y);
	x=x+y;
	y=x-y;
	x=x-y;	
	printf("Novos valores\no valor de x ---> %d\no valor de y ---> %d\n",x,y);
	system("pause");
	return(0);
}
