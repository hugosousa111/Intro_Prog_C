#include <stdio.h>
#include <stdlib.h>
main(){
	int a,b,c;
	printf("Digite os 3 valores\n");
	scanf("%d %d %d",&a,&b,&c);
	if(a>b){
		if(a>c){
			printf("maior valor ---> %d\n",a);
		}else{
			printf("maior valor ---> %d\n",c);
		}
	}else{
		if(b>c){
			printf("maior valor ---> %d\n",b);
		}else{
			printf("maior valor ---> %d\n",c);
		}
	}
	if(a<b){
		if(a<c){
			printf("menor valor ---> %d\n",a);
		}else{
			printf("menor valor ---> %d\n",c);
		}
	}else{
		if(b<c){
			printf("menor valor ---> %d\n",b);
		}else{
			printf("menor valor ---> %d\n",c);
		}
	}
	float md=(a+b+c)/3;
	printf("media ----> %.2f\n",md);
	system("pause");
	return(0);
}
