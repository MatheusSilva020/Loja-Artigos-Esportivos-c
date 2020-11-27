#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stock.h"

//cadastrarEstoque: recebe a lista do estoque e cadastra um novo produto.
void cadastrarEstoque(estoque **lista, int codigoProduto){
  estoque *novo = (estoque *)malloc(sizeof(estoque));

  if (novo == 0){
    printf("Erro de alocacao!!!\n");
  }else{
    setbuf(stdin, NULL);
    printf("\tNome: ");
    fgets(novo->nome, 101, stdin);
    novo->nome[strlen(novo->nome) - 1] = '\0';
    novo->codigo = codigoProduto;
    printf("\tValor(R$): ");
    scanf("%f", &novo->valor);
    printf("\tQuantidade: ");
    scanf("%d", &novo->qtd);
    novo->prox = NULL;
    if ((*lista)->codigo == 0){
      strcpy((*lista)->nome, novo->nome);
      (*lista)->codigo = novo->codigo;
      (*lista)->valor = novo->valor;
      (*lista)->qtd = novo->qtd;
    }else{
      pegarUltimoEstoque(lista)->prox = novo;
    }
    printf("\n\tPRODUTO CADASTRADO COM SUCESSO NO ESTOQUE!\n\n");
  }
}

//modificarEstoque: recebe a lista de estoque e altera seu cadastro.
void modificarEstoque(estoque **lista, int codigo){
  estoque *p = (*lista);
  int find = 0;

  while (p != NULL){
    if (p->codigo == codigo){
      find = 1;
      printf("\tPRODUTO ENCONTRADO! - Alterar cadastro\n");
      setbuf(stdin, NULL);
      printf("\tNome: ");
      fgets(p->nome, 101, stdin);
      p->nome[strlen(p->nome) - 1] = '\0';
      printf("\tCodigo: ");
      scanf("%d", &p->codigo);
      printf("\tValor(R$): ");
      scanf("%f", &p->valor);
      printf("\tQuantidade: ");
      scanf("%d", &p->qtd);

      printf("\tEstoque - alteracao\n");
      printf("\t");
      puts(p->nome);
      printf("\tCodigo - %d\n", p->codigo);
      printf("\tValor(R$) - %.2f\n", p->valor);
      printf("\tQuantidade - %d\n", p->qtd);
      printf("-------------------------------------------------\n");
    }
    p = p->prox;
  }
  if (find == 0){
    printf("\tERRO - Estoque nao encontrado!!!\n");
  }
}

//excluirEstoque: recebe a lista de produtos e o codigo a ser removido, busca e remove da lista.
void excluirEstoque(estoque **lista, int deleteCode){
  estoque *p = (*lista);
  estoque *anterior = NULL;
  int deleted = 0;
  
  while((p!=NULL)&&(deleted==0)){
  	if(p->codigo==deleteCode){
		if(anterior==NULL){                 //Primeiro item da Lista
			(*lista)=(*lista)->prox;		
			p->codigo=0;
		}else if(p->prox==NULL){           //Ultimo item da Lista
  			anterior->prox = NULL;
  			p->codigo=0;
  		}else{                            //No meio da Lista
			anterior->prox = p->prox;
			p->codigo=0;
		}
		free(p);
		deleted=1;
	}else{
		anterior = p;
	}
    p = p->prox;
  }
}
/*
//excluirEstoque: recebe o produto a ser removido e remove da lista.
void excluirEstoque(estoque *item){
  estoque *morta = (estoque*)malloc(sizeof(estoque));

  morta = item;
  item = morta->prox;
  free(morta);
}
*/

//recebeValor: usado para fazer a recepcao/devolucao do valor.
float recebeValor(estoque **lista, int codProduto){
  estoque *p = (*lista);
  float valor;

  while (p != NULL){
    if (p->codigo == codProduto){
      valor = p->valor;
    }
    p = p->prox;
  }
  return valor;
}

//checkEstoque: recebe o codigo do produto e a quantidade desejada, caso seja possivel, atualiza o estoque e retorna 1, e retorna 0 caso contrario.
int checkEstoque(estoque **lista, int codProduto, int quantidade){
  estoque *p = (*lista);
  int check = 0;

  while (p != NULL){
    if (p->codigo == codProduto && p->qtd >= quantidade){
      check = 1;
      p->qtd -= quantidade;
    }
    p = p->prox;
  }
  return check;
}

//pegarUltimoEstoque: recebe a lista de estoque e retorna o ultimo.
estoque *pegarUltimoEstoque(estoque **lista){
  estoque *p = (*lista);

  while (p->prox != NULL){
    p = p->prox;
  }
  return p;
}

//procuraEstoque: verifica se o produto existe ou nao no estoque. retorna 1 se positivo e 0 caso negativo.
int procuraEstoque(estoque **lista, int codigo){
  estoque *p = (*lista);
  int find = 0;

  while (p != NULL){
    if (p->codigo == codigo){
      find = 1;
    }
    p = p->prox;
  }
  return find;
}

//pegarEstoque: recebe a lista de estoque e o codigo e retorna o cliente desejado.
estoque *pegarEstoque(estoque **lista, int codigo){
  estoque *p = (*lista);

  while (p != NULL){
    if (p->codigo == codigo){
      return p;
    }
    p = p->prox;
  }
}

//imprimeEstoque: recebe a lista de estoque e imprime(JEITO DE ARRUMAR A ULTIMA IMPRESSAO SEM GAMBIARRA).
void imprimeEstoque(estoque **lista){
  estoque *p = (*lista);

  printf("\n\tESTOQUE\n");
  printf("\n\tCOD.PRODUTO     NOME       QTD      VALOR");
  printf("\n\t-------------------------------------------------");
  while (p != NULL){
    printf("\n\t#%-10d     %-6s     %3d      R$%.2f", p->codigo, p->nome, p->qtd, p->valor);
    p = p->prox;
  }
  printf("\n\t-------------------------------------------------\n");
}
