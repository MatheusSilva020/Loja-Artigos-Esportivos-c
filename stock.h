#ifndef STOCK_H
#define STOCK_H

//structs(todas possuem base em "listas ligadas" - possuem um ponteiro para o prox item da lista).
typedef struct stock{
  char nome[100];
  int codigo;
  float valor;
  int qtd;
  struct stock *prox;
} estoque;

void cadastrarEstoque(estoque **, int);
void modificarEstoque(estoque **, int);
void excluirEstoque(estoque **, int);
int checkEstoque(estoque **, int, int);
float recebeValor(estoque **, int);
estoque *pegarUltimoEstoque(estoque **);
int procuraEstoque(estoque **, int);
estoque *pegarEstoque(estoque **, int);
void imprimeEstoque(estoque **);

#endif
