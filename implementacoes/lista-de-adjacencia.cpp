#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{  
  int n, m, k;
  cin >> n >> m >> k;

  while(!cin.eof())
  {
    // considerando que os índices dos vértices começam de 1 e vão até n
    vector<int>* lista_adj = new vector<int>[n+1];
    int* grau = new int[n+1];

    for(int i = 1; i <= n; i++)
      grau[i] = 0; //grau do nó i
    
    // leitura do grafo
    int u, v;
    for(int i = 0; i < m; i++)
    {
      cin >> u >> v; // lendo as arestas do grafo

      // evitando a leitura de vertices repetidos nas listas
      if(find(lista_adj[u].begin(), lista_adj[u].end(), v) != lista_adj[u].end())
        continue;
    
      // grafo nao-orientado
      lista_adj[u].push_back(v); //u -> v
      lista_adj[v].push_back(u); //v -> u
      
      grau[u]++;
      grau[v]++;
    }
  }
}