#include <iostream>
#include <stdlib.h>
#include <chrono>
using namespace std;

void listar_vetor(int vetor[], int quantidade)
{
  for (int i = 0; i < quantidade; i++)
  {
    cout << "Quantidade: " << vetor[i] << endl;
  };
};

int busca_binaria_recursiva(int vetor[], int inicio, int final, int chave)
{
  int meio = (inicio + final) / 2;

  if (meio == 0)
  {
    return -1;
  };

  if (meio == chave)
  {
    return meio;
  };

  if (meio > chave)
  {
    return busca_binaria_recursiva(vetor, meio + 1, final, chave);
  }
  if (meio < chave)
  {
    return busca_binaria_recursiva(vetor, inicio, meio - 1, chave);
  }
}

int busca_sequencial(int vetor[], int chave)
{
  for (int i = 0; i <= 100000; i++)
  {
    if (vetor[i] == chave)
    {
      return i;
    }
  }
  return -1;
}

int main()
{
  int MAX_SIZE = 100000;
  int vetor[MAX_SIZE] = {};
  for (int i = 0; i < MAX_SIZE; i++)
  {
    vetor[i] = i;
  }

  int chave = 50000;
  // listar_vetor(vetor, 100000);
  cout << "Busca Sequencial" << endl;
  int resultado = busca_sequencial(vetor, chave);
  auto tempo_busca_sequêncial = std::chrono::high_resolution_clock::now();
  cout << "Resultado: " << resultado << endl;

  cout << "Busca Binaria" << endl;
  int inicio = 0;
  int final = MAX_SIZE;
  int resultado_busca_binaria = busca_binaria_recursiva(vetor, inicio, final, chave);
  cout << "Resultado: " << resultado_busca_binaria << endl;
}