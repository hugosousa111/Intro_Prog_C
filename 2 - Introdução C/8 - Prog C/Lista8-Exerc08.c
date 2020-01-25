#include <stdio.h>
#include <stdlib.h>
main(){
	int a, cont;
	printf("insira um valor\n");
	scanf("%d",&a);
	for (cont=1; cont<=20;cont++){
		printf("--%d--\n",(a+cont));
	}
	system("pause");
	return(0);
}
