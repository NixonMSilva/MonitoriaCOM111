/*
Escreva um programa que leia um número l de linhas e um número c de colunas. Em seguida, um vetor V de tamanho l*c e uma matriz M com l linhas e
c colunas devem ser alocados dinamicamente. Seu programa deve executar as tarefas abaixo sequencialmente, através de chamadas de funções:
a) Preencher o vetor V com valores inteiros digitados pelo usuário.
b) Imprimir o vetor V na tela.
c) Preencher a matriz M, sequencialmente, com os valores do vetor $V$.
d) Imprimir a matriz M na tela. 
*/

// Autor: Nixon Moreira Silva

#include <stdio.h>
#include <stdlib.h>

int* alocaVetor (int tamanho)
{
	// Alocacao do vetor
	return (int*) malloc(sizeof(int) * tamanho);
}

int** alocaMatriz (int linhas, int colunas)
{
	// Alocacao da matriz
	// 1. Alocacao de um vetor de ponteiros
	int** matriz = (int**) malloc(sizeof(int*) * linhas);

	// 2. Verificacao de erros
	if (matriz == NULL)
	{
		printf("Erro na alocacao de matriz!\n");
		return NULL;
	}

	// 3. Alocacao de colunas
	for (int i = 0; i < linhas; i++)
	{
		matriz[i] = (int*) malloc (sizeof(int) * colunas);

		// 4. Verificacao de erros
		if (matriz[i] == NULL)
		{
			printf("Erro na alocacao de matriz!\n");
			return NULL;
		}
	}

	return matriz;
}

void preencheVetor (int* vetor, int tamanho)
{
	// Preencher vetor
	for (int i = 0; i < tamanho; i++)
	{
		// Acesso direto da posicao de memoria
		// atraves do operador []
		scanf("%d", &vetor[i]);
	}
}

void preencheMatriz (int** matriz, int *vetor, int linhas, int colunas)
{
	// Preencher matriz
	for (int i = 0; i < linhas; i++)
	{
		for (int j = 0; j < colunas; j++)
		{
			// Aritmetica de ponteiros para obter o valor da matriz
			// numa estrutura linear (vetor)
			matriz[i][j] = vetor[(i * colunas) + j];
		}
	}
}

void imprimeVetor (int* vetor, int tamanho)
{
	// Imprimir vetor
	for (int i = 0; i < tamanho; i++)
	{
		// Acesso direto da posicao de memoria
		// atraves do operador []
		printf("%d ", vetor[i]);
	}
	printf("\n");
}

void imprimeMatriz (int** matriz, int linhas, int colunas)
{
	// Imprimir matriz
	for (int i = 0; i < linhas; i++)
	{
		for (int j = 0; j < colunas; j++)
		{
			// Acesso direto da posicao de memoria
			// atraves do operador []
			printf("%d ", matriz[i][j]);
		}
		// Quebra de linha para a prox. linha
		printf("\n");
	}
	printf("\n");
}

int main (int argc, char* argv[]) 
{
	int linhas, colunas;
	int *vetor, **matriz;

	printf ("Insira o número de linhas e colunas: ");
	scanf ("%d %d", &linhas, &colunas);

	// Chamada da alocacao do vetor
	vetor = alocaVetor(linhas * colunas);

	// Verificacao de erros
	if (vetor == NULL)
	{
		printf("Erro na alocacao de vetor!\n");
		return -1;
	}

	// Chamada da alocacao da matriz
	matriz = alocaMatriz(linhas, colunas);

	// Verificacao de erros
	if (matriz == NULL)
	{
		printf("Erro na alocacao da matriz!\n");
		return -1;
	}

	// Chamada de preenchimento de vetor
	preencheVetor(vetor, (linhas * colunas));

	// Chamada de preenchimento da matriz
	preencheMatriz(matriz, vetor, linhas, colunas);

	// Chamada de impressao de vetor
	imprimeVetor(vetor, (linhas * colunas));

	// Chamada de impressao de matriz
	imprimeMatriz(matriz, linhas, colunas);

	// Libera memario do vetor
	free(vetor);

	// Libera memoria da matriz
	for (int i = 0; i < linhas; i++)
	{
		// Libera linha por linha
		free(matriz[i]);
	}
	// Libera o ponteiro da matriz em si
	free(matriz);

	return 0;
}