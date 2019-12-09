#include <stdio.h>
#include <stdlib.h>
main(){
	float nota1, nota2;
	printf("Digite a nota 1\n");
	scanf("%f",&nota1);
	printf("Digite a nota 2\n");	
	scanf("%f",&nota2);
	float md=(nota1+nota2)/2;
	if (md>=7){
		printf("APROVADO\n");
	}else if (md>=4){
		float nota_final;
		printf("Digite a nota final\n");	
		scanf("%f",&nota_final);
		float md_final=(nota_final+md)/2;
		if(md_final>=5){
			printf("Aprovado final\n");
		}else{
			printf("Reprovado\n");
		}
	}else{
		printf("Reprovado\n");
	}	
	system("pause");
	return(0);
}
