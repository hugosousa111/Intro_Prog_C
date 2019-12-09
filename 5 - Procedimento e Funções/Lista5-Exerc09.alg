algoritmo "semnome"
// Função : Teste de Triangulos
// Autor :  Hugo Sousa
// Data : 25/11/2015
// Seção de Declarações
var
cat1,cat2,cat3:real
procedimento testetriangulo (x,y,z:real)
inicio
se x<y+z entao       //teste pra saber se é um triangulo
   se y<x+z entao    //teste pra saber se é um triangulo
      se z<x+y entao //teste pra saber se é um triangulo
         se x=y entao
            se x=z entao
               escreval("Triângulo Equilátero")
            senao
               escreval("Triângulo Isósceles")
            fimse
         senao
            se x=z entao
               escreval("Triângulo Isósceles")
            senao
               se y=z entao
                  escreval("Triângulo Isósceles")
               senao
                  escreval("Triângulo Escaleno")
               fimse
            fimse
         fimse
      senao
      escreval("nao valido")
      fimse
   senao
   escreval("nao valido")
   fimse
senao
escreval("nao valido")
fimse
fimprocedimento
inicio
// Seção de Comandos
leia(cat1,cat2,cat3)
testetriangulo(cat1,cat2,cat3)
fimalgoritmo
