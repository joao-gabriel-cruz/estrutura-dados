#include <iostream>
#include <stdlib.h>

using namespace std;

struct No
{
  int chave;
  No *proximo;
};

struct Lista
{
  No *inicio;
  int quantidade;
};

void iniciar_lista(Lista *lista)
{
  lista->inicio = NULL;
  lista->quantidade = 0;
}

No *inserir_lista(No *lista, int chave)
{
  No *novo = (No *)malloc(sizeof(No));
  novo->chave = chave;
  novo->proximo = lista;

  return novo;
};

No *remover(No *lista, int possicao)
{
  if (lista == nullptr)
  {
    return NULL;
  };

  if (possicao == 0)
  {
    No *novo_no = lista->proximo;
    free(lista);
    return novo_no;
  };
  No *atual = lista;
  No *anterior_index = NULL;
  No *anterior = NULL;
  int contador = 0;

  for (No *p = atual; p->proximo != NULL; anterior_index = p, p = p->proximo, contador++)
  {
    if (possicao == contador)
    {
      atual = p;
      anterior = anterior_index;
      cout << "Item removido: " << p->chave << endl;
      cout << "Posição: " << contador << endl;
    };
  };
  // cout << "Atual: " << atual->chave << endl;
  // cout << "Anterior: " << anterior->chave << endl;

  if (atual == NULL)
  {
    cout << "Elemento não encontrado";
    return lista;
  };

  anterior->proximo = atual->proximo;
  free(atual);
  return lista;
};

void listar(No *lista)
{
  for (No *p = lista; p->proximo != NULL; p = p->proximo)
  {
    cout << "No: " << p->chave << endl;
    cout << "proximo no: " << p->proximo->chave << endl;
  };
};

No *busca_por_chave(No *lista, int chave)
{
  for (No *p = lista; p->proximo != NULL; p = p->proximo)
  {
    if (p->chave == chave)
      return p;
  }
  return NULL;
}

int main()
{
  No *lista = inserir_lista(NULL, 1);
  lista = inserir_lista(lista, 2);
  // lista = inserir_lista(lista, 3);
  // lista = inserir_lista(lista, 4);
  // lista = inserir_lista(lista, 5);
  listar(lista);
  // cout << "Lista antes de remover" << endl;
  // remover(lista, 1);
  // cout << "Lista depois de remover" << endl;

  // listar(lista);

  // No *resultado = busca_por_chave(lista, 158);
  // cout << resultado->chave;
}