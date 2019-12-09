algoritmo "semnome"
// Função : decimal para binario
// Autor : Hugo Sousa
// Data : 01/12/2015
// Seção de Declarações
var
decimal:inteiro
binario,x:caractere
inicio
// Seção de Comandos
leia(decimal)
se decimal=0 entao
binario<-"0"
senao
enquanto decimal>0 faca
   se decimal mod 2 = 0 entao
      x<-"0"
      binario<-x+binario
   senao
      x<-"1"
      binario<-x+binario
   fimse
   decimal<-decimal div 2
fimenquanto
fimse
escreval(binario)
fimalgoritmo
