#include <stdio.h>
#include <stdlib.h>  
#include <locale.h>  //biblioteca para acentos e �
#include <string.h>  //apenas para usar uma fun��o, a strlen, que pega o tamanho da palavra
#include <time.h> 	 //usado para a semente do aleat�rio
#include <ctype.h>   //usado para usar fun��es como isalpha, isdigit, toupper, tolower

char palavra[20]; 			 //� o vetor que recebe a palavra do arquivo
char letrasprocuradas[100];  //� o vetor que recebe as letras que o usu�rio digitou
char resposta[20];			 //este vetor � o que � exibido para o usu�rio, com as letras que ele for acertando
char letra; 				 //letra que o usu�rio digita por vez
int contvetorletprocuradas=0;//� a posi��o atual do vetor letras procuradas
int tentativas;				 //n�mero de chances do usu�rio

int boneco(){
	/*essa fun��o faz o boneco, de acordo com n�mero de tentativas
	percebisse que ela � chamada v�rias vezes no c�digo, o us�ario errando ou n�o*/
	if (tentativas == 6){
		printf("____________________\n");
		printf("         |         |\n");
		printf("                   |\n");
		printf("                   |\n");
		printf("                   |\n");
		printf("                   |\n");
		printf("                   |\n");
		printf("                   |\n");
		printf("                   |\n");
		printf("                   |\n");
		printf("____________________\n");
		printf("\n\n\n");
	}	
	if (tentativas == 5){			
		/*por exemplo, se ele chamar essa fun��o, e o n�mero 
		de tentativas for igual a 5, ele exibe esta forma, 
		apenas com a cabe�a do boneco*/
		printf("____________________\n");
		printf("         |         |\n");
		printf("       (^ ^)       |\n");
		printf("                   |\n");
		printf("                   |\n");
		printf("                   |\n");
		printf("                   |\n");
		printf("                   |\n");
		printf("                   |\n");
		printf("                   |\n");
		printf("____________________\n");
		printf("\n\n\n");
	}
	if (tentativas == 4){
		printf("____________________\n");
		printf("         |         |\n");
		printf("       (^ ^)       |\n");
		printf("       __|         |\n");
		printf("      |            |\n");
		printf("      |            |\n");
		printf("                   |\n");
		printf("                   |\n");
		printf("                   |\n");
		printf("                   |\n");
		printf("____________________\n");
		printf("\n\n\n");
	}
	if (tentativas == 3){
		printf("____________________\n");
		printf("         |         |\n");
		printf("       (^ ^)       |\n");
		printf("       __|__       |\n");
		printf("      |     |      |\n");
		printf("      |     |      |\n");
		printf("                   |\n");
		printf("                   |\n");
		printf("                   |\n");
		printf("                   |\n");
		printf("____________________\n");
		printf("\n\n\n");
	}
	if (tentativas == 2){
		printf("____________________\n");
		printf("         |         |\n");
		printf("       (^ ^)       |\n");
		printf("       __|__       |\n");
		printf("      |  |  |      |\n");
		printf("      |  |  |      |\n");
		printf("         |         |\n");
		printf("                   |\n");
		printf("                   |\n");
		printf("                   |\n");
		printf("____________________\n");
		printf("\n\n\n");
	}
	if (tentativas == 1){
		printf("____________________\n");
		printf("         |         |\n");
		printf("       (^ ^)       |\n");
		printf("       __|__       |\n");
		printf("      |  |  |      |\n");
		printf("      |  |  |      |\n");
		printf("       __|         |\n");
		printf("      |            |\n");
		printf("     _|            |\n");
		printf("                   |\n");
		printf("____________________\n");
		printf("\n\n\n");
	}
	if (tentativas == 0){
		printf("____________________\n");
		printf("         |         |\n");
		printf("       (^ ^)       |\n");
		printf("       __|__       |\n");
		printf("      |  |  |      |\n");
		printf("      |  |  |      |\n");
		printf("       __|__       |\n");
		printf("      |     |      |\n");
		printf("     _|     |_     |\n");
		printf("                   |\n");
		printf("____________________\n");
		printf("\n\n\n");
	}
}

int escolhepalavra(){
	/* sorteia uma palavra do arquivo, percorre o arquivo 
	at� a palavra pega essa palavra e joga dentro do vetor palavra*/
 	srand(time(NULL)); 					//pega o tempo atual, para fazer o aleat�rio
 	int aleato = 1 + (rand() % 100); 	/*aqui, ele faz um aleat�rio, de 0 a 99, por causa do m�dulo, 
	 e adiciona 1, porque eu posso ir da linha 1 at� a linha 100 do arquivo*/
 	FILE *arq;							//porteiro para um arquivo
 	arq=fopen("arquivodepalavras.txt","r");  //abre o arquivo das palavras e joga o ponteiro em arq
	if(arq==NULL){
		//este � apenas um teste, se n�o for encontrado o arquivo, ele sai do programa
 		printf("\nERRO NO ARQUIVO PALAVRAS\n");
 		system("pause");
 		exit(1);
	}
	char plvr [20]; 		//vetor auxiliar para pegar as palarvras 
	int pfor;
	for(pfor=0; pfor<aleato;pfor++){ 
		/*visto que seria complicado fazer com que o ponteiro 
		v� direto pra linha sorteada, foi colocado dentro de um for, 
		que ir� ler todas as palavras at� a sorteada, e jogar dentro de plvr*/
		fgets(plvr,20,arq);
	}
	int contforescol;
	for (contforescol=0;contforescol<20;contforescol++){
		//este for "zera" o vetor palavras com '_', para quando chegar em '_', saber que a palavra acabou
		palavra[contforescol]='_';
	}
	for (contforescol=0;contforescol<strlen(plvr)-1;contforescol++){
		//este for joga a palavra sorteada nas primeiras posi��es do vetor palavra
		palavra[contforescol]=plvr[contforescol];
	}
	fclose(arq);		//comando para fechar o arquivo, para quando eu abri-lo novamente, o ponteiro esteja no inicio 
}

int letrajaprocurada(letra){
	/*pega a letra que o usu�rio digitou e procura no vetor letrasprocuradas para ver 
	se j� foi digitado, se ele a encontrar, retorna 1, se n�o, joga essa letra dentro desse vetor, e retorna 0*/
	int contforltproc;
	for (contforltproc=0;contforltproc<100;contforltproc++){
		if(letrasprocuradas[contforltproc]==tolower(letra) || letrasprocuradas[contforltproc]==toupper(letra)){
			/*dentro da condi��o do if, ele testa se a posi��o do vetor � igual a letra min�scula 
			ou a letra mai�scula usando as fun��es tolower e toupper*/
			limpaorganiza();
			printf("\nLetra j� procurada\n");
			return (1);
		}	
	}
	letrasprocuradas[contvetorletprocuradas]=letra; //se n�o tiver no vetor, ele adiciona na ultima posi��o
	contvetorletprocuradas++;				//adiciona mais um, para virar a nova �ltima posi��o para a pr�xima letra
	return(0);
}
	
int procuraletra(letra){
	/*depois de testado se j� foi digitado, esta fun��o � chamada,
	 ela testa todas as posi��es do vetor palavra, se tiver alguma 
	 letra igual ao que o usu�rio digitou ele joga na mesma posic�o do vetor resposta */
	int d=0;
	int contltpala;
	for (contltpala=0; palavra[contltpala]!='_'; contltpala++){
		//este for percorre todas as letras at� chegar no '_'
		if(palavra[contltpala]==tolower(letra) || palavra[contltpala]==toupper(letra)){ 
			//se tiver na posi��o a letra que o us�rio digitou, mai�scula ou min�scula, ele joga dentro do resposta
			resposta[contltpala]=palavra[contltpala];
			d++;
		}
	}if (d!=0){
		/*este if � para resolver um problema, quando o usu�rio digita uma letra
		ele diminui uma tentativa, mas se ele acertar n�o era pra diminuir, ent�o
		tentativas recebe mais um, para ficar do jeito inicial*/
		tentativas++;
	}
}

int ganhou(){
	//Confere se dentro do vetor resposta tem letras e n�o mais '_', apenas no tamanho da palavra sorteada
	int contforgan;
	for(contforgan=0;palavra[contforgan]!='_'; contforgan++){
		//percorre todo o vetor palavra
		if (resposta[contforgan]=='_'){
			//se retornar 0, � porque ele n�o ganhou ainda
			return(0);
		}
	}
	return(1);
}

int zerador(){
	//"zera" as vari�veis e vetores para jogar novamente
	tentativas=6;
	contvetorletprocuradas=0;
	escolhepalavra();	
	int contforze;
	for (contforze=0;contforze<20;contforze++){
		resposta[contforze]='_'; 
	}
	for (contforze=0;contforze<100;contforze++){
		letrasprocuradas[contforze]='_'; 
	}
}

int limpaorganiza(){
	/*essa fun��o ir� limpar a tela, para dar 
	a impress�o de que o jogo s� atualiza os valores do vetor resposta, e o boneco
	sendo chamada varias vezes durante o jogo*/
	system	("CLS");
	printf("********************************  JOGO DA FORCA  ******************************\n\n");
	boneco();
	exibir();
}

int exibir(){
	//exibe o vetor resposta
	int contexib=1;
	for (contexib=0;palavra[contexib]!='_'; contexib++){
		//percorre todo o vetor palavra, para mostrar o tamanho de resposta
		printf(" %c ",resposta[contexib]);
	}
	printf("\n");
}

int main(){
	int contmostrar,auxeletra;
	char continuar=' ';
	setlocale(LC_ALL, "Portuguese");	//apenas para poder usar os acentos e �'s nas exibi��es
	do{ 	 			//este "do while" � o que d� ao jogador a op��o jogar novamente 
	zerador();			//inicia as vari�veis, ou zera caso seja outra rodada
		while(tentativas>0){	//ele tem 6 chances para acertar,
			limpaorganiza();	//chama para organizar a tela de sa�da
			do{				//este "do while" � o que for�a o jogador a digitar uma letra ainda n�o digitada
				do{			//este "do while" � o que for�a o jogador a digitar um caractere do alfabeto
					printf("\n>Voc� tem %d tentativas<\n",tentativas);
					printf("\nDigite uma letra\n >");
					setbuf(stdin, NULL);		//para evitar problemas, "zeramos" o buffer
					letra = getch(); 			//a fun��o getch, faz com que o us�ario s� digite uma letra por vez, sem esperar o enter
					if(isalpha(letra)){			//testa se � uma letra, se for, ele pula para o teste
						auxeletra=0;
						continue;
					}
					limpaorganiza();
					printf("\n>> Isso n�o � letra\n",letra);
					auxeletra=1;
				}while(auxeletra);				//se for 1, � porque n�o era uma letra, se 0, porque era
			}while(letrajaprocurada(letra));	//chama letrajaprocurada e faz seus testes
			procuraletra(letra);			//se n�o tiver digitado, ele testa se tem dentro da palavra
			tentativas--;		
			limpaorganiza();
			printf("\n");
			if (ganhou()==1){		//testa se ele ganhou, se sim exibe a mensagem e dar um break no while das tentativas
				printf("Voc� acertou\n");
				break;
			}
		}if(tentativas==0 && ganhou()==0){  //se tentativas for 0, e ganhou retornar 0, � porque o usu�rio perdeu
			printf("Voc� perdeu, a palavra era ");
			int mostrar;
			for(mostrar=0; palavra[mostrar]!='_';mostrar++){
				//este for exibe a palavra que o us�ario n�o descobriu
				printf("%c",palavra[mostrar]);
			}
			printf("\n");
		}
		do{ 		//for�a a pessoa digitar 1 ou 2, para sair deste "do while"
			printf("\n1) Jogar Novamente\n2) Sair\n >");
			setbuf(stdin, NULL);
			continuar = getch();
			if(continuar=='1' || continuar=='2'){
				break;
			}
			limpaorganiza();
			printf("\nEscolha 1 ou 2\n");
		}while(1);
	}while(continuar=='1'); 
	printf("\nFIM DO JOGO\n");
	system("pause");
	return(0);
}
