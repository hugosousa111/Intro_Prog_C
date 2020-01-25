algoritmo "semnome"
// Função : Fibonacci
// Autor : Hugo Sousa
// Data : 25/11/2015
// Seção de Declarações
var
termos,a:inteiro
procedimento Fibonacci(t:inteiro)
inicio
a<-1
se a<=t entao
   escreva(" 1 , ")
   enquanto a<t faca
      escreva(a+a-1, " , ")
      a<-a+1
   fimenquanto
fimse
fimprocedimento
inicio
// Seção de Comandos
leia(termos)
Fibonacci(termos)
fimalgoritmo
