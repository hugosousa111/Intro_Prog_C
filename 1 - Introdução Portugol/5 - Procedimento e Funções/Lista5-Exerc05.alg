algoritmo "semnome"
// Função : testar se o numero é par ou impar
// Autor : Hugo Sousa
// Data : 24/11/2015
// Seção de Declarações
var
a:inteiro
sinal:logico
funcao testarparimpar(x:inteiro):logico
inicio
se x mod 2=0 entao
   retorne verdadeiro
senao
   retorne falso
fimse
fimfuncao
inicio
// Seção de Comandos
leia(a)
se a<>0 entao
se testarparimpar(a) entao
escreval("o numero é par")
senao
escreval("o numero é ímpar")
fimse
senao
escreval("0 é nulo")
fimse
fimalgoritmo
