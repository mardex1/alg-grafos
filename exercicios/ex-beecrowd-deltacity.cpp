// Mardem Arantes de Castro 202210086, Luiz Victor Soriano da Conceição 202210420
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <functional>
using namespace std;

/*
 * Variaveis globais
 */
int n, m;

// lista de adjacencia
vector<pair<int, int>> *LA;
vector<pair<int, int>> *LAT;

vector<int> pai;

vector<int> aresta_pai;

int maior = -1;

void caminho(int u)
{
    if (pai[u] == -1)
    {
        if (maior < aresta_pai[u])
            maior = aresta_pai[u];
            cout << u << endl;
        return;
    }

    caminho(pai[u]);
    if (maior < aresta_pai[u])
        maior = aresta_pai[u];
        cout << u << endl;
}

// distancia da origem "org" a cada vertice do grafo
vector<int> d;

vector<int> visitado;

void dijkstra(int org, int dest, vector<pair<int, int>> *la)
{
    d.assign(n, __INT_MAX__);

    // a distance da origem "org" eh sempre zero
    d[org] = 0;
    pai.assign(n, -1);
    aresta_pai.assign(n, 0);

    // heap que auxilia na obtencao do vertice com maior prioridade, a cada iteracao
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;

    // primeiro par inserido na heap: "org" com custo zero
    heap.push(make_pair(0, org));

    vector<bool> visitado;
    visitado.assign(n, false);

    // o algoritmo para quando a heap estiver vazia
    while (!heap.empty())
    {
        pair<int, int> vertice = heap.top();
        heap.pop();

        int distancia = vertice.first;
        int u = vertice.second;

        if (visitado[u]) // "u" jah foi explorado
            continue;

        visitado[u] = true;

        int custo;
        for (int j = 0; j < (int)la[u].size(); j++)
        {

            pair<int, int> vizinho = la[u][j];
            int v = vizinho.first;
            int peso = vizinho.second;

            // tentativa de melhorar a estimativa de menor caminho da origem ao vertice v
            custo = d[u] + peso;
            if (custo < d[v])
            {
                d[v] = custo;
                heap.push(make_pair(d[v], v));
                pai[v] = u;
                aresta_pai[v] = peso;
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;
    for (int z = 0; z < t; z++)
    {
        int s, t, limiar;
        cin >> n >> m >> s >> t >> limiar;

        LA = new vector<pair<int, int>>[n];
        LAT = new vector<pair<int, int>>[n];
        int u, v;
        int p;
        for (int i = 0; i < m; i++)
        {
            cin >> u >> v >> p;
            u--;
            v--;
            LA[u].push_back(make_pair(v, p));
            LAT[v].push_back(make_pair(u, p));
        }
        maior = -1;
        int maior_normal = -1;
        dijkstra(s - 1, t - 1, LA);
        caminho(t - 1);
        maior_normal = maior;


        maior = -1;
        int maior_transposto = -1;
        dijkstra(t - 1, s - 1, LAT);
        caminho(s - 1);
        maior_transposto = maior;
        if (d[s - 1] > limiar)
        {
            cout << -1 << endl;
        }
        else
        {
            if (maior_normal > maior_transposto)
                cout << maior_normal << endl;
            else
                cout << maior_transposto << endl;
        }
    }
    return 0;
}