// Lista 2 - COM 11
// Nixon Moreira Silva - 2020015292

#include <stdio.h>
#include <stdlib.h>

//---- SOLUTION START ----//

// DISCLAIMER: Bubble sort here is perhaps not the ideal solution
// since it has a quadratic complexity, besides, the students at 
// this course weren't introduced to the algorithm just yet

int* bubbleSort (int* A, int n)
{
	// Sorts an array from smallest to largest value
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
	
	// Returns the sorted array
    return A;
}

int* iniciaVetor (int n)
{
    // Allocates and initializes a list with n elements
    int* list = (int*) calloc(n, sizeof(int));
    // Returns the list
    return list;
}

int* uniao (int* A, int nA, int* B, int nB, int* nC)
{
    int i, j, k, rep, *C;

    // Initializes the new list
    C = iniciaVetor(nA + nB);

    k = 0;

    // Adds all the elements form A on C
    for (i = 0; i < nA; ++i)
    {
        C[k++] = A[i];
    }

    // Check for repetition in each element of B on A,
    // if there's none, add the element to C
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

    // Returns the upper bound of the new list
    *nC = k;

	// Sorts the array
    C = bubbleSort(C, k);

    return C;
}

int* interseccao (int* A, int nA, int* B, int nB, int *nD)
{
    int i, j, k, rep, *D;

    // Initializes the new list
    D = iniciaVetor(nA + nB);

    k = 0;

    // Checks for repeated elements of A on B, if there is,
    // add the repeated element onto C
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

    // Returns the upper bound of the new list
    *nD = k;

	// Sorts the array
    D = bubbleSort(D, k);

    return D;
}

void imprimeConjunto (int* C, int nC)
{
    // Prints each element of the array until its upper bound
    for (int i = 0; i < nC; ++i)
    {
        printf("%d ", C[i]);
    }
    printf("\n");
}

void liberaConjunto (int* A)
{
    // Frees the allocated memory
    free(A);
}

//---- SOLUTION END ----//

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
