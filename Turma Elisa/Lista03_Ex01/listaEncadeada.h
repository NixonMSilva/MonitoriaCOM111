// TAD para Lista Dinâmica Encadeada baseado no livro "Estrutura de dados descomplicada em lingugem C (André Backes)"

#ifndef _LISTA_ENCADEADA
#define _LISTA_ENCADEADA

struct aluno {
	int matricula;
	char nome[30];
	float nota;
};

// definição do struct elemento
struct elemento{
  struct aluno dado;
  struct elemento *prox;
};

// renomeando a estrutura elemento acima
typedef struct elemento Elemento;

// renomeando a estrutura aluno acima
typedef struct aluno Aluno;

//typedef struct elemento* Lista;
typedef struct elemento* Lista;

// funções para alocar e desalocar memória
Lista* criar_lista();
int liberar_lista(Lista *li);	

// funções para obter informações da lista
int tamanho_lista(Lista *li);
int lista_vazia(Lista *li);
int lista_cheia(Lista *li);

// funções para inserção de elementos da lista
int inserir_lista_inicio(Lista *li, Aluno dado);
int inserir_lista_final(Lista *li, Aluno dado);
int inserir_lista_ordenada(Lista *li, Aluno dado);

// funções para remoção de elementos da lista
int remover_lista_inicio(Lista *li);
int remover_lista_final(Lista *li);
int remover_lista_meio(Lista *li, Aluno dado);

// funções para buscar elementos na lista
int buscar_lista_posicao(Lista *li, int pos, Aluno *dado);
int buscar_lista_dado(Lista *li, Aluno dado, int *pos);

int imprimir_lista(Lista *li);

// ===============================================================
// Solucao inicio
// ===============================================================

Lista* concatena_lista (Lista *li1, Lista *li2);
Lista* copia_lista_remove_duplicados (Lista *li);
Lista* inverte_lista (Lista *li);

int verifica_ordenacao (Lista *li);
int calcula_tamanho (Elemento *li, int tamanho);

// ===============================================================
// Solucao fim
// ===============================================================

#endif



