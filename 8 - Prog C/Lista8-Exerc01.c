#include <stdio.h>
#include <stdlib.h>
#include <math.h>
main(){
	int a,b;
	printf("Digite dois numeros interios\n");
	scanf("%d %d",&a, &b);
	printf("---->   %d  +  %d   =   %d\n", a,b,(a+b));
	printf("---->   %d  -  %d   =   %d\n", a,b,(a-b));
	printf("---->   %d  *  %d   =   %d\n", a,b,(a*b));
	int x= pow(a,b);
	printf("---->   %d  ^  %d   =   %d\n", a,b,x);
	printf("---->   disivisao inteira %d  /  %d   =   %d\n", a,b,(a/b));
	printf("---->   resto da divisao  %d  /  %d   =   %d\n", a,b,(a%b));
	system("pause");
	return(0);
}
