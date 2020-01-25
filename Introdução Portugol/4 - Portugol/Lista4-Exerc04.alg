algoritmo "semnome"
// Função : Maior e menor número
// Autor : Hugo Sousa
// Data : 24/11/2015
// Seção de Declarações
var
a,b,c:inteiro
inicio
// Seção de Comandos
leia(a,b,c)
escreva("o maior número é ")
se a>b entao
   se a>c entao
      escreval(a)
   senao
      escreval(c)
   fimse
senao
   se b>c entao
      escreval(b)
   senao
      escreval(c)
   fimse
fimse
escreva("o menor número é ")
se a<b entao
   se a<c entao
      escreval(a)
   senao
      escreval(c)
   fimse
senao
   se b<c entao
      escreval(b)
   senao
      escreval(c)
   fimse
fimse
escreva("a media é  ",(a+b+c)/2)
fimalgoritmo
