#include <stdio.h>
#include <stdlib.h>

//SUGESTAO DE ESTRUTURA PARA GUARDAR UM BLOCO
//PODE MUDAR SE QUISER
typedef struct bloco{
  int id;
  int altura;
  struct bloco* prox;
} bloco;

typedef struct bloco * p_Bloco;

//SUGESTAO DE ESTRUTURA PARA GUARDAR UM MACACO
//PODE MUDAR SE QUISER
typedef struct Macaco{
  int altura;
  struct bloco* lista_blocos;
} Macaco;

//

// Macaco.altura = 0;
// Macaco.lista_blocos = NULL;

typedef struct Macaco * p_Macaco;


//SUGESTAO DE FUNCOES PARA IMPRESSAO
//PODE MUDAR SE QUISER
void imprime_blocos(p_Bloco lista){
  if(lista == NULL) return;
  imprime_blocos(lista->prox);
  printf(" %d %d", lista->id, lista->altura);
}

void imprime_macacos(p_Macaco M, int num_macacos){
  for(int i = 0; i < num_macacos; i++){
    printf("M[%d] altura = %d:", i, M[i].altura);
    imprime_blocos(M[i].lista_blocos);
    printf("\n");
  }
}

p_Macaco inicializa_macacos(int num_macacos)
{
    // Inicializa vetor de macacos
    return (p_Macaco) calloc (num_macacos, sizeof(Macaco));
}

void libera_lista (p_Bloco bloco)
{
    // Recursivamente, libere a pilha bloco por bloco
    if (bloco == NULL)
        return;

    libera_lista(bloco->prox);

    // Por fim libere a pilha em si
    free(bloco);
}

void libera_macacos(p_Macaco M, int num_macacos)
{
    // Libera os macacos um por um
    for (int i = 0; i < num_macacos; ++i)
    {
        libera_lista (M[i].lista_blocos);
    }
    // Por fim, libera o ponteiro da lista de macacos
    free (M);
}

int encontraMenor (p_Macaco lista, int num_macacos)
{
    // Percorre o vetor de macacos em busca do menor valor
    int menor, indiceMenor;
    menor = -1;
    indiceMenor = 0;
    for (int i = 0; i < num_macacos; ++i)
    {
        // Se um novo menor valor for encontrado, atualize as vari�veis auxiliares
        if (lista[i].altura < menor || menor == -1)
        {
            menor = lista[i].altura;
            indiceMenor = i;
        }
    }
    // Retorna o indice da menor pilha de macacos
    return indiceMenor;
}


void adicionaNaLista (p_Macaco lista, int indice, int id_bloco, int altura_bloco)
{
    // Aloca o novo bloco
    p_Bloco bloco = (p_Bloco) malloc(sizeof(bloco));
    // Atualiza as informa��es do bloco conforme os par�metros
    bloco->prox = lista[indice].lista_blocos;
    bloco->id = id_bloco;
    bloco->altura = altura_bloco;
    // Atualiza o �ndice do bloco do topo
    lista[indice].lista_blocos = bloco;
    // Atualiza a altura da pilha
    lista[indice].altura += altura_bloco;
}

void bota_no_menor (p_Macaco lista, int num_macacos, int id_bloco, int altura_bloco)
{
    int indiceMenor;
    // Encontra o vetor de macacos com o menor �ndice
    indiceMenor = encontraMenor(lista, num_macacos);;
    // Adiciona o novo bloco a lista de macacos
    adicionaNaLista(lista, indiceMenor, id_bloco, altura_bloco);
}

//******************************
//VOCE NAO PODE MODIFICAR A MAIN
//******************************
int main(int argc, char * argv[]){

  p_Macaco M;
  int num_macacos;
  int id_bloco;
  int altura_bloco;

  //le o numero de macacos
  scanf("%d", &num_macacos);

  M = inicializa_macacos(num_macacos);

  //le o primeiro bloco
  scanf("%d %d", &id_bloco, &altura_bloco);
  while(id_bloco != -1){
    bota_no_menor(M, num_macacos, id_bloco, altura_bloco);
    //le o proximo bloco
    scanf("%d %d", &id_bloco, &altura_bloco);
  }

  imprime_macacos(M, num_macacos);

  //Lembre que cada macaca tem uma lista que precisa ser liberada
  libera_macacos(M, num_macacos);
  return 0;
}





