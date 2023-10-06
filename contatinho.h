#ifndef CONTATINHO_H
#define CONTATINHO_H

typedef struct lista tipoLista;

typedef struct contato contatinho;

tipoLista *criar_lista();
void inserir_contato(tipoLista *list, char nome[], int numero);
void pesquisar_contato(tipoLista *list, char nome[]);
void remover_contato(tipoLista *list, char nome[]);
void alterar_contato(tipoLista *list, char nome[], int numero);
void remove_lista(tipoLista **list);

#endif