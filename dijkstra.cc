#include <iostream>
#include <vector>

using namespace std;

struct Aresta
{
  int peso;
  int destino;

  Aresta(int destino, int peso) : destino(destino), peso(peso) {}
};

class Grafo
{
public:
  int vertice;
  vector<vector<Aresta>> adjacentes;

  Grafo(int vertice);

  void adicionarAresta(int origem, int destino, int peso);
};

Grafo::Grafo(int numVertice)
{
  this->vertice = numVertice;
  adjacentes.resize(numVertice);
};

void Grafo::adicionarAresta(int origem, int destino, int peso)
{
  Aresta aresta(destino, peso);
  adjacentes[origem].push_back(aresta);
}

int main()
{
  int numVertices = 4;
  Grafo g(numVertices);

  char letras[4] = {'a', 'b', 'c', 'd'};

  g.adicionarAresta(0, 1, 1);
  g.adicionarAresta(0, 2, 3);
  g.adicionarAresta(1, 2, 2);
  g.adicionarAresta(2, 0, 4);
  g.adicionarAresta(2, 3, 1);
  g.adicionarAresta(3, 3, 5);

  for (int vertice = 0; vertice < numVertices; vertice++)
  {
    cout << "_____vertice_____: " << letras[vertice] << endl;

    for (int i = 0; i < g.adjacentes[vertice].size(); i++)
    {
      cout << endl;

      cout << "no: " << i << endl;

      int destino = g.adjacentes[vertice][i].destino;
      int peso = g.adjacentes[vertice][i].peso;

      cout << "destino: " << destino << endl;
      cout << "peso: " << peso << endl;
    }
    cout << endl;
  }
}