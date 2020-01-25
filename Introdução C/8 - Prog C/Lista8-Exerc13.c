#include <stdio.h>
#include <stdlib.h>
main(){
	int a, b, cont, result,resto,quociente,resultadoexpo,contparecelas;
	printf("Digite os dois valores\n");
	scanf("%d %d", &a,&b);
	cont=0;
	result=0;
	while(cont<b){
		result=result+a;
		cont++;
	}
	printf("---> %d   *   %d   =   %d  \n",a,b,result);
	resto=a;
	quociente=0;
	while(resto>=b){
		resto=resto-b;
		quociente++;	
	}
	printf("Quociente --->  %d\n",quociente);
	printf("Resto    ---->  %d\n",resto);	
	resultadoexpo=1;
	contparecelas=0;		
	while (contparecelas<b){
		result=0;
		cont=0;
		while(cont<resultadoexpo){
			result=result+a;
			cont++;
		}
		resultadoexpo=result;
		contparecelas++;
	}
	printf("---> %d   ^   %d   =   %d  \n",a,b,resultadoexpo);	
	system("pause");
	return(0);
}
