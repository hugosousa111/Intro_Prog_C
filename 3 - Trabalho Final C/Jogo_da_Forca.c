#include <stdio.h>
#include <stdlib.h>  
#include <locale.h>  //biblioteca para acentos e ç
#include <string.h>  //apenas para usar uma função, a strlen, que pega o tamanho da palavra
#include <time.h> 	 //usado para a semente do aleatório
#include <ctype.h>   //usado para usar funções como isalpha, isdigit, toupper, tolower

char palavra[20]; 			 //é o vetor que recebe a palavra do arquivo
char letrasprocuradas[100];  //é o vetor que recebe as letras que o usuário digitou
char resposta[20];			 //este vetor é o que é exibido para o usuário, com as letras que ele for acertando
char letra; 				 //letra que o usuário digita por vez
int contvetorletprocuradas=0;//é a posição atual do vetor letras procuradas
int tentativas;				 //número de chances do usuário

int boneco(){
	/*essa função faz o boneco, de acordo com número de tentativas
	percebisse que ela é chamada várias vezes no código, o usúario errando ou não*/
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
		/*por exemplo, se ele chamar essa função, e o número 
		de tentativas for igual a 5, ele exibe esta forma, 
		apenas com a cabeça do boneco*/
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
	até a palavra pega essa palavra e joga dentro do vetor palavra*/
 	srand(time(NULL)); 					//pega o tempo atual, para fazer o aleatório
 	int aleato = 1 + (rand() % 100); 	/*aqui, ele faz um aleatório, de 0 a 99, por causa do módulo, 
	 e adiciona 1, porque eu posso ir da linha 1 até a linha 100 do arquivo*/
 	FILE *arq;							//porteiro para um arquivo
 	arq=fopen("arquivodepalavras.txt","r");  //abre o arquivo das palavras e joga o ponteiro em arq
	if(arq==NULL){
		//este é apenas um teste, se não for encontrado o arquivo, ele sai do programa
 		printf("\nERRO NO ARQUIVO PALAVRAS\n");
 		system("pause");
 		exit(1);
	}
	char plvr [20]; 		//vetor auxiliar para pegar as palarvras 
	int pfor;
	for(pfor=0; pfor<aleato;pfor++){ 
		/*visto que seria complicado fazer com que o ponteiro 
		vá direto pra linha sorteada, foi colocado dentro de um for, 
		que irá ler todas as palavras até a sorteada, e jogar dentro de plvr*/
		fgets(plvr,20,arq);
	}
	int contforescol;
	for (contforescol=0;contforescol<20;contforescol++){
		//este for "zera" o vetor palavras com '_', para quando chegar em '_', saber que a palavra acabou
		palavra[contforescol]='_';
	}
	for (contforescol=0;contforescol<strlen(plvr)-1;contforescol++){
		//este for joga a palavra sorteada nas primeiras posições do vetor palavra
		palavra[contforescol]=plvr[contforescol];
	}
	fclose(arq);		//comando para fechar o arquivo, para quando eu abri-lo novamente, o ponteiro esteja no inicio 
}

int letrajaprocurada(letra){
	/*pega a letra que o usuário digitou e procura no vetor letrasprocuradas para ver 
	se já foi digitado, se ele a encontrar, retorna 1, se não, joga essa letra dentro desse vetor, e retorna 0*/
	int contforltproc;
	for (contforltproc=0;contforltproc<100;contforltproc++){
		if(letrasprocuradas[contforltproc]==tolower(letra) || letrasprocuradas[contforltproc]==toupper(letra)){
			/*dentro da condição do if, ele testa se a posição do vetor é igual a letra minúscula 
			ou a letra maiúscula usando as funções tolower e toupper*/
			limpaorganiza();
			printf("\nLetra já procurada\n");
			return (1);
		}	
	}
	letrasprocuradas[contvetorletprocuradas]=letra; //se não tiver no vetor, ele adiciona na ultima posição
	contvetorletprocuradas++;				//adiciona mais um, para virar a nova última posição para a próxima letra
	return(0);
}
	
int procuraletra(letra){
	/*depois de testado se já foi digitado, esta função é chamada,
	 ela testa todas as posições do vetor palavra, se tiver alguma 
	 letra igual ao que o usuário digitou ele joga na mesma posicão do vetor resposta */
	int d=0;
	int contltpala;
	for (contltpala=0; palavra[contltpala]!='_'; contltpala++){
		//este for percorre todas as letras até chegar no '_'
		if(palavra[contltpala]==tolower(letra) || palavra[contltpala]==toupper(letra)){ 
			//se tiver na posição a letra que o usário digitou, maiúscula ou minúscula, ele joga dentro do resposta
			resposta[contltpala]=palavra[contltpala];
			d++;
		}
	}if (d!=0){
		/*este if é para resolver um problema, quando o usuário digita uma letra
		ele diminui uma tentativa, mas se ele acertar não era pra diminuir, então
		tentativas recebe mais um, para ficar do jeito inicial*/
		tentativas++;
	}
}

int ganhou(){
	//Confere se dentro do vetor resposta tem letras e não mais '_', apenas no tamanho da palavra sorteada
	int contforgan;
	for(contforgan=0;palavra[contforgan]!='_'; contforgan++){
		//percorre todo o vetor palavra
		if (resposta[contforgan]=='_'){
			//se retornar 0, é porque ele não ganhou ainda
			return(0);
		}
	}
	return(1);
}

int zerador(){
	//"zera" as variáveis e vetores para jogar novamente
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
	/*essa função irá limpar a tela, para dar 
	a impressão de que o jogo só atualiza os valores do vetor resposta, e o boneco
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
	setlocale(LC_ALL, "Portuguese");	//apenas para poder usar os acentos e ç's nas exibições
	do{ 	 			//este "do while" é o que dá ao jogador a opção jogar novamente 
	zerador();			//inicia as variáveis, ou zera caso seja outra rodada
		while(tentativas>0){	//ele tem 6 chances para acertar,
			limpaorganiza();	//chama para organizar a tela de saída
			do{				//este "do while" é o que força o jogador a digitar uma letra ainda não digitada
				do{			//este "do while" é o que força o jogador a digitar um caractere do alfabeto
					printf("\n>Você tem %d tentativas<\n",tentativas);
					printf("\nDigite uma letra\n >");
					setbuf(stdin, NULL);		//para evitar problemas, "zeramos" o buffer
					letra = getch(); 			//a função getch, faz com que o usúario só digite uma letra por vez, sem esperar o enter
					if(isalpha(letra)){			//testa se é uma letra, se for, ele pula para o teste
						auxeletra=0;
						continue;
					}
					limpaorganiza();
					printf("\n>> Isso não é letra\n",letra);
					auxeletra=1;
				}while(auxeletra);				//se for 1, é porque não era uma letra, se 0, porque era
			}while(letrajaprocurada(letra));	//chama letrajaprocurada e faz seus testes
			procuraletra(letra);			//se não tiver digitado, ele testa se tem dentro da palavra
			tentativas--;		
			limpaorganiza();
			printf("\n");
			if (ganhou()==1){		//testa se ele ganhou, se sim exibe a mensagem e dar um break no while das tentativas
				printf("Você acertou\n");
				break;
			}
		}if(tentativas==0 && ganhou()==0){  //se tentativas for 0, e ganhou retornar 0, é porque o usuário perdeu
			printf("Você perdeu, a palavra era ");
			int mostrar;
			for(mostrar=0; palavra[mostrar]!='_';mostrar++){
				//este for exibe a palavra que o usúario não descobriu
				printf("%c",palavra[mostrar]);
			}
			printf("\n");
		}
		do{ 		//força a pessoa digitar 1 ou 2, para sair deste "do while"
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
