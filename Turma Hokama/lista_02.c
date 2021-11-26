// Lista 2 - COM 11
// Nixon Moreira Silva - 2020015292

#include <stdio.h>
#include <stdlib.h>

//---- SOLUCAO INICIO ----//

// AVISO: Bubble sort não é a solução ótima pra esse exercício

int* bubbleSort (int* A, int n)
{
	// Ordena o array do menor para o maior elemento
    int i, j, aux;
    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < n; ++j)
        {
            if (A[i] < A[j])
            {
                aux = A[i];
                A[i] = A[j];
                A[j] = aux;
            }
        }
    }
	
	// Retorna o array ordenado
    return A;
}

int* iniciaVetor (int n)
{
    // Aloca e inicializa a lista de n elementos
    int* list = (int*) calloc(n, sizeof(int));
    // Retorna a lista
    return list;
}

int* uniao (int* A, int nA, int* B, int nB, int* nC)
{
    int i, j, k, rep, *C;

    // Incializa a nova lista
    C = iniciaVetor(nA + nB);

    k = 0;

    // Adiciona todos os elementos de A em C
    for (i = 0; i < nA; ++i)
    {
        C[k++] = A[i];
    }

    // Cheque por repeticoes de elementos de A no B
    // se nao houver, adicione ao C
    for (j = 0; j < nB; ++j)
    {
        rep = 0;
        for (i = 0; i < nA; ++i)
        {
            if (B[j] == A[i])
                rep = 1;
        }
        if (rep == 0)
        {
            C[k++] = B[j];
        }
    }

    // Retorna o topo dessa lista
    *nC = k;

	// Ordena a lista
    C = bubbleSort(C, k);

    return C;
}

int* interseccao (int* A, int nA, int* B, int nB, int *nD)
{
    int i, j, k, rep, *D;

    // Incializa a nova lista
    D = iniciaVetor(nA + nB);

    k = 0;

    // Checa por elementos de A repetidos em B e vice-versa e
    // adiciona o elemento repetido em C
    for (i = 0; i < nA; ++i)
    {
        rep = 0;
        for (j = 0; j < nB; ++j)
        {
            if (A[i] == B[j])
                rep = 1;
        }
        if (rep == 1)
        {
            D[k++] = A[i];
        }
    }

    // Retorna o topo da lista
    *nD = k;

	// Ordena a lista
    D = bubbleSort(D, k);

    return D;
}

void imprimeConjunto (int* C, int nC)
{
    // Imprime cada elemento da lista ate seu topo
    for (int i = 0; i < nC; ++i)
    {
        printf("%d ", C[i]);
    }
    printf("\n");
}

void liberaConjunto (int* A)
{
    // Libera a memoria alocada
    free(A);
}

//---- SOLUCAO FIM ----//

//NAO ALTERE A MAIN
int main(int argc, char * argv[]){
  int* A;
  int* B;
  int* C;
  int* D;
  int nA, nB, nC, nD, aux;

  //inicializando e lendo o conjunto A
  scanf("%d", &nA);
  A = iniciaVetor(nA);
  for(int i = 0; i < nA; i++){
    scanf("%d", &aux);
    A[i] = aux;
  }
  //inicializando e lendo o conjunto B
  scanf("%d", &nB);
  B = iniciaVetor(nB);
  for(int i = 0; i < nB; i++){
    scanf("%d", &aux);
    B[i] = aux;
  }

  //calcula e imprime a uniao e a interseccao
  C = uniao(A, nA, B, nB, &nC);
  imprimeConjunto(C, nC);

  D = interseccao(A, nA, B, nB, &nD);
  imprimeConjunto(D, nD);

  //libera a memoria dos 4 vetores
  liberaConjunto(A);
  liberaConjunto(B);
  liberaConjunto(C);
  liberaConjunto(D);

  return 0;
}
