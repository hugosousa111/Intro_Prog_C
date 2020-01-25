algoritmo "semnome"
// Função : Media Escolar
// Autor :  Hugo Sousa
// Data : 24/11/2015
// Seção de Declarações
var
nota01, nota02, md, mdfinal, notafinal:real
inicio
// Seção de Comandos
escreval("primeira nota")
leia(nota01)
escreval("segunda nota")
leia(nota02)
md<-(nota01+nota02)/2
se md>=7 entao
   escreval("APROVADO")
senao
   se md>=4 entao
      escreval("nota final")
      leia(notafinal)
      mdfinal <-(md+notafinal)/2
      se mdfinal>=5 entao
         escreval("APROVADO FINAL")
      senao
         escreval("REPROVADO")
      fimse
   senao
      escreval("REPROVADO")
   fimse
fimse
fimalgoritmo
