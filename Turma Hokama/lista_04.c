#include <stdio.h>
#include <stdlib.h>

int somaSubsequencia (int* arrConjunto, int* arrSolucao, int n, int i, int c)
{
    // Impressão da árvore de recursões
    printf ("f(%d, %d, %d)\n", n, i, c);

    if (i == n)
    {
        // Se a soma chega no valor desejado (i.e. c = 0) quando o vetor é percorrido por inteiro então retorna verdadeiro
        if (c == 0) return 1;
        return 0;
    }

    // Caso a soma extrapole o valor desejado em algum momento, retorna falso
    if (c < 0) return 0;

    arrSolucao[i] = 0;
    // Percorre a árvore para arrSolucao[i] não pego, retorna 1 se a solução bate (vide linha 12)
    if (somaSubsequencia(arrConjunto, arrSolucao, n, i + 1, c))
        return 1;

    arrSolucao[i] = 1;
    // Percorre a árvore para arrSolucao[i] pego, retorna 1 se a solução bate (vide linha 12)
    if (somaSubsequencia(arrConjunto, arrSolucao, n, i + 1, c - arrConjunto[i]))
        return 1;

    return 0;
}

int main (int argc, char* argv[])
{
    int i, soma, qtde;
    int *itens, *resultado;

    // Leitura da soma desejada e da quantidade de itens
    scanf ("%d", &soma);
    scanf ("%d", &qtde);

    // Aloca os vetores
    itens = (int*) calloc(qtde, sizeof(int));
    resultado = (int*) calloc(qtde, sizeof(int));

    // Leitura dos valores
    for (i = 0; i < qtde; ++i)
    {
        scanf("%d", &itens[i]);
    }

    somaSubsequencia(itens, resultado, qtde, 0, soma);

    // Impressao do vetor resposta
    for (i = 0; i < qtde; ++i)
    {
        printf("%d ", resultado[i]);
    }
    printf("\n");

    return 0;
}
