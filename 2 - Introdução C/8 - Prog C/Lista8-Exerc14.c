#include <stdio.h>
#include <stdlib.h>
main(){
	int qlinha,linha,j;
	printf("Digite o numero de linhas\n");
	scanf("%d",&qlinha);
	for(linha=1;linha<=qlinha;linha++){
		for(j=1;j<=(qlinha-linha);j++){
			printf(".");
		}
		for(j=1;j<=((qlinha-(qlinha-linha))*2-1);j++){
			printf("*");
		}
		for(j=1;j<=(qlinha-linha);j++){
			printf(".");
		}
		for(j=1;j<=(qlinha-linha);j++){
			printf(".");
		}
		for(j=1;j<=((qlinha-(qlinha-linha))*2-1);j++){
			printf("*");
		}
		for(j=1;j<=(qlinha-linha);j++){
			printf(".");
		}
		printf("\n");
	}
	system("pause");
	return(0);
}
