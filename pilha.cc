#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

const int MAX = 3;

struct Pilha
{
  int itens[MAX];
  int topo;
};

void inicializa(Pilha *p)
{
  p->topo = -1;
};

int verificarPilhaVazia(Pilha *p)
{
  if (p->topo == -1)
  {
    return 1;
  }
  else
  {
    return 0;
  };
};

int verificarPilhaCheia(Pilha *p)
{
  if (p->topo == MAX)
  {
    return 1;
  }
  else
  {
    return 0;
  }
};

int pop(Pilha *pilha)
{
  if (verificarPilhaVazia(pilha))
  {
    cout << "Erro: Pilha está vazia" << endl;
    return -1;
  };
  int item = pilha->itens[pilha->topo];
  pilha->topo--;
  return item;
};

// int desempilhar(Pilha *pilha)
// {
//   if (pilha_esta_vazia(pilha))
//   {
//     cout << "Erro: Pilha está vazia" << endl;
//     return -1;
//   }
//   int item = pilha->itens[pilha->topo];
//   pilha->topo--;
//   return item;
// }

void push(Pilha *p, int item)
{
  if (verificarPilhaCheia(p) == MAX)
  {
    cout << "Pilha Cheia";
    return;
  };

  p->topo++;
  p->itens[p->topo] = item;
}

void listarPilha(Pilha *pilha)
{
  if (verificarPilhaVazia(pilha))
  {
    cout << "Erro: Pilha está vazia" << endl;
    return;
  }
  cout << "Conteúdo da pilha: ";
  for (int i = pilha->topo; i >= 0; i--)
  {
    cout << " " << pilha->itens[i];
  }
  cout << endl;
}

int main()
{
  Pilha pilha;
  inicializa(&pilha);
  push(&pilha, 10);
  push(&pilha, 20);
  pop(&pilha);
  push(&pilha, 30);
  push(&pilha, 45);
  push(&pilha, 21);
  pop(&pilha);
  pop(&pilha);

  listarPilha(&pilha);
}

// #include <stdio.h>
// #include <iostream>
// using namespace std;
// const int TAMANHO_MAXIMO = 10;
// // Definir a estrutura da pilha
// struct Pilha
// {
//   int itens[TAMANHO_MAXIMO];
//   int topo;
// };
// // Inicializar a pilha
// void inicializar_pilha(Pilha *pilha)
// {
//   pilha->topo = -1;
// }
// // Verificar se a pilha está vazia
// int pilha_esta_vazia(Pilha *pilha)
// {
//   if (pilha->topo == -1)
//     return 1;
//   else
//     return 0;
// }
// // Verificar se a pilha está cheia
// int pilha_esta_cheia(Pilha *pilha)
// {
//   if (pilha->topo == TAMANHO_MAXIMO)
//     return 1;
//   else
//     return 0;
// }
// // Empilha um elemento na pilha
// void empilhar(Pilha *pilha, int item)
// {
//   if (pilha_esta_cheia(pilha))
//   {
//     cout << "Erro: Pilha está cheia" << endl;
//     return;
//   }
//   pilha->topo++;
//   pilha->itens[pilha->topo] = item;
// }
// // Desempilhar um elemento da pilha
// int desempilhar(Pilha *pilha)
// {
//   if (pilha_esta_vazia(pilha))
//   {
//     cout << "Erro: Pilha está vazia" << endl;
//     return -1;
//   }
//   int item = pilha->itens[pilha->topo];
//   pilha->topo--;
//   return item;
// }
// // Exibir os conteúdos da pilha
// void mostrar_pilha(Pilha *pilha)
// {
//   if (pilha_esta_vazia(pilha))
//   {
//     cout << "Erro: Pilha está vazia" << endl;
//     return;
//   }
//   cout << "Conteúdo da pilha: ";
//   for (int i = pilha->topo; i >= 0; i--)
//   {
//     cout << " " << pilha->itens[i];
//   }
//   cout << endl;
// }
// // Testar a implementação da pilha
// int main()
// {
//   Pilha pilha;
//   inicializar_pilha(&pilha);
//   empilhar(&pilha, 1);
//   empilhar(&pilha, 2);
//   empilhar(&pilha, 3);
//   mostrar_pilha(&pilha);
//   cout << "Desempilhando " << desempilhar(&pilha) << "da pilha" << endl;
//   mostrar_pilha(&pilha);
//   return 0;
// }
