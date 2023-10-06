#include "contatinho.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct contato
{ // cria um tipo no da lista de contatos ou seja cria um no para uma pessoa
    char nome[11];
    int numero;
    struct contato *proximo;

} contatinho;

typedef struct lista
{ // cria um ponteiro lista que ira apontar para o primeiro elemento da lista de contatos
    contatinho *inicio;

} tipoLista;

tipoLista *criar_lista()
{ // cria o lista que é na verdade o ponteiro para o primeiro elemento ou seja o primeiro contato
    tipoLista *lista = calloc(1, sizeof(tipoLista));
    lista->inicio = NULL;

    return lista;
}

void inserir_contato(tipoLista *list, char nome[], int numero)
{ // ira inseir um contato na primeira posição se ele não foi inserido ainda

    contatinho *pessoa = calloc(1, sizeof(contatinho));
    strcpy(pessoa->nome, nome);
    pessoa->numero = numero;
    pessoa->proximo = NULL;

    if (list->inicio == NULL) // lista vazia
    {
        list->inicio = pessoa;
    }

    else // lista não esta vazia
    {
        contatinho *auxiliar = list->inicio;
        int teste = 0; // ira auxiliar para saber se o nome ja existe ou não

        while (auxiliar != NULL)
        {
            if (strcmp(auxiliar->nome, nome) == 0) // ja existe o nome na lista
                teste = 1;

            auxiliar = auxiliar->proximo;
        }

        if (teste == 1)
        { // contato ja inserido
            printf("Contatinho ja inserido\n");
            free(pessoa);
        }
        else
        { // ira colcoar o contato na lista
            pessoa->proximo = list->inicio;
            list->inicio = pessoa;
        }
    }
}

void pesquisar_contato(tipoLista *list, char nome[])
{
    contatinho *auxiliar = list->inicio; // ira apontar para o primeiro elemento
    contatinho *auxiliar2 = NULL;
    int test = 0;

    if (list->inicio == NULL) // lista está vazia
        printf("Contatinho nao encontrado\n");

    else // lista não está vazia
    {
        if (strcmp(auxiliar->nome, nome) == 0)
        { // contanto está na primeira posição
            printf("Contatinho encontrado: telefone %d\n", auxiliar->numero);
        }
        else
        { // contato não esta na primeira posição ,logo irei percorrer a lista para encontra-lo
            while (auxiliar != NULL)
            {

                if (strcmp(auxiliar->nome, nome) == 0)
                { // encontrou o contato
                    test = 1;
                    break;
                }
                auxiliar2 = auxiliar;
                auxiliar = auxiliar->proximo;
            }

            if (test == 1)
                printf("Contatinho encontrado: telefone %d\n", auxiliar->numero);

            else
                printf("Contatinho nao encontrado\n");
        }
    }
}

void remover_contato(tipoLista *list, char nome[])
{ // ira remover um contato se ele existir

    {
        contatinho *auxiliar = list->inicio;
        contatinho *auxiliar2 = NULL;
        int test = 0;

        if (list->inicio == NULL) // lista vazia
            printf("Operacao invalida: contatinho nao encontrado\n");

        else
        { // lista não está vazia
            if (strcmp(auxiliar->nome, nome) == 0)
            { // contato está na primeira posição
                list->inicio = auxiliar->proximo;
                free(auxiliar);
            }
            else
            { // contato não está na primeira posição, logo terei que percorrer para encontra-lo
                while (auxiliar != NULL)
                {

                    if (strcmp(auxiliar->nome, nome) == 0)
                    { // encontrou o contato
                        test = 1;
                        break;
                    }
                    auxiliar2 = auxiliar;
                    auxiliar = auxiliar->proximo;
                }

                if (test == 1)
                {
                    auxiliar2->proximo = auxiliar->proximo;
                    free(auxiliar);
                }

                else
                    printf("Operacao invalida: contatinho nao encontrado\n");
            }
        }
    }
}

void alterar_contato(tipoLista *list, char nome[], int numero)
{ // ira alterar o valor do numero de um contato

    {
        contatinho *auxiliar = list->inicio;
        contatinho *auxiliar2 = NULL;
        int test = 0;

        if (list->inicio == NULL) // lista vazia
            printf("Operacao invalida: contatinho nao encontrado\n");

        else
        { // lista não esta vazia
            if (strcmp(auxiliar->nome, nome) == 0)
            { // contanto está na primeira posição
                auxiliar->numero = numero;
            }
            else
            { // contato não está na primeira posição, logo terei que percorrer para encontra-lo
                while (auxiliar != NULL)
                {

                    if (strcmp(auxiliar->nome, nome) == 0)
                    { // entrou o contato
                        test = 1;
                        break;
                    }
                    auxiliar2 = auxiliar;
                    auxiliar = auxiliar->proximo;
                }

                if (test == 1)
                    auxiliar->numero = numero;

                else
                    printf("Operacao invalida: contatinho nao encontrado\n");
            }
        }
    }
}

void remove_lista(tipoLista **list)
{

    tipoLista *auxiliar = *list;

    contatinho *auxiliar2 = auxiliar->inicio;
    contatinho *auxiliar3 = NULL;

    while (auxiliar2 != NULL)
    {
        auxiliar3 = auxiliar2;
        auxiliar2 = auxiliar2->proximo;
        free(auxiliar3);
    }

    free(auxiliar);

    *list = NULL;
}
