#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

#define NAO_VISITADO 0

// Raiz da DFS
int raiz;

// Armazena a informacao se um vertice eh de articulacao
bool* articulacoes;

/*
 * Parametros:
 *  u -> vertice a ser explorado
 *  lista_adj -> lista de adjacencia, que modela o grafo
 *  low -> vetor com os menores tempos de descoberta de arestas que abracam um vertice
 *  d -> vetor dos tempos de descoberta pre-ordem de todos os vertices
 *  pai -> vetor com os pais de todos os vertices
 *  cont_dfs -> contador do tempo de descoberta em profundidade dos vertices
 *  filhos_raiz -> conta quantos filhos a raiz possui na DFS
 */
void tarjan(int u, vector<int>* lista_adj, int* low, int* d, int* pai, int& cont_dfs, int& filhos_raiz)
{
    low[u] = d[u] = cont_dfs++;
 
    for(auto it = lista_adj[u].begin(); it != lista_adj[u].end(); it++)
    {
        int v = *it;
        if(d[v] == NAO_VISITADO)
        {
            pai[v] = u;
     
            if(u == raiz)
            {
                filhos_raiz++;
            }
        
            tarjan(v, lista_adj, low, d, pai, cont_dfs, filhos_raiz);
        
            if(low[v] >= d[u])
            {
                articulacoes[u] = true;
            }
        
            if(low[v] > d[u])
            {
                cout << "ponte: (" << u << ", " << v << ")" << endl;
            }
     
            low[u] = min(low[u], low[v]);
        }
     
        // Nao eh um ciclo trivial
        else if(v != pai[u])
        {
            low[u] = min(low[u], d[v]);
        }
    }
}

int main()
{  
  int n, m;
  cin >> n >> m;

  while(!cin.eof())
  {
    // alocando as estruturas auxiliares
    int* low = new int[n+1];
    int* d = new int[n+1];
    int* pai = new int[n+1];
    int cont_dfs = 1;
    int filhos_raiz = 0;
   
    articulacoes = new bool[n+1];
   
    // iniciando as estruturas auxiliares
    for(int i = 1; i <= n; i++)
    {
        low[i] = NAO_VISITADO;
        d[i] = NAO_VISITADO;
        pai[i] = -1;
        articulacoes[i] = false;
    }
   
    vector<int>* lista_adj = new vector<int>[n+1];

    // leitura do grafo
    int u, v;
    for(int i = 0; i < m; i++)
    {
      cin >> u >> v; // lendo as arestas do grafo

      // evitando a leitura de vertices repetidos nas listas
      if(find(lista_adj[u].begin(), lista_adj[u].end(), v) != lista_adj[u].end())
      {
        continue;
      }

      // grafo nao-orientado
      lista_adj[u].push_back(v); //u -> v
      lista_adj[v].push_back(u); //v -> u
    }

    for(int i = 1; i <= n; i++)
    {
        if(d[i] == NAO_VISITADO)
        {
            raiz = i;
            filhos_raiz = 0;
            tarjan(i,  lista_adj, low, d, pai, cont_dfs, filhos_raiz);
            // Caso especial para vertice de articulacao: a raiz da DFS com mais de 1 filho
            articulacoes[i] = (filhos_raiz > 1);
        }
    }
   
    for(int i = 1; i <= n; i++)
    {
        if(articulacoes[i])
        {
            cout << "vertice de articulacao: " << i << endl;
        }
    }
   
    delete[] pai;
    delete[] d;
    delete[] low;
    delete[] articulacoes;
   
    cin >> n >> m;
  }

  cout << "*****" << endl;

  return 0;
}