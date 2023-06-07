#include <utility>
#include <vector>
#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

typedef pair<int, int> ii; // pares de inteiros
typedef vector<int> vi;    // vetor de inteiros
typedef vector<ii> vii;    // vetor de pares de inteiros

// armazena a informacao se o vertice foi explorado ou nao
vi explorado;

// heap que armazena o vertices e suas prioridades a cada iteracao
priority_queue<ii> Q;

// numero de vertices
int n;

// numero de arestas
int m;

//Condicao para teste de insercao/remocao da lista de caminhos
bool ok = true;

void dfs_pai(int u, int b, int* pai, vii* LANova) {
    explorado[u] = 1;
    
    for(auto it = LANova[u].begin(); it != LANova[u].end(); ++it) {
        if(explorado[it->first] == 0) {
            pai[it->first] = u;
            dfs_pai(it->first, b, pai, LANova);
        }
    }
}

void dfs_caminho(int u, int* pai, int& menor, vii* LANova) {
    if(pai[u] == -1) ok = false;

    if(ok) {
        for(int j = 0; j < LANova[u].size(); j++) {
            if(LANova[u][j].first == pai[u] && LANova[u][j].second < menor) {
                menor = LANova[u][j].second;
            }
        }
        dfs_caminho(pai[u], pai, menor, LANova);
    } 

    
}

// funcao que atualiza a fila de prioridades
void atualizaFila(int u, vii* LA)
{
    explorado[u] = 1;
    for (int j = 0; j < LA[u].size(); j++)
    {
        ii v = LA[u][j];
        if (!explorado[v.first])
        {
            /* valor: peso; chave: id do vertice */
            Q.push(ii(v.second, v.first));
        }
    }
}

void prim(int a, vii* LA, vii* LANova)
{
    explorado.assign(n, 0);
    atualizaFila(a, LA);


    while (!Q.empty())
    {
        ii u = Q.top(); // O(1)
        Q.pop();        // O(logm)

        int w = u.first;
        int v = u.second;

        if (!explorado[v])
        {
            for (int i = 0; i < LA[i].size(); i++)
            {
                if (LA[v][i].second == w)
                {
                    int u = LA[v][i].first;
                    LANova[v].push_back(ii(u,w));
                    LANova[u].push_back(ii(v,w));
                }
            }
            atualizaFila(v, LA); // O(logm)
        }
    }
}

int main()
{
    
    std::cin >> n >> m;
    while(n != 0 and m != 0) {
        vector<pair<int,int>>* LA = new vector<pair<int,int>>[n];
        vii* LANova = new vii[n];

        int u, v, w; // extremos das arestas, e peso de cada aresta
        for (int i = 0; i < m; i++)
        {
            std::cin >> u >> v >> w;
            u--;
            v--;
            LA[u].push_back(ii(v, w));
            LA[v].push_back(ii(u, w));
        }

        int a, b, c;
        std::cin >> a >> b >> c;
        if(a > 0 and b <= n) {
            a--;
            b--;
            
            prim(a, LA, LANova);

            explorado.assign(n, 0);
            int* pai = new int[n];
            pai[a] = -1;

            dfs_pai(a, b, pai, LANova);

            int menor = __INT_MAX__;

            dfs_caminho(b, pai, menor, LANova); 
    
            std::cout << ceil(c/float(menor - 1)) << endl;
            delete[] pai;
        }
            std::cin >> n >> m;
            ok = true;
    }
    
    return 0;
}