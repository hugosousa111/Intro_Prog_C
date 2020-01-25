algoritmo "semnome"
// Função : leitura de n numeros
// Autor : Hugo Sousa
// Data : 01/12/2015
// Seção de Declarações
var
n,cont:inteiro
a, somaa,menornum, maiornum:real
inicio
// Seção de Comandos
leia(n)
se n>0 entao
   para cont de 1 ate n faca
      leia(a)
      somaa<-somaa+a
      se cont=1 entao
         menornum<-a
         maiornum<-a
      senao
         se a<menornum entao
            menornum<-a
         fimse
      fimse
      se a>maiornum entao
         maiornum<-a
      fimse
   fimpara
   escreval("media é   ",somaa/n)
   escreval("maior é   ",maiornum)
   escreval("menor é   ",menornum)
senao
   escreval("entrada invalida, apenas numeros positivos")
fimse
fimalgoritmo
