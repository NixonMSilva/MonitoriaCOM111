
/*
Implemente um TAD para representar números complexos (complex.h e complex.c). Sabe-se
que um número complexo é representado por a + bi, onde a e b são números reais e i a unidade
imaginária. O TAD deve implementar as seguintes operações:
(a) Função para criar um número complexo, dados a e b.
(b) Função para liberar um número complexo previamente criado.
(c) Função para somar dois números complexos, retornando um novo número com o resultado
da operação. 
*/

// Autor: Nixon Moreira Silva

#include <stdio.h>
#include "complex.h"

int main (int argc, char* argv[]) 
{
	double r1, r2, i1, i2;
	complex_t *a, *b;
	complex_t *soma, *sub, *mult, *div;

	// Leitura dos numeros complexos
	printf("Insira o primeiro numero complexo com sua parte real e imaginaria entre espacos (sem o i):");
	scanf("%lf %lf", &r1, &i1);

	printf("Insira o segundo numero complexo com sua parte real e imaginaria entre espacos (sem o i):");
	scanf("%lf %lf", &r2, &i2);

	// Criacao dos valores
	a = allocateComplex(r1, i1);
	b = allocateComplex(r2, i2);

	// Impressao dos valores
	printf("Complexo A: ");
	printComplex(a);
	printf("\n");

	printf("Complexo B: ");
	printComplex(b);
	printf("\n");

	// Somar
	printf("Soma: ");
	soma = sumComplex(a, b);
	printComplex(soma);
	printf("\n");

	// Subtrair
	printf("Subtracao: ");
	sub = subtractComplex(a, b);
	printComplex(sub);
	printf("\n");

	// Multiplicar
	printf("Multiplicacao: ");
	mult = multiplyComplex(a, b);
	printComplex(mult);
	printf("\n");

	// Dividir
	printf("Divisao: ");
	div = divideComplex(a, b);
	printComplex(div);
	printf("\n");

	// Liberacao de memoria
	freeComplex(a);
	freeComplex(b);
	freeComplex(soma);
	freeComplex(sub);
	freeComplex(mult);
	freeComplex(div);

	return 0;
}