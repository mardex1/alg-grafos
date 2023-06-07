#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

void busca_profundidade(vi* lista_adj, int u, int* visitado, int& x)
{
    visitado[u] = 1;
    x++;

    for (auto it = lista_adj[u].begin(); it != lista_adj[u].end(); it++)
    {
        
        if (visitado[*it] == 0)
        {
            busca_profundidade(lista_adj,*it, visitado, x);
        }
    }
}

int main()
{
    int n;
    cin >> n;

    vi* lista_adj = new vi[n + 1];
    vi* transposto = new vi[n + 1];
    int* visitado = new int[n + 1];

    int u, v;
    for (int i = 0; i < n; i++)
    {
        cin >> u >> v;

        lista_adj[u].push_back(v);
        transposto[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        visitado[i] = 0;
    }

    int x = 0;

    busca_profundidade(lista_adj, 1, visitado, x);

    for (int i = 1; i <= n; i++) {
        visitado[i] = 0;
    }
    
    busca_profundidade(transposto, 1, visitado, x);


    if(x == 2*n) {
        cout << "S" << endl;
    }else{
        cout << "N" << endl;
    }

    delete[] visitado;

    return 0;
}