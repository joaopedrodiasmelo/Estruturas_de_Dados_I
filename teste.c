// joão pedro dias melo - 13828592
// Fernando Mezher Silva Lopes - 12725515
// Beatriz Vieira da Silva Andrade - 13692362

#include "contatinho.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{

    tipoLista *lista_contatos = criar_lista(); // criação da lista

    char operacao, nome[11];
    int numero;

    while (operacao != '0')
    {
        scanf("%c", &operacao);

        if (operacao == '0')
        { // se a operação for =0 ira remover a lista criada
            remove_lista(&lista_contatos);
            return 0;
        }

        if (operacao == 'I' || operacao == 'A' || operacao == 'P' || operacao == 'R')
        { // apartir do caractere ira entrar em uma opsção do switch

            switch (operacao)
            {
            case 'I': // ira inserir um contato apenas se esse não tiver sido inserido antes
                scanf("%s", nome);
                scanf("%d", &numero);
                inserir_contato(lista_contatos, nome, numero);
                break;

            case 'P': // ira pesquisar um contato
                scanf("%s", nome);
                pesquisar_contato(lista_contatos, nome);
                break;

            case 'R': // ira remover um contato caso ele exista
                scanf("%s", nome);
                remover_contato(lista_contatos, nome);
                break;

            case 'A': // ira alterar um contato caso ele exista
                scanf("%s", nome);
                scanf("%d", &numero);
                alterar_contato(lista_contatos, nome, numero);
                break;
            }
        }
    }

    return 0;
}
