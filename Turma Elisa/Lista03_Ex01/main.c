// Resolucao Lista 3

// Autor: Nixon Moreira Silva

// bibliotecas do sistema
#include <stdio.h>
#include <stdlib.h>

// bibliotecas do projeto
#include "listaEncadeada.h"

int criar_dado(Aluno *dado);

// funcao principal
int main(void) {

  // no início a lista está vazia, logo, o ponteiro inicio tem valor NULL
  //o ponteiro inicio conterá o endereço do primeiro elemento da lista
  Lista *li = NULL;
  Lista *li2 = NULL;
  Lista *li3 = NULL;
  int opcao, ok, pos, cod, estado;
  struct aluno dado;
  int matriculaDado;

  // menu de opções para execuções de operações sobre a lista
  do
  {
    printf("\n\nMenu de opções");
    printf("\n1 - Criar lista");
    printf("\n2 - Liberar lista");
    printf("\n3 - Inserir elemento no início");
    printf("\n4 - Inserir elemento no final");
    printf("\n5 - Inserir elemento (ordenado)");
    printf("\n6 - Remover elemento do início");
    printf("\n7 - Remover elemento do final");
    printf("\n8 - Remover elemento (qualquer)");
    printf("\n9 - Buscar elemento pela posição");
    printf("\n10 - Buscar elemento pelo dado");
    printf("\n11 - Imprimir lista");
	printf("\n12 - Concatena listas 1 e 2");
	printf("\n13 - Copia lista 1 em 2 sem repeticoes");
	printf("\n14 - Inverte lista 1 em 2");
	printf("\n15 - Verificao ordenacao de lista");
	printf("\n16 - Imprime tamanho de lista");
    printf("\n17 - Sair");
    printf("\nOpção: ");
    scanf("%d", &opcao);

    switch(opcao){

      case 1:

		printf ("Insira o codigo da lista a ser criada (1 ou 2): "
		);
		scanf("%d", &cod);

		if (cod == 1)
		{
			// criar lista
			li = criar_lista();

			if(li != NULL)
			{
				printf("\n Lista 1 criada com sucesso!");
			}
			else
			{
				printf("\n Lista 1 não criada!");
			}
		}
		else if (cod == 2)
		{
			// criar lista
			li2 = criar_lista();

			if(li2 != NULL)
			{
				printf("\n Lista 2 criada com sucesso!");
			}
			else
			{
				printf("\n Lista 2 não criada!");
			}
		}
		else
		{
			printf("Codigo invalido!\n");
		}
        
        break;

      case 2:

		printf ("Insira o codigo da lista a ser liberada (1 / 2 / 3): "
		);
		scanf("%d", &cod);

		if (cod == 1)
		{
			// liberar lista
			ok = liberar_lista(li);
		}
		else if (cod == 2)
		{
			ok = liberar_lista(li2);
		}
		else if (cod == 3)
		{
			ok = liberar_lista(li3);
		}
		else
		{
			printf("Codigo invalido!\n");
		}

		if(ok)
		{
			printf("\n Lista liberada com sucesso!");
		}
		else
		{
			printf("\n Lista não liberada!");
		}

        
        break;

      case 3:

	  	printf ("Insira o codigo da lista para insercao (1 ou 2): ");
		scanf("%d", &cod);

		// inserir elemento no início
        ok = criar_dado(&dado);

		if (cod == 1)
		{
			ok = inserir_lista_inicio(li, dado);
		}
		else if (cod == 2)
		{
			ok = inserir_lista_inicio(li2, dado);
		}
		else
		{
			printf("Codigo invalido!\n");
		}

        if(ok == 1)
		{
        	printf("\n Inserção realizada com sucesso!");
        }
		else
		{
        	printf("\n Falha na inserção!");
        }

        break;

      case 4:

	  	printf ("Insira o codigo da lista para insercao (1 ou 2): ");
		scanf("%d", &cod);

        // inserir elemento no final
        ok = criar_dado(&dado);
        
		if (cod == 1)
		{
			ok = inserir_lista_final(li, dado);
		}
		else if (cod == 2)
		{
			ok = inserir_lista_final(li2, dado);
		}
		else
		{
			printf("Codigo invalido!\n");
		}

        if(ok == 1)
		{
        	printf("\n Inserção realizada com sucesso!");
        }
		else
		{
        	printf("\n Falha na inserção!");
        }

        break;

      case 5:

	  	printf ("Insira o codigo da lista para insercao (1 ou 2): ");
		scanf("%d", &cod);

        // inserir elemento de forma ordenada
        ok = criar_dado(&dado);
        
		if (cod == 1)
		{
			ok = inserir_lista_ordenada(li, dado);
		}
		else if (cod == 2)
		{
			ok = inserir_lista_ordenada(li2, dado);
		}
		else
		{
			printf("Codigo invalido!\n");
		}

        if(ok == 1)
		{
			printf("\n Inserção realizada com sucesso!");
        }else
		{
			printf("\n Falha na inserção!");
        }

        break;

      case 6:

	  	printf ("Insira o codigo da lista para remocao (1 ou 2): ");
		scanf("%d", &cod);

		if (cod == 1)
		{
			// remover elemento do início
        	ok = remover_lista_inicio(li);
		}
		else if (cod == 2)
		{
			// remover elemento do início
        	ok = remover_lista_inicio(li2);
		}
		else
		{
			printf("Codigo invalido!\n");
		}

        if(ok == 1)
		{
        	printf("\n Remoção realizada com sucesso!");
        }
		else
		{
			printf("\n Falha na remoção!");
        }
        break;

      case 7:

	  	printf ("Insira o codigo da lista para remocao (1 ou 2): ");
		scanf("%d", &cod);

		if (cod == 1)
		{
			// remover elemento do final
        	ok = remover_lista_final(li);
		}
		else if (cod == 2)
		{
			// remover elemento do final
        	ok = remover_lista_final(li2);
		}
		else
		{
			printf("Codigo invalido!\n");
		}

        if(ok == 1){
          printf("\n Remoção realizada com sucesso!");
        }else{
          printf("\n Falha na remoção!");
        }
        break;

      case 8:

	  	printf ("Insira o codigo da lista para remocao (1 ou 2): ");
		scanf("%d", &cod);

		// remover elemento do meio
		printf("\n Número a ser removido: ");
		scanf("%d", &dado.matricula);

		if (cod == 1)
		{
			// remover elemento do fmeio
        	ok = remover_lista_meio(li, dado);
		}
		else if (cod == 2)
		{
			// remover elemento do meio
        	ok = remover_lista_meio(li2, dado);
		}
		else
		{
			printf("Codigo invalido!\n");
		}

		

		if(ok == 1){
		printf("\n Remoção realizada com sucesso!");
		}else{
		printf("\n Falha na remoção!");
		}
		break;

      case 9:

	  	printf ("Insira o codigo da lista para busca (1/2/3): ");
		scanf("%d", &cod);

        // busca elemento pela posicao
        printf("\n Posição do elemento a ser buscado: ");
        scanf("%d", &pos);

		if (cod == 1)
		{
			ok = buscar_lista_posicao(li, pos, &dado);
		}
		else if (cod == 2)
		{
			ok = buscar_lista_posicao(li2, pos, &dado);
		}
		else if (cod == 3)
		{
			ok = buscar_lista_posicao(li3, pos, &dado);
		}
		else
		{
			printf("Codigo invalido!\n");
		}

        if(ok)
		{
          	printf("\n Busca realizada com sucesso!");
          	printf("\n Elemento da %dª posição: \n", pos);
          	printf("Matricula: %d\n", dado.matricula);
			printf("Nome: %s\n", dado.nome);
			printf("Nota: %.1f\n", dado.nota);
        }
		else
		{
          printf("\n Posição não existe!");
        }

        break;

      case 10:

	  	printf ("Insira o codigo da lista para busca (1/2/3): ");
		scanf("%d", &cod);

        // busca elemento pelo dado
        printf("\n Código do produto a ser buscado: ");
        scanf("%d", &dado.matricula);

		if (cod == 1)
		{
			ok = buscar_lista_dado(li, dado, &pos);
		}
		else if (cod == 2)
		{
			ok = buscar_lista_dado(li2, dado, &pos);
		}
		else if (cod == 3)
		{
			ok = buscar_lista_dado(li3, dado, &pos);
		}
		else
		{
			printf("Codigo invalido!\n");
		}        

        if(ok)
		{
			printf("\n Busca realizada com sucesso!");
			printf("\n Elemento da %dª posição: ", pos);
			printf("%d", dado.matricula);
        }
		else
		{
          	printf("\n Elemento não encontrado!");
        }

      case 11:

	  	printf ("Insira o codigo da lista para impressao (1/2/3): ");
		scanf("%d", &cod);

		 // imprime a lista
        printf("\n Lista encadeada: \n");

		if (cod == 1)
		{
			ok = imprimir_lista(li);
		}
		else if (cod == 2)
		{
			ok = imprimir_lista(li2);
		}
		else if (cod == 3)
		{
			ok = imprimir_lista(li3);
		}
		else
		{
			printf("Codigo invalido!\n");
		}        

        if(!ok)
		{
        	printf("\n Lista não encontrada!");
        }

        break;

// ===============================================================
// Solucao inicio
// ===============================================================

	  case 12:

	  	// Concatena lista 1 e 2 em 3
	  	li3 = concatena_lista(li, li2);
		if (li3 != NULL)
		{
			printf("Sucesso! Imprimindo lista...\n");
			ok = imprimir_lista(li3);
		}
		else
		{
			printf("Erro durante operacao!");
		}
		break;
	
	  case 13:

		// Libera lista 2 atual
		liberar_lista(li2);
	  	// Copia lista 1 em 2 sem repeticoes;
	  	li2 = copia_lista_remove_duplicados (li);
		if (li2 != NULL)
		{
			printf("Sucesso! Imprimindo lista...\n");
			ok = imprimir_lista(li2);
		}
		else
		{
			printf("Erro durante operacao!");
		}
		break;
	
	  case 14:

	  	// Libera a lista 2 atual
		liberar_lista(li2);
		// Copia a lista 1 em 2 invertido
		li2 = inverte_lista(li);
		if (li2 != NULL)
		{
			printf("Sucesso! Imprimindo lista...\n");
			ok = imprimir_lista(li2);
		}
		else
		{
			printf("Erro durante operacao!");
		}
		break;
	
	  case 15:

		printf ("Insira o codigo da lista para verificar ordenacao (1/2/3): ");
		scanf("%d", &cod);

		if (cod == 1)
		{
			if (li == NULL)
			{
				printf("Lista nao alocada!");
			}
			else
			{
				estado = verifica_ordenacao(li);
			}
			
		}
		else if (cod == 2)
		{
			if (li2 == NULL)
			{
				printf("Lista nao alocada!");
			}
			else
			{
				estado = verifica_ordenacao(li2);
			}	
		}
		else if (cod == 3)
		{
			if (li3 == NULL)
			{
				printf("Lista nao alocada!");
			}
			else
			{
				estado = verifica_ordenacao(li3);
			}
		}
		else
		{
			printf("Codigo invalido!\n");
		}        

		if (estado == 0)
		{
			printf("Lista %d nao esta ordenada!\n", cod);
		}
		else if (estado == 1)
		{
			printf("Lista %d esta ordenada crescentemente!\n", cod);
		}
		else if (estado == -1)
		{
			printf("Lista %d esta ordenada descrescentemente!\n", cod);
		}

	  	break;

	  case 16:

		printf ("Insira o codigo da lista para verificar o tamanho (1/2/3): ");
		scanf("%d", &cod);

		if (cod == 1)
		{
			if (li == NULL)
			{
				printf("Lista nao alocada!");
			}
			else
			{
				printf("Tamanho da lista %d: %d\n", cod, calcula_tamanho((*li), 0));
			}
			
		}
		else if (cod == 2)
		{
			if (li2 == NULL)
			{
				printf("Lista nao alocada!");
			}
			else
			{
				printf("Tamanho da lista %d: %d\n", cod, calcula_tamanho((*li2), 0));
			}	
		}
		else if (cod == 3)
		{
			if (li3 == NULL)
			{
				printf("Lista nao alocada!");
			}
			else
			{
				printf("Tamanho da lista %d: %d\n", cod, calcula_tamanho((*li3), 0));
			}
		}
		else
		{
			printf("Codigo invalido!\n");
		}        

	    break;

// ===============================================================
// Solucao fim
// ===============================================================

	  case 17:

        // libera memória e finaliza programa
        liberar_lista(li);
		liberar_lista(li2);
		liberar_lista(li3);
        printf("\nFinalizando...");
        break;

      default:
        printf("\nOpção inválida!");
        break;
    }

  } while(opcao != 12);

  return 0;
}

int criar_dado (struct aluno *dado)
{  
	if (dado == NULL)
		return 0;

    printf("Digite a matricula: ");
    scanf("%d", &dado->matricula);
	printf("Digite o nome: ");
	scanf("%s", dado->nome);
	printf("Digite a nota: ");
	scanf("%f", &dado->nota);

    return 1;
}