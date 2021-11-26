#include <stdio.h>
#include <stdlib.h>
#include "complex.h"

complex_t* allocateComplex (double r, double i)
{
	// Alocacao de TAD
	complex_t* temp = (complex_t*)malloc(sizeof(complex_t));

	// Tratamento de erros
	if (temp == NULL)
	{
		printf("Erro alocando valor!\n");
	}
	else
	{
		// Inicializa os valores
		temp->r = r;
		temp->i = i;
	}

	return temp;
}

void freeComplex (complex_t* a)
{
	// Libera elemento
	free(a);
}

void printComplex (complex_t* a)
{
	// Imprime elemento
	// + forca o printf a imprimir o sinal
	// .3 forca a imprimir com 3 casas decimais de precisao
	printf("%+.3lf %+.3lf", a->r, a->i);
}


complex_t* sumComplex (complex_t* a, complex_t* b)
{
	// Soma de complexos
	// (a + b)i + (c + d)i = (a + c) + (b + d)i
	double r = a->r + b->r;
	double i = a->i + b->i;
	return allocateComplex(r, i);
}

complex_t* subtractComplex (complex_t* a, complex_t* b)
{
	// Subtracao de complexos
	// (a + b)i - (c + d)i = (a - c) + (b - d)i
	double r = a->r - b->r;
	double i = a->i - b->i;
	return allocateComplex(r, i);
}

complex_t* multiplyComplex (complex_t* a, complex_t* b)
{
	// Multiplicacao de complexos
	// (a + b)i * (c + d)i = (ac - bd) + (bc + ad)i
	double r = (a->r * b->r) - (a->i * b->i);
	double i = (a->i * b->r) + (a->r * b->i);
	return allocateComplex(r, i);
}

complex_t* divideComplex (complex_t* a, complex_t* b)
{
	// Divisao de complexos
	// (a + b)i / (c + d)i = ((ac + bd)/(c^2 + d^2)) + ((bc − ad)/(c^2 + d^2))i
	double r = (double)((a->r * b->r) + (a->i * b->i)) / (double)((b->r * b->r) + (b->i * b->i));
	double i = (double)((a->i * b->r) - (a->r * b->i)) / (double)((b->r * b->r) + (b->i * b->i));
	return allocateComplex(r, i);
}