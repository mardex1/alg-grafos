/*
    Luiz Victor Soriano da Conceição 202210420 10A
    Mardem Arantes de Castro 202210086 10A
*/
#include<iostream>
#include<vector>
#include<utility>
using namespace std;

typedef vector<int> vi; // vetor de inteiros

// visitado[v]: igual a 1 se o vertice v foi visitado 
vi visitado;

bool ok = false;

// lista de adjacencia do grafo
vector<vi> LA;

vector<vi> LA_aux;

void DFS(int u, int& posicao) {
    visitado[u] = 1;

    for(auto it = LA[u].begin(); it != LA[u].end(); it++) {
        
        if(!visitado[*it]) {
            LA_aux[posicao].push_back(*it);
            DFS(*it, posicao);
        }
    }
    
}

int main()
{
    int n, m, p; // numero de vertices e numero de arestas
    cin >> n >> m >> p;

    visitado.assign(n, 0);
 
    for(int i = 0; i < n; i++)
    {
        vector<int> lista;
        LA.push_back(lista);
        LA_aux.push_back(lista);
    }
 
    int u, v; // extremos das arestas, e peso de cada aresta
    for(int i = 0; i < m; i++)
    {
        cin >> u >> v;
        u--;
        v--;

        LA[u].push_back(v);
        LA[v].push_back(u);
    }

    for(int i = 0; i < n; i++) {
        int posicao = i;
        DFS(i, posicao);
        visitado.assign(n, 0);
    }

    int a, b;
    for(int i = 0; i < p; i++) { 
        cin >> a >> b;
        a--;
        b--;

        int j = 0;
        while(j < LA_aux[a].size()) {
            if(LA_aux[a][j] == b) {
                ok = true;
                break;
            }
            j++;
        }

        if(ok) cout << "Lets que lets" << endl;
        else cout << "Deu ruim" << endl;

        ok = false;
        visitado.assign(n, 0); 
    } 

    return 0;
}