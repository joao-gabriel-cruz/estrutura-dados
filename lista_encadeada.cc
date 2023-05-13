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
  No *atual = lista;
  No *anterior_index = NULL;
  No *anterior = NULL;
  int contador = 0;

  if (lista == nullptr)
  {
    cout << "Lista vazia" << endl;
    return NULL;
  };

  if (possicao == 0)
  {
    No *novo_no = lista->proximo;
    lista->chave = novo_no->chave;
    lista->proximo = novo_no->proximo;

    return lista;
  };

  for (No *p = atual; contador <= possicao; contador++, anterior_index = p, p = p->proximo)
  {
    if (possicao == contador)
    {
      atual = p;
      anterior = anterior_index;
      cout << "Item removido: " << p->chave << endl;
      cout << "Posicao: " << contador << endl;
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

No *inserit_por_posicao(No *lista, int possicao, int chave)
{
  No *atual = lista;
  No *anterior_index = NULL;
  No *anterior = NULL;
  int contador = 0;

  if (lista == nullptr)
  {
    cout << "Lista vazia" << endl;
    return NULL;
  };

  if (possicao == 0)
  {
    No *novo_no = (No *)malloc(sizeof(No));

    novo_no->chave = chave;
    novo_no->proximo = lista;

    return lista;
  };

  for (No *p = atual; contador <= possicao; contador++, anterior_index = p, p = p->proximo)
  {
    if (possicao == contador)
    {
      atual = p;
      anterior = anterior_index;
    };
  };
  // cout << "Atual: " << atual->chave << endl;

  No *novo_no = (No *)malloc(sizeof(No));
  novo_no->chave = chave;
  novo_no->proximo = atual;
  anterior->proximo = novo_no;
  return lista;
};

void listar(No *lista)
{
  for (No *p = lista; p != nullptr; p = p->proximo)
  {
    cout << "No: " << p->chave << endl;
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
  lista = inserir_lista(lista, 3);
  lista = inserir_lista(lista, 4);
  lista = inserir_lista(lista, 5);
  listar(lista);
  cout << "Lista antes de remover" << endl;
  remover(lista, 0);
  cout << "Lista depois de remover" << endl;
  listar(lista);
  inserit_por_posicao(lista, 2, 90);
  cout << "Lista depois de adicionar um item" << endl;
  listar(lista);

  // No *resultado = busca_por_chave(lista, 158);
  // cout << resultado->chave;
}