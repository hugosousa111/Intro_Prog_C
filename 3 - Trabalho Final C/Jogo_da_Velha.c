#include <stdio.h>
#include <stdlib.h>
#include <locale.h>  //biblioteca para acentos e ç
#include <time.h>    //biblioteca para pegar a hora para os sorteios

char tabela[3][3]; 					//tabela será a matriz do jogo, onde irá guardar as posições
char nomej1[100], nomej2[100];		//vetores nomes, para guardar os nomes dos jogadores,
char xo;  							//xo é uma variavel auxiliar, que guarda se é X ou O
char continuar=' ',mododejogo=' ';
int l,c,jogadacom=1;
char posi;

int ganhou(){
	/* essa função é uma das principais do código, pois ela irá testar todas 
		as posibilidades de vitoria para o X e para o O
	*/
	//testes para o X
	if(tabela[0][0]=='X' && tabela[0][1]=='X' && tabela[0][2]=='X'){
		//por exemplo se a posição 1,2,3 estiver ocupada com X é porque o jogador do X ganhou
		limpaorganiza();
		printf("\nFIM DE JOGO, JOGADOR %s VENCEU\n",nomej1);
		return(1);
	}else if(tabela[0][0]=='X' && tabela[1][0]=='X' && tabela[2][0]=='X'){
		limpaorganiza();
		printf("\nFIM DE JOGO, JOGADOR %s VENCEU\n",nomej1);
		return(1);
	}else if(tabela[0][0]=='X' && tabela[1][1]=='X' && tabela[2][2]=='X'){
		limpaorganiza();
		printf("\nFIM DE JOGO, JOGADOR %s VENCEU\n",nomej1);
		return(1);
	}else if(tabela[0][1]=='X' && tabela[1][1]=='X' && tabela[2][1]=='X'){
		limpaorganiza();
		printf("\nFIM DE JOGO, JOGADOR %s VENCEU\n",nomej1);
		return(1);	
	}else if(tabela[0][2]=='X' && tabela[1][2]=='X' && tabela[2][2]=='X'){
		limpaorganiza();
		printf("\nFIM DE JOGO, JOGADOR %s VENCEU\n",nomej1);
		return(1);	
	}else if(tabela[0][2]=='X' && tabela[1][1]=='X' && tabela[2][0]=='X'){
		limpaorganiza();
		printf("\nFIM DE JOGO, JOGADOR %s VENCEU\n",nomej1);
		return(1);	
	}else if(tabela[1][0]=='X' && tabela[1][1]=='X' && tabela[1][2]=='X'){
		limpaorganiza();
		printf("\nFIM DE JOGO, JOGADOR %s VENCEU\n",nomej1);
		return(1);	
	}else if(tabela[2][0]=='X' && tabela[2][1]=='X' && tabela[2][2]=='X'){
		limpaorganiza();
		printf("\nFIM DE JOGO, JOGADOR %s VENCEU\n",nomej1);
		return(1);	
	}
	//testes para o O
	if(tabela[0][0]=='O' && tabela[0][1]=='O' && tabela[0][2]=='O'){
		//por exemplo se a posição 1,2,3 estiver ocupada com O é porque o jogador do O ganhou
		limpaorganiza();
		printf("\nFIM DE JOGO, JOGADOR %s VENCEU\n",nomej2);
		return(1);
	}else if(tabela[0][0]=='O' && tabela[1][0]=='O' && tabela[2][0]=='O'){
		limpaorganiza();
		printf("\nFIM DE JOGO, JOGADOR %s VENCEU\n",nomej2);
		return(1);
	}else if(tabela[0][0]=='O' && tabela[1][1]=='O' && tabela[2][2]=='O'){
		limpaorganiza();
		printf("\nFIM DE JOGO, JOGADOR %s VENCEU\n",nomej2);
		return(1);
	}else if(tabela[0][1]=='O' && tabela[1][1]=='O' && tabela[2][1]=='O'){
		limpaorganiza();
		printf("\nFIM DE JOGO, JOGADOR %s VENCEU\n",nomej2);
		return(1);	
	}else if(tabela[0][2]=='O' && tabela[1][2]=='O' && tabela[2][2]=='O'){
		limpaorganiza();
		printf("\nFIM DE JOGO, JOGADOR %s VENCEU\n",nomej2);
		return(1);	
	}else if(tabela[0][2]=='O' && tabela[1][1]=='O' && tabela[2][0]=='O'){
		limpaorganiza();
		printf("\nFIM DE JOGO, JOGADOR %s VENCEU\n",nomej2);
		return(1);	
	}else if(tabela[1][0]=='O' && tabela[1][1]=='O' && tabela[1][2]=='O'){
		limpaorganiza();
		printf("\nFIM DE JOGO, JOGADOR %s VENCEU\n",nomej2);
		return(1);	
	}else if(tabela[2][0]=='O' && tabela[2][1]=='O' && tabela[2][2]=='O'){
		limpaorganiza();
		printf("\nFIM DE JOGO, JOGADOR %s VENCEU\n",nomej2);
		return(1);	
	}
	return(0);
}	

int testaposi(posi){
	/* essa função pega a posição que o usuario digitou, e de acordo
	 insere valores dentro de l e c, que representam a posição na matriz
	 também confere se o usuario digitou de 1 a 9, e se a posição já estava ocupada
	*/
	if(!(isdigit(posi))){
		//testa se o que a pessoa digitou é um dígito
		limpaorganiza();
		printf("\nDIGITE APENAS NÚMEROS VÁLIDOS\n");
		return(1);
	}
	//o switch testa por exemplo, se a pessoa digitar 1, ela se refere a linha 0 e a coluna 0 da tabela
	switch (posi){
		case '1':
			l=0;
			c=0;
			break;
		case '2':
			l=0;
			c=1;
			break;
		case '3':
			l=0;
			c=2;
			break;
		case '4':
			l=1;
			c=0;	
			break;
		case '5':
			l=1;
			c=1;
			break;
		case '6':
			l=1;
			c=2;
			break;
		case '7':
			l=2;
			c=0;
			break;
		case '8':
			l=2;
			c=1;
			break;
		case '9':
			l=2;
			c=2;
			break;
		default:
			//caso o usuário digite algum digito diferente de 1 a 9
			limpaorganiza();
			printf("\nESCOLHA UMA POSIÇÃO VÁLIDA, DE 1 A 9\n");
			return(1);
	}
	if(tabela[l][c]=='X' || tabela[l][c]=='O'){
		//este if testa se a posição que a pessoa escolheu já foi escolhida, para não haver sobreposição 
		limpaorganiza();
		printf("\nPOSIÇÃO JÁ OCUPADA, ESCOLHA OUTRA\n");
		return(1);
	}
	else{
		//caso a posição escolhida não tiver sido ocupada, ele insere o valor de xo dentro da posição da matriz
		tabela[l][c]=xo;
		return(0);
	}
}

int limpaorganiza(){
	/*essa função irá limpar a tela, para dar 
	a impressão de que o jogo só atualiza os valores na matriz
	sendo chamada varias vezes durante o jogo*/
	system	("CLS");
	exibir();
	printf("> %s será o X\n\n",nomej1);
	printf("> %s será o O\n\n",nomej2);		
}

int velha(){
	/* essa função é tão importante quanto a ganhou, pois confere o empate,
	se todas as posições ja estivem alteradas, e o ganhou não tiver retornado "1", é porque deu velha
	*/
	if(	tabela[0][0]!='1' && tabela[0][1]!='2' && tabela[0][2]!='3' 
		&& tabela[1][0]!='4' && tabela[1][1]!='5' && tabela[1][2]!='6' 
		&& tabela[2][0]!='7' && tabela[2][1]!='8' && tabela[2][2]!='9'){
		limpaorganiza();
		printf("DEU VELHA, SEM VENCEDORES\n");
		return(1);
	}
	return(0);
}

int jogada(){
	/*esta função é responsavel pela leitura das posições, e pela chamadas de funções 
	como ganhou e velha, o jogo realmente começa e termina nessa função */
	do{
		do{ //este "do while" força a digitar uma posição valida, e que não esteja ocupada
			printf(">> %s escolha uma posição: \n > ",nomej1);
			setbuf(stdin, NULL); 	//para evitar problemas, "zeramos" o buffer
			posi = getch();			//força o usuario a digitar apenas um caractere por vez
			xo='X';					//o jogador 1 é sempre o X
		}while(testaposi(posi));    //chama o testaposi pra ver se o que digitou foi válido
		if (ganhou()){		//ver se o jogador 1 ganhou, se sim sai do looping
			break;
		}
		if(velha()){		//testa se deu velha, se sim, sai do looping
			break;
		}
		limpaorganiza();	//limpa a tela, e chama de novo a tabela
		do{		//este "do while" força a digitar uma posição valida, e que não esteja ocupada, mas agr para o jogador 2
			printf(">> %s escolha uma posição: \n > ",nomej2);
			setbuf(stdin, NULL);
			posi = getch();
			xo='O';			//o jogador 2 é sempre o O
		}while(testaposi(posi)); //faz os mesmos testes
		if (ganhou()){
			break;
		}
		if(velha()){
			break;
		}
		limpaorganiza();
	}while(1);	//ira girar, até uma condição do ganhou ou do velha ser valida, e ter um break
}

int exibir(){
	//essa função exibe a matriz, e é chamada varias vezes pela função limpaorganiza
	printf("********************************  JOGO DA VELHA  ******************************\n\n");	
	int contforlinha=0, contforexicoluna;
	for (contforlinha=0; contforlinha<3; contforlinha++){
		printf("                            ");//para centralizar a tabela
		for(contforexicoluna=0; contforexicoluna<3; contforexicoluna++){
			//os dois "for"s passam por todas as linhas e todas as colunas
			printf("[  %c  ] ",tabela[contforlinha][contforexicoluna]);
		}
		if(contforlinha!=2){
			printf("\n                             _______________________\n");
		}
	}
	printf("\n\n");
}

void zerador(){
	//essa função irá "zerar" todas as variaveis, vetores e a matriz, para ser jogado novamente
	tabela[0][0]='1';
	tabela[0][1]='2';
	tabela[0][2]='3';
	tabela[1][0]='4';
	tabela[1][1]='5';
	tabela[1][2]='6';
	tabela[2][0]='7';
	tabela[2][1]='8';
	tabela[2][2]='9';
	int contfornome;
	jogadacom=1;
	for(contfornome=0; contfornome<100; contfornome++){
		nomej1[contfornome]='_';
		nomej2[contfornome]='_';
	}
} 

//////////////////////////as próximas funções, são especificas do jogo contra o computador //////////////////////////////
int advganhar(){
	/*esta função testa se tem como o adverário ganhar, no caso ela é sempre 
	chamada depois da função pcganhar(), pois a preferencia é ganhar*/
	if(tabela[0][0]=='X' && tabela[0][1]=='X'&& tabela[0][2]=='3'){
		/*por exemplo se tiver X no 1 e no 2, e na posição 3 estiver 
		com seu valor atual, a pessoa está para ganhar, e o computador joga na posição livre*/
		tabela[0][2]='O';
		return(1);
	}else if(tabela[0][0]=='X' && tabela[0][2]=='X' && tabela[0][1]=='2'){
		tabela[0][1]='O';
		return(1);
	}else if(tabela[0][1]=='X' && tabela[0][2]=='X' && tabela[0][0]=='1'){
		tabela[0][0]='O';
		return(1);
	}else if(tabela[1][0]=='X' && tabela[1][1]=='X' && tabela[1][2]=='6'){
		tabela[1][2]='O';
		return(1);
	}else if(tabela[1][0]=='X' && tabela[1][2]=='X' && tabela[1][1]=='5'){
		tabela[1][1]='O';
		return(1);
	}else if(tabela[1][1]=='X' && tabela[1][2]=='X' && tabela[1][0]=='4'){
		tabela[1][0]='O';
		return(1);
	}else if(tabela[2][0]=='X' && tabela[2][1]=='X' && tabela[2][2]=='9'){
		tabela[2][2]='O';
		return(1);
	}else if(tabela[2][0]=='X' && tabela[2][2]=='X' && tabela[2][1]=='8'){
		tabela[2][1]='O';
		return(1);
	}else if(tabela[2][1]=='X' && tabela[2][2]=='X' && tabela[2][0]=='7'){
		tabela[2][0]='O';
		return(1);
	}else if(tabela[0][0]=='X' && tabela[1][0]=='X' && tabela[2][0]=='7'){
		tabela[2][0]='O';
		return(1);
	}else if(tabela[0][0]=='X' && tabela[2][0]=='X' && tabela[1][0]=='4'){
		tabela[2][0]='O';
		return(1);
	}else if(tabela[1][0]=='X' && tabela[2][0]=='X' && tabela[0][0]=='1'){
		tabela[0][0]='O';
		return(1);
	}else if(tabela[0][1]=='X' && tabela[1][1]=='X' && tabela[2][1]=='8'){
		tabela[2][1]='O';
		return(1);
	}else if(tabela[0][1]=='X' && tabela[2][1]=='X' && tabela[1][1]=='5'){
		tabela[1][1]='O';
		return(1);
	}else if(tabela[1][1]=='X' && tabela[2][1]=='X' && tabela[0][1]=='2'){
		tabela[0][1]='O';
		return(1);
	}else if(tabela[0][2]=='X' && tabela[1][2]=='X' && tabela[2][2]=='9'){
		tabela[2][2]='O';
		return(1);
	}else if(tabela[0][2]=='X' && tabela[2][2]=='X' && tabela[1][2]=='6'){
		tabela[1][2]='O';
		return(1);
	}else if(tabela[1][2]=='X' && tabela[2][2]=='X' && tabela[0][2]=='3'){
		tabela[0][2]='O';
		return(1);
	}else if(tabela[0][2]=='X' && tabela[1][1]=='X' && tabela[2][0]=='7'){
		tabela[2][0]='O';
		return(1);
	}else if(tabela[0][2]=='X' && tabela[2][0]=='X' && tabela[1][1]=='5'){
		tabela[1][1]='O';
		return(1);
	}else if(tabela[2][0]=='X' && tabela[1][1]=='X' && tabela[0][2]=='3'){
		tabela[0][2]='O';
		return(1);
	}else if(tabela[0][0]=='X' && tabela[1][1]=='X' && tabela[2][2]=='9'){
		tabela[2][2]='O';
		return(1);
	}else if(tabela[0][0]=='X' && tabela[2][2]=='X' && tabela[1][1]=='5'){
		tabela[1][1]='O';
		return(1);
	}else if(tabela[1][1]=='X' && tabela[2][2]=='X' && tabela[0][0]=='1'){
		tabela[0][0]='O';
		return(1);
	}
	return(0);
}

int pcganhar(){
	//está função ver se tem alguma possibilidade do computador ganhar
	if(tabela[0][0]=='O' && tabela[0][1]=='O'&& tabela[0][2]=='3'){
		/*caso na posição 1 e 2, estiver com O, e a 3, com seu valor 
		inicial, se o computador jogar na posição 3 ele vence*/
		tabela[0][2]='O';
		return(1);
	}else if(tabela[0][0]=='O' && tabela[0][2]=='O' && tabela[0][1]=='2'){
		tabela[0][1]='O';
		return(1);
	}else if(tabela[0][1]=='O' && tabela[0][2]=='O' && tabela[0][0]=='1'){
		tabela[0][0]='O';
		return(1);
	}else if(tabela[1][0]=='O' && tabela[1][1]=='O' && tabela[1][2]=='6'){
		tabela[1][2]='O';
		return(1);
	}else if(tabela[1][0]=='O' && tabela[1][2]=='O' && tabela[1][1]=='5'){
		tabela[1][1]='O';
		return(1);
	}else if(tabela[1][1]=='O' && tabela[1][2]=='O' && tabela[1][0]=='4'){
		tabela[1][0]='O';
		return(1);
	}else if(tabela[2][0]=='O' && tabela[2][1]=='O' && tabela[2][2]=='9'){
		tabela[2][2]='O';
		return(1);
	}else if(tabela[2][0]=='O' && tabela[2][2]=='O' && tabela[2][1]=='8'){
		tabela[2][1]='O';
		return(1);
	}else if(tabela[2][1]=='O' && tabela[2][2]=='O' && tabela[2][0]=='7'){
		tabela[2][0]='O';
		return(1);
	}else if(tabela[0][0]=='O' && tabela[1][0]=='O' && tabela[2][0]=='7'){
		tabela[2][0]='O';
		return(1);
	}else if(tabela[0][0]=='O' && tabela[2][0]=='O' && tabela[1][0]=='4'){
		tabela[2][0]='O';
		return(1);
	}else if(tabela[1][0]=='O' && tabela[2][0]=='O' && tabela[0][0]=='1'){
		tabela[0][0]='O';
		return(1);
	}else if(tabela[0][1]=='O' && tabela[1][1]=='O' && tabela[2][1]=='8'){
		tabela[2][1]='O';
		return(1);
	}else if(tabela[0][1]=='O' && tabela[2][1]=='O' && tabela[1][1]=='5'){
		tabela[1][1]='O';
		return(1);
	}else if(tabela[1][1]=='O' && tabela[2][1]=='O' && tabela[0][1]=='2'){
		tabela[0][1]='O';
		return(1);
	}else if(tabela[0][2]=='O' && tabela[1][2]=='O' && tabela[2][2]=='9'){
		tabela[2][2]='O';
		return(1);
	}else if(tabela[0][2]=='O' && tabela[2][2]=='O' && tabela[1][2]=='6'){
		tabela[1][2]='O';
		return(1);
	}else if(tabela[1][2]=='O' && tabela[2][2]=='O' && tabela[0][2]=='3'){
		tabela[0][2]='O';
		return(1);
	}else if(tabela[0][2]=='O' && tabela[1][1]=='O' && tabela[2][0]=='7'){
		tabela[2][0]='O';
		return(1);
	}else if(tabela[0][2]=='O' && tabela[2][0]=='O' && tabela[1][1]=='5'){
		tabela[1][1]='O';
		return(1);
	}else if(tabela[2][0]=='O' && tabela[1][1]=='O' && tabela[0][2]=='3'){
		tabela[0][2]='O';
		return(1);
	}else if(tabela[0][0]=='O' && tabela[1][1]=='O' && tabela[2][2]=='9'){
		tabela[2][2]='O';
		return(1);
	}else if(tabela[0][0]=='O' && tabela[2][2]=='O' && tabela[1][1]=='5'){
		tabela[1][1]='O';
		return(1);
	}else if(tabela[1][1]=='O' && tabela[2][2]=='O' && tabela[0][0]=='1'){
		tabela[0][0]='O';
		return(1);
	}
	return(0);
}

int jogadapc(){
	/*está função é a que faz o computador escolher entre, jogar em uma 
	posição que o adversário irá ganhar, ou uma posição que ele irá ganhar,
	ou uma posição aleatória*/
	if (!pcganhar()){
		//se o computador tiver como ganhar, ele não entra e já joga, se não ele faz o próximo teste
		if(!advganhar()){
			/*se o adversário tiver como ganhar, ele joga, se não ele faz com que jogadacom seja 1, 
			porque com essa condição o computador irá jogar em uma posição aleatória*/
			jogadacom=1;
		}
	}
	while(jogadacom==1){
		//no caso de jogadacom igual a 1, ele joga aleatóriamente
		limpaorganiza();
		xo='O';
		srand(time(NULL));				//semente para o aleatório
		/*a proxima linha faz um aleátorio de 1 a 9 na parte (1+ rand() % 9),
		e "converte" o número inteiro sorteado em um char, por exemplo,
		se o sorteio der 1, ele acrescenta 48, pois o número 49 na tabela ASCII
		representa o caractere 1 */
		posi = 48 + (1+ rand() % 9); 	
		switch (posi){
			//este switch escolhe um valor de linha e coluna para cada número sorteado
			case '1' :
				l=0;
				c=0;
				break;
			case '2' :
				l=0;
				c=1;
				break;
			case '3' :
				l=0;
				c=2;
				break;
			case '4':
				l=1;
				c=0;	
				break;
			case '5':
				l=1;
				c=1;
				break;
			case '6':
				l=1;
				c=2;
				break;
			case '7':
				l=2;
				c=0;
				break;
			case '8':
				l=2;
				c=1;
				break;
			case '9':
				l=2;
				c=2;
				break;
			default:
				printf("\nerror sorteio");
			}	
		if(tabela[l][c]!='X' && tabela[l][c]!='O'){ //se as posições não estiverem ocupadas ele entra
			tabela[l][c]=xo;						//e ocupa a posição sorteada com um X ou O
			jogadacom=2;							//muda o valor de jogadacom para sair do looping
			return(1);								
		}
	}
}

int jogadamodovcpc(){
	//está função funciona como a função jogada, só que agora o segundo jogador é o computador
		do{
			do{ //este "do while" força a digitar uma posição valida, e que não esteja ocupada
				printf("%s escolha uma posição: \n > ",nomej1);
				setbuf(stdin, NULL);		//para evitar problemas, "zeramos" o buffer
				posi=getch();				//força o usuario a digitar apenas um caractere por vez
				xo='X';						//o jogador é sempre o X e o computador O
			}while(testaposi(posi));		//chama o testaposi pra ver se o que digitou foi válido
			if (ganhou()){					//ver se o jogador 1 ganhou, se sim sai do looping
				break;
			}
			if(velha()){					//testa se deu velha, se sim, sai do looping
				break;
			}
			limpaorganiza();
			Sleep(300);						//espera um tempo, para dar impressão que o computador está pensando 
			printf(" PC JOGANDO . ");
			Sleep(300);
			printf(". ");
			Sleep(300);
			printf(". \n");
			Sleep(200);
			jogadapc();
			if (ganhou()){					//testa se o computador venceu
				break;
			}
			if(velha()){					//testa se deu velha
				break;
			}
			limpaorganiza();
		}while(1);		//ira girar, até uma condição do ganhou ou do velha ser valida, e ter um break
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(){
	do{
		system("CLS");
		setlocale(LC_ALL, "Portuguese");	//apenas para poder usar os acentos e ç's nas exibições
		zerador();							//inicia as variáveis, ou zera caso seja outra rodada
		exibir();							//exibe a tabela do jogo							
		printf("\nEscolha o modo de jogo\n");
		do{									//para sair deste "do while", a pessoa é forçada a pessoa digitar 1 ou 2 
			printf("1) PLAYER1 VS PLAYER2\n2) PLAYER VS PC\n>>"); //os modos de jogo
			setbuf(stdin, NULL);
			mododejogo = getch();
			if(mododejogo=='1' || mododejogo=='2'){
				break;
			}
			system	("CLS");
			exibir();
			printf("\nEscolha 1 ou 2\n");
		}while(1);
		if(mododejogo=='1'){
			printf("\nDigite o nome do jogador 1:\n");
			setbuf(stdin, NULL);				//para evitar problemas, "zeramos" o buffer
			gets(nomej1);						//função gets para ler uma string do nome dos jogadores
			printf("Digite o nome do jogador 2:\n");
			setbuf(stdin, NULL);
			gets(nomej2);	
			limpaorganiza();					//limpa a tela, e chama a função exibe
			jogada();							//a função jogada é chamada onde fica o núcleo do jogo
		}else if(mododejogo=='2'){
			printf("Você começara jogando\n");
			//atribui ao jogador dois o nome PC
			nomej2[0]='P';
			nomej2[1]='C';
			nomej2[2]='\0';		//depois de PC ele adiciona \0 para quando for manipular este nome, saber onde acaba
			printf("Digite o nome seu nome :\n");
			setbuf(stdin, NULL);
			gets(nomej1);	
			limpaorganiza();
			jogadamodovcpc();
		}
		do{									//força a pessoa digitar 1 ou 2, para sair deste "do while"
			printf("\n1) Jogar Novamente\n2) Sair\n >");
			setbuf(stdin, NULL);
			continuar = getch();
			if(continuar=='1' || continuar=='2'){
				break;
			}
			limpaorganiza();
			printf("Escolha 1 ou 2\n");
		}while(1);
	}while(continuar=='1'); 
	printf("FIM DO JOGO\n");
	system("pause");
	return(0);
}
