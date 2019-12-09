algoritmo "semnome"
// Função : Calculadora
// Autor : Hugo Sousa
// Data : 25/11/2015
// Seção de Declarações 
var
num1,num2:real
operacao:caractere
funcao calculadora(a,b:real;opera:caractere):real
inicio
escolha opera
caso "+"
retorne a+b
caso "-"
retorne a-b
caso "*"
retorne a*b
caso "/"
retorne a/b
caso "^"
retorne a^b
outrocaso
escreval("Sinal invalido")
retorne 0
fimescolha
fimfuncao
inicio
// Seção de Comandos 
escreval("insira os numeros")
leia(num1,num2)
escreval("insira a operacao")
leia(operacao)
escreval(" = ",calculadora(num1, num2, operacao))
fimalgoritmo
