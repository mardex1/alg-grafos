#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

void DFS(int u, vector<int>* lista_adj, bool* visitado) {
    visitado[u] = true;

    for(auto it = lista_adj[u].begin(); it != lista_adj[u].end(); it++) {
        if(visitado[*it] == false) {
            DFS(*it, lista_adj, visitado);
        }
    }
}

int main()
{
    int t, n, m;
    cin >> t;

    for(int k = 1; k <= t; k++) {
        cin >> n >> m;

        // alocando as estruturas auxiliares
        bool* visitado = new bool[n+1];
    
        // iniciando as estruturas auxiliares
        for(int i = 1; i <= n; i++)
        {
            visitado[i] = false;
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

        int componentes = 0;
        for(int i = 1; i <= n; i++)
        {
            if(visitado[i] == false)
            {
                DFS(i, lista_adj, visitado);
                componentes++;
            }
        }
    
        if(componentes-1 == 0) 
            cout << "Caso #" << k <<  ": a promessa foi cumprida" << endl;
        else
            cout << "Caso #" << k << ": ainda falta(m) " << componentes-1 << " estrada(s)" << endl;
        delete[] visitado;
   
    }
    
  return 0;
}