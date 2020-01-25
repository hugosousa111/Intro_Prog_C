algoritmo "semnome"
// Função :  Calcular o numero fatorial
// Autor :  Hugo Sousa
// Data : 25/11/2015
// Seção de Declarações
var
num,a,resposta:inteiro
funcao calcfatorial(x:inteiro):inteiro
inicio
a<-x
enquanto a>1 faca
a<-a-1
x<-x*a
fimenquanto
retorne x
fimfuncao
inicio
// Seção de Comandos
leia(num)
se num =0 entao
   escreval("fatorial de 0 é 1")
senao
   se num>0 entao
      escreval("fatorial de ",num," é ",calcfatorial(num))
   senao
      escreval("Só existe fatorial de numeros positivos")
   fimse
fimse
fimalgoritmo
