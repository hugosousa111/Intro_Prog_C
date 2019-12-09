algoritmo "semnome"
// Função : testar se o numero é positivo ou negativo
// Autor : Hugo Sousa
// Data : 24/11/2015
// Seção de Declarações
var
a:inteiro
sinal:logico
funcao testesinal(x:inteiro):logico
inicio
se x>0 entao
   retorne verdadeiro
senao
   retorne falso
fimse
fimfuncao
inicio
// Seção de Comandos
leia(a)
se a<>0 entao
se testesinal(a) entao
escreval("o numero é positivo")
senao
escreval("o numero é negativo")
fimse
senao
escreval("0 é nulo")
fimse
fimalgoritmo
