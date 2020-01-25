algoritmo "semnome"
// Função : Massa Ideal
// Autor : Hugo Sousa
// Data : 24/11/2015
// Seção de Declarações
var
altura,massa:real
sexo:caractere
funcao calcmassa(a:real;s:caractere):real
inicio
se s="m" entao
   retorne (72.7 *a)-58
senao
   retorne (62.1 * a)-44.7
fimse
fimfuncao
inicio
// Seção de Comandos
escreval("escreva altura")
leia(altura)
escreval("escreva sexo")
leia(sexo)
se sexo="m" entao
   escreval(calcmassa(altura,sexo),"  é a massa ideal")
senao
   se sexo="f"entao
      escreval(calcmassa(altura,sexo),"  é a massa ideal")
   senao
   escreval("sexo invalido")
   fimse
fimse
fimalgoritmo
