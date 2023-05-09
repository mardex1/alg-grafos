#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

//Cores dos vértices
#define BRANCO 0
#define CINZA 1
#define PRETO 2

int main() {
    int n, m;
    cin >> n >> m;

    int* dist = new int[n];
    int* pai = new int[n];
    int* cor = new int[n];

    for(int i = 0; i < n; i++) {
        dist[i] = 0;
        pai[i] = -1;
        cor[i] = BRANCO;
    }

    vector<int>* lista_adj = new vector<int>[n];

    int u, v;
    for(int i = 0; i < m; i++) {
        cin >> u >> v;

        lista_adj[u].push_back(v);
        lista_adj[v].push_back(u);
    }

    int s = 0;// vertice origem
    queue<int> fila;
    fila.push(s);
    cor[s] = CINZA;

    while(!fila.empty()) {

        int u = fila.front();
        fila.pop();
        cor[u] = PRETO;

        for(auto it = lista_adj[u].begin(); it != lista_adj[u].end(); it++) {
            // Se o vértice não foi descoberto
            if(cor[*it] == BRANCO) {
                cor[*it] = CINZA;
                pai[*it] = u;
                dist[*it] = dist[u] + 1;
                fila.push(*it);
            }
        }
    }
    cout << "Distancias" << endl;
    for(int k = 0; k < n; k++)
    {
        cout << "dist[" << k << "]: " << dist[k] << endl;
    }
   
    cout << "Pai" << endl;
    for(int k = 0; k < n; k++)
    {
        cout << "pai[" << k << "]: " << pai[k] << endl;
    }
    cout << "*** *** ***" << endl;
   
    delete[] pai;
    delete[] cor;
    delete[] dist;

    return 0;
    
}