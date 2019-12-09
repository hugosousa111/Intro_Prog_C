algoritmo "semnome"
// Função :  Arvore
// Autor : Hugo Sousa
// Data : 30/11/2015
// Seção de Declarações
var
qlinha, linha, j: inteiro
inicio
// Seção de Comandos
leia(qlinha)
para linha de  1 ate qlinha faca
     para j de 1 ate (qlinha-linha) faca
     escreva(".")
     fimpara
     para j de 1 ate (qlinha-(qlinha-linha))*2-1 faca
     escreva("*")
     fimpara
     para j de 1 ate qlinha-linha faca
     escreva(".")
     fimpara
     para j de 1 ate (qlinha-linha) faca
     escreva(".")
     fimpara
     para j de 1 ate (qlinha-(qlinha-linha))*2-1 faca
     escreva("*")
     fimpara
     para j de 1 ate qlinha-linha faca
     escreva(".")
     fimpara
     escreval()
fimpara

fimalgoritmo
