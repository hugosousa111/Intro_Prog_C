#include <stdio.h>
#include <stdlib.h>
main(){
	int x,y;
	printf("digite o valor de x e o valor de y\n");
	scanf("%d %d",&x,&y);
	if (x>y){
		printf("X=%d tem maior valor\n",x);
	}else if(x<y){
		printf("Y=%d tem maior valor\n",y);
	}else{
		printf("X=%d e Y=%d tem os mesmos valores\n",x,y);
	}
	system("pause");
	return(0);
}
