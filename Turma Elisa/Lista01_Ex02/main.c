/*
Crie um registro (struct) ALUNO que contenha os seguintes campos:
  int matricula;
	char nome[50];
	int dia\_nasc;
	int mes\_nasc;
	int ano\_nasc; 
	float nota;

Escreva um programa que leia o número n de alunos a serem cadastrados. Em seguida, um vetor V com n posições deve ser alocado 
dinamicamente usando uma função que retorna um ponteiro do tipo ALUNO. O programa deve preencher o vetor V e imprimir o 
registro dos alunos aprovados, isto é, com nota maior ou igual a 6,0. Para executar tais tarefas devem ser criadas funções para:
a) Alocar memória dinamicamente para um vetor do tipo ALUNO.
b) Preencher o vetor de alunos.
c) Imprimir o vetor de alunos.
d) Preencher o registro de um aluno.
e) Imprimir o registro de um aluno.
*/

// Autor: Nixon Moreira Silva

#include <stdio.h>
#include <stdlib.h>

// Estrutura do aluno
typedef struct aluno
{
	int matricula;
	char nome[50];
	int diaNasc;
	int mesNasc;
	int anoNasc;
	float nota;
} aluno_t;

aluno_t* alocaLista (int tamanho)
{
	// Aloca uma lista de aluno_t com o tamanho especificado
	return (aluno_t*) malloc(sizeof(aluno_t) * tamanho);
}

void preencherAluno (aluno_t* aluno)
{
	do
	{
		// Faca ate que um numero de matricula valido seja inserido
		printf("Insira o numero de matricula: ");
		scanf("%d", &aluno->matricula);

		// Verificao de erros
		if (aluno->matricula < 1)
		{
			printf("Matricula invalida!");
		}
	} while (aluno->matricula < 1);

	// Le o nome
	printf("Insira o nome do aluno: ");
	scanf("%s%*c", aluno->nome);

	do
	{
		// Faca ate que a data de nascimento seja valida
		printf("Insira a data de nascimento do aluno no formato DD MM AAAA: ");
		scanf("%d%d%d", &aluno->diaNasc, &aluno->mesNasc, &aluno->anoNasc);

	} while ((aluno->diaNasc < 1 || aluno->diaNasc > 31) ||
	(aluno->mesNasc < 1 || aluno->mesNasc > 12) ||
	(aluno->anoNasc < 1900));

	do
	{
		// Faca ate que a nota seja valida
		printf("Insira a nota do aluno: ");
		scanf("%f", &aluno->nota);
	} while (aluno->nota < 0.0 || aluno->nota > 10.0);
}

void preencherLista (aluno_t* lista, int tamanho)
{
	// Itera entre os elementos da lista, um por um,
	// envia endereco de memoria ao inves de copia
	// pois queremos que as modificacoes persistam
	// fora da funcao preencherAluno
	for (int i = 0; i < tamanho; i++)
	{
		printf("Preenchendo aluno [%d]:\n", (i + 1));
		preencherAluno(&lista[i]);
	}
}

void imprimirAluno (aluno_t aluno)
{
	// Se o aluno nao pegou media, entao nao imprima nada
	if (aluno.nota < 6.0)
		return;

	// Caso contrario, imprima as informacoes
	printf("=============\n");
	printf("Matricula: %d\n", aluno.matricula);
	printf("Nome: %s\n", aluno.nome);
	// %02d forca a imprimir (2) dois digitos inteiros (d), sendo o digito "nulo"
	// zeros a esquerda (0)
	printf("Data de Nascimento: %02d/%02d/%d\n", aluno.diaNasc, aluno.mesNasc, aluno.anoNasc);
	// .2f forca a imprimir o float com 2 digitos de precisao
	printf("Nota: %.2f\n", aluno.nota);
	printf("=============\n");
}

void imprimirLista (aluno_t* lista, int tamanho)
{
	// Itera entre os elementos da lista e imprime os alunos
	// cuja nota é MAIOR OU IGUAL a 6.0
	for (int i = 0; i < tamanho; i++)
	{
		imprimirAluno(lista[i]);
	}
}



int main (int argc, char* argv[])
{
	int n;
	aluno_t *alunoLista;

	printf("Digite o numero de alunos a cadastrar: ");
	scanf("%d", &n);

	// Chamada da funcao de alocacao
	alunoLista = alocaLista(n);

	// Tratamento de erros
	if (alunoLista == NULL)
	{
		printf("Erro na alocacao de lista!\n");
		return -1;
	}

	// Chamada do preenchimento de lista
	preencherLista(alunoLista, n);

	// Chamada da impressao de lista
	imprimirLista(alunoLista, n);

	// Liberacao da memoria
	free(alunoLista);

	return 0;
}