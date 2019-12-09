algoritmo "semnome"
// Função : Ordenação de 3 variaveis
// Autor : Hugo Sousa
// Data : 01/12/2015
// Seção de Declarações
var
a,b,c, temp:inteiro
inicio
// Seção de Comandos
leia(a,b,c)
se a<b entao
   se a<c entao
      se b<c entao
      senao
         temp<-c
         c<-b
         b<-temp
      fimse
   senao
      temp<-c
      c<-a
      a<-temp
      temp<-c
      c<-b
      b<-temp
   fimse
senao
   se a>c entao
      temp<-c
      c<-a
      a<-temp
      se a<b entao
      senao
         temp<-b
         b<-a
         a<-temp
      fimse
   senao
      temp<-b
      b<-a
      a<-temp
   fimse
fimse
escreval(a,b,c)
fimalgoritmo
