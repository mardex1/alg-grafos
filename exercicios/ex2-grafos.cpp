#include<iostream>
#include<vector>
using namespace std;

typedef vector<int> vi;

// Implemente sua resposta aqui
vi* retornaTransposto(int** MA, int n)
{
    vi* LA = new vi[n];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(MA[i][j] == 1) {
                LA[j].push_back(i);
            }
        }
    }
    // TO DO

    return LA;
}

int main()
{
    int n, m;

        // considerando que os índices dos vértices começam de 0 e vão até n-1
        int** MA = new int*[n];
        for(int i = 0; i < n; i++)
        {
        MA[i] = new int[n];
        for(int j = 0; j < n; j++)
            MA[i][j] = 0;
        }

        // leitura do grafo
        int u, v;
        for(int i = 0; i < m; i++)
        {
        cin >> u >> v; // lendo as arestas do grafo

        // grafo direcionado
        MA[u][v] = 1; //u -> v
        }

        
        vi* LA = retornaTransposto(MA, n);
        for(int u = 0; u < n; u++)
        {
        cout << u << ": ";
        for(int j = 0; j < LA[u].size(); j++)
        {
            int v = LA[u][j];
            cout << v << " ";
        }
        cout << endl;
        }

        cout << endl;

    return 0;
}