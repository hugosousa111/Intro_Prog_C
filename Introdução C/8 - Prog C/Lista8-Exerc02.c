#include <stdio.h>
#include <stdio.h>
#include <math.h>
main(){
	float a,b,x;
	printf("Digite dois numeros\n");
	scanf("%f %f",&a, &b);
	printf("----->	%.3f	+	%.3f	=	%.3f\n",a,b,(a+b));
	printf("----->	%.3f	-	%.3f	=	%.3f\n",a,b,(a-b));
	printf("----->	%.3f	*	%.3f	=	%.3f\n",a,b,(a*b));
	printf("----->	%.3f	/	%.3f	=	%.3f\n",a,b,(a/b));
	x=pow(a,b);
	printf("----->	%.3f	^	%.3f	=	%.3f\n",a,b,x);
	system("pause");
	return(0);
}
