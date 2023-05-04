#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int main() {
    int n, m;

    cin >> n >> m;

    vector<pair<int,int>> lista_arestas;

    //leitura do grafo
    int u, v;
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        pair<int,int> uv(u,v);
        lista_arestas.push_back(uv);
    }

    return 0;
}
