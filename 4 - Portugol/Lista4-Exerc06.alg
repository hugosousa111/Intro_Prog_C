algoritmo "semnome"
// Função : Calculadora
// Autor : Hugo Sousa
// Data : 24/11/2015
// Seção de Declarações 
var
a,b,res:real
opera:caractere
inicio
// Seção de Comandos 
leia(a,b)
escreval("digite operação (+)(-)(*)(/)")
leia(opera)
escolha opera
caso "+"
res<-a+b
caso "-"
res<-a-b
caso "*"
res<-a*b
caso "/"
res<-a/b
outrocaso
escreval("Sinal invalido")
fimescolha
escreval(a,opera,b," = ", res)
fimalgoritmo
