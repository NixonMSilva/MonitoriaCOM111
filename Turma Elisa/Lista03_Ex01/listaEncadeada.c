// TAD para Lista Dinâmica Encadeada baseado no livro "Estrutura de dados descomplicada em lingugem C (André Backes)"

#include <stdio.h>
#include <stdlib.h>
#include "listaEncadeada.h"

// função para alocar memória do tipo Lista
Lista* criar_lista()
{
  Lista *li = (Lista*) malloc(sizeof(Lista));  

  // se a lista foi criada corretamente, indica que ela está vazia
  if(li != NULL){
    *li = NULL;
  } 

  return li;
}


// função para liberar memória
int liberar_lista(Lista *li)
{
  if(li == NULL){    
    return 0;
  }

  // libera todos os nós da lista que foram alocados
  Elemento *no;
  while(*li != NULL){
    no = *li;
    *li = (*li)->prox;
    free(no);
  }

  // libera o ponteiro da lista
  free(li);

  return 1;  
}

// função para obter o tamanho da lista
int tamanho_lista(Lista *li)
{
  // a lista não foi criada corretamente
  if(li == NULL){
    return -1;
  }

  int cont = 0;
  Elemento *no = *li;

  // acrescenta cont até acabar a lista
  while(no != NULL){
    cont++;
    no = no->prox;
  }

  return cont;
}

// função para verificar se a lista está vazia
int lista_vazia(Lista *li)
{
  // verifica se houve problema na criação da lista
  // ou seja, li não é uma lista válida
  if(li == NULL){
    return -1;
  }

  // verifica se a lista foi criada corretamente
  // mas não contém nenhum valor
  if(*li == NULL){
    return 1;
  }

  // se houver elementos, retorna 0
  return 0;
}


// função para verificar se a lista está cheia (não se aplica)
int lista_cheia(Lista *li)
{
  return 0;
}


// função para alocar memória do tipo Elemento
Elemento* criar_elemento()
{
  Elemento *no = (Elemento*) malloc(sizeof(Elemento));  

  return no;
}


// função para inserir elemento no início da lista
int inserir_lista_inicio(Lista *li, Aluno dado)
{
  if(li == NULL){
    return 0;
  }

  // cria um elemento novo
  Elemento *no;
  no = criar_elemento();

  if(no == NULL){
    return 0;
  }

  // atribui valores ao elemento novo
  no->dado = dado;
  no->prox = (*li);

  // insere elemento no início da lista
  *li = no;

  return 1;
}


// função para inserir elemento no final da lista
int inserir_lista_final(Lista *li, Aluno dado)
{
  if(li == NULL){
    return 0;
  }

  // cria um elemento novo
  Elemento *no;
  no = criar_elemento();

  if(no == NULL){
    return 0;
  }

  // atribui valores ao elemento novo
  no->dado = dado;
  no->prox = NULL;

  // se a lista estiver vazia, insere no início da lista
  if( (*li) == NULL ){
    *li = no;

  }else{

    // senão percorre a lista até o fim e insere no final
    Elemento *aux;
    aux = *li;

    while(aux->prox != NULL){
      aux = aux->prox;
    }
    aux->prox = no;
  }

  return 1;
}


// função para inserir elemento na lista de forma ordenada
int inserir_lista_ordenada(Lista *li, Aluno dado)
{
  if(li == NULL){
    return 0;
  }

  // cria um elemento novo
  Elemento *no;
  no = criar_elemento();

  if(no == NULL){
    return 0;
  }

  // atribui valores ao elemento novo
  no->dado = dado;

  // se a lista estiver vazia, insere no início da lista
  if( (*li) == NULL ){
    no->prox = NULL;
    *li = no;

  }else{

    // senão percorre a lista até achar o local correto e insere
    Elemento *anterior, *atual;
    atual = *li;

    while(atual != NULL && atual->dado.matricula < dado.matricula){
      anterior = atual;
      atual = atual->prox;
    }
    
    // insere na primeira posição
    if( atual == (*li) ){
      no->prox = (*li);
      *li = no;

    }else{
      no->prox = atual;
      anterior->prox = no;
    }
  }

  return 1;
}


// função para remover elemento do início da lista
int remover_lista_inicio(Lista *li)
{
  if(li == NULL){
    return 0;
  }

  // lista vazia, não remove nada
  if((*li) == NULL){
    return 0;
  }

  // muda inicio para o proximo elemento
  Elemento *atual;
  atual = *li;
  *li = atual->prox;

  // libera Elemento atual
  free(atual);

  return 1;
}


// função para remover elemento do final da lista
int remover_lista_final(Lista *li)
{
  if(li == NULL){
    return 0;
  }

  // lista vazia, não remove nada
  if((*li) == NULL){
    return 0;
  }

  // percorre lista até o final
  Elemento *anterior, *atual;
  atual = *li;
  
  while(atual->prox != NULL){
    anterior = atual;
    atual = atual->prox;
  }

  // remove o primeiro elemento, se este for o único da lista
  if(atual == (*li)){ 
    *li = atual->prox; // igual *li = NULL 

  }else{
    anterior->prox = atual->prox; // igual anterior->prox = NULL
  }

  //libera Elemento atual
  free(atual);

  return 1;

}


// função para remover elemento do meio da lista
int remover_lista_meio(Lista *li, Aluno dado)
{
  if(li == NULL){
    return 0;
  }

  // lista vazia, não remove nada
  if((*li) == NULL){
    return 0;
  }

  // percorre a lista até achar o elemento e remove
  Elemento *anterior, *atual;
  atual = *li;

  while (atual != NULL && atual->dado.matricula != dado.matricula){
    anterior = atual;
    atual = atual->prox;
  }

  // elemento não foi encontrado
  if(atual == NULL){
    return 0;
  }

  // remove o primeiro elemento
  if(atual == (*li)){
    *li = atual->prox;

  }else{
    anterior->prox = atual->prox;
  }

  //libera Elemento atual
  free(atual);
  return 1;

}

int buscar_lista_posicao(Lista *li, int pos, Aluno *dado)
{
  // verifica se a lista foi criada corretamente, se não está vazia e se a posição é válida (note que é a posição na lista e não o índice do vetor)
  if(li == NULL || (*li) == NULL || pos <= 0){
    return 0;
  }

  Elemento *no = *li;
  int i = 1;

  while(no != NULL && i < pos){
    no = no->prox;
    i++;
  }

  // posição não existe na lista
  if(no == NULL){
    return 0;
  }

  // copia o dado da posição desejada (parâmetro passado por referência)
  *dado = no->dado;

  return 1;
}


int buscar_lista_dado(Lista *li, Aluno dado, int *pos)
{
  // verifica se a lista foi criada corretamente
  if(li == NULL || (*li) == NULL){
    return 0;
  }

  // procura a posição no vetor onde o dado desejado se encontra
  Elemento *no = *li;
  int i = 1;

  while(no != NULL && no->dado.matricula != dado.matricula) {
    no = no->prox;
    i++;
  }
  
  // verifica se elemento não foi encontrado 
  if(no == NULL){ 
    return 0;
  }

  // copia a posição da lista onde o dado foi encontrado (parâmetro passado por referência)
  *pos = i; 

  return 1;
}



//**************************************************************************
// função para imprimir a lista dinâmica
int imprimir_lista (Lista *li)
{
    if(li == NULL || (*li) == NULL){
      return 0;
    }

    Elemento *aux = (*li);

    while(aux->prox != NULL) 
	{
		printf("Matricula: %d\n", aux->dado.matricula);
		printf("Nome: %s\n", aux->dado.nome);
		printf("Nota: %.1f\n", aux->dado.nota);
		printf("=============\n");
		aux = aux->prox;
    }

    printf("Matricula: %d\n", aux->dado.matricula);
	printf("Nome: %s\n", aux->dado.nome);
	printf("Nota: %.1f\n", aux->dado.nota);
	printf("=============\n");

    return 1;
}


// ===============================================================
// Solucao inicio
// ===============================================================

// i) Receba duas listas e retorne uma terceira contendo as duas // primeiras concatenadas.

Lista* concatena_lista (Lista *li1, Lista *li2)
{
	int ok;
	Lista *li3 = criar_lista();
	Elemento *aux = (*li1);

	// Concatenando os elementos de l1
	while (aux != NULL)
	{
		// Copia o elemento pra lista 3
		ok = inserir_lista_final(li3, aux->dado);
		// Caso algo de errado, encerre a funcao aqui
		if (!ok)
			return NULL;
		aux = aux->prox;
	}
	
	aux = (*li2);

	// Concatenando os elementos de l2
	while (aux != NULL)
	{
		// Copia o elemento pra lista 3
		ok = inserir_lista_final(li3, aux->dado);
		// Caso algo de errado, encerre a funcao aqui
		if (!ok)
			return NULL;
		// Itera para o proximo elemento
		aux = aux->prox;
	}

	// Retorna a terceira lista
	return li3;
}

// ii) Dada uma lista L1, crie e retorne uma cópia dela em L2 // eliminando os valores repetidos

Lista* copia_lista_remove_duplicados (Lista *li)
{
	int ok, duplicado;
	Lista *li2 = criar_lista();
	Elemento *aux_i = (*li);
	Elemento *aux_j = (*li);
	
	while (aux_i != NULL)
	{
		duplicado = 0;

		// Itera a partir do prox. elemento a procura de duplicatas
		aux_j = aux_i->prox;
		while (aux_j != NULL && duplicado == 0)
		{
			if (aux_j->dado.matricula == aux_i->dado.matricula)
			{
				duplicado = 1;
			}
			aux_j = aux_j->prox;
		}

		if (duplicado == 0) 
		{
			// Apenas adiciona se nao for duplicado
			ok = inserir_lista_ordenada(li2, aux_i->dado);
			// Caso algo de errado, encerre a funcao aqui
			if (!ok)
				return NULL;
		}

		// Itera para o proximo elemento
		aux_i = aux_i->prox;
	}
	
	// Retorna a segunda lista
	return li2;
}

// iii) Dada uma lista L1, inverta a lista e armazene em L2. A
// função deve retornar a lista L2.

Lista* inverte_lista (Lista *li)
{
	int ok;
	Lista *li2 = criar_lista();
	Elemento *aux = (*li);

	while (aux != NULL)
	{
		// Insere elemento no comeco
		ok = inserir_lista_inicio(li2, aux->dado);
		// Caso algo de errado, encerre a funcao aqui
		if (!ok)
			return NULL;
		// Itera para o proximo elemento
		aux = aux->prox;
	}

	// Retorna a segunda lista
	return li2;
}

// iv) Verifique se a lista está ordenada ou não (crescente ou 
// decrescente), de acordo com a matrícula do aluno.

int verifica_ordenacao (Lista *li)
{
	// Estado:
	// 0 - Nao ordenado
	// 1 - Crescente
	// -1 - Descrente
	int anterior = -1, atual, estado = 0;
	Elemento *aux = (*li);

	while (aux != NULL)
	{
		// Copia o elemento atual para o atual
		atual = aux->dado.matricula;
		// (anterior == - 1) -> Esta iterando o primeiro elemento da lista
		if (anterior != -1)
		{
			if (anterior > atual)
			{
				// Lista desordenada
				if (estado == 1)
					return 0;

				// Continua ordenacao
				estado = -1;
			}
			else if (anterior < atual)
			{
				// Lista desordenada
				if (estado == -1)
					return 0;

				// Continua ordenacao
				estado = 1;
			}
		}
		// Copia o elemento atual para o anterior
		anterior = aux->dado.matricula;
		// Itera para o proximo elemento
		aux = aux->prox;
	}

	return estado;
}

// v) Calcule e retorne o tamanho da lista dinâmica encadeada. 
// A função deve ser recursiva.

int calcula_tamanho (Elemento *li, int tamanho)
{
	if (li == NULL)
		return tamanho;
	
	return calcula_tamanho(li->prox, tamanho + 1);
}

// ===============================================================
// Solucao fim
// ===============================================================