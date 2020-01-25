#include <stdio.h>
#include <stdlib.h>
main(){
	int a,b,cont,aux;
	printf("digite o intervalo\n");
	scanf("%d %d",&a, &b);
	if (a<b){
		if(b>10){
			for (cont=10; cont<(b-1);cont=cont+2){
				printf("--%d--\n",(cont+2));
			}	
		}else{
			printf("Nenhum numero par > que 10 no intervalo de %d ate %d\n",a,b);
		}
	}else{
		if(a>10){
			for (cont=10; cont<(a-1);cont=cont+2){
				printf("--%d--\n",(cont+2));
			}	
		}else{
			printf("Nenhum numero par > que 10 no intervalo de %d ate %d\n",b,a);
		}
	}
	system("pause");
	return(0);
}
