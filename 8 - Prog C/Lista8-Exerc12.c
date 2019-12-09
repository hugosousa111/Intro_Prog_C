#include <stdio.h>
#include <stdlib.h>
#include <math.h>
main(){
	int base, expoente, resultadoexpo,contparecelas,result,cont,x;
	printf("Digite a base\n");
	scanf("%d",&base);
	printf("Digite o expoente\n");
	scanf("%d",&expoente);
	resultadoexpo=1;
	contparecelas=0;
	while (contparecelas<expoente){
		result=0;
		cont=0;
		while(cont<resultadoexpo){
			result=result+base;
			cont++;
		}
		resultadoexpo=result;
		contparecelas++;
	}
	printf("Resultado ---> %d\n",resultadoexpo);	
	system("pause");
	return(0);
}
