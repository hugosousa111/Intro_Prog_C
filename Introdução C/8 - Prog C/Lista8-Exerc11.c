#include <stdio.h>
#include <stdlib.h>
main(){
	int a, contnum;
	float md,somat,y;
	a=1;
	contnum=0;
	while(a!=0){
		printf("Insira um valor\n");
		scanf("%d", &a);
		somat=somat+a;
		contnum++;
	} 
	contnum--;
	printf("Digitados %d numeros\n",contnum);
	printf("Somatorio ---> %.3f\n",somat);
	y=contnum;
	md = somat/y;
	printf("Media    ----> %.3f\n",md);
	system("pause");
	return(0);
}
