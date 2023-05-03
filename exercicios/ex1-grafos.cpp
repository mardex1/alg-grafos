//A partir de um vértice aleatório em um grafo, qual é o seu grau de entrada e grau de saída?
#include<iostream>
#include<vector>
#include<utility>
using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;

ii retornaGrau(vi* LA, int n, int u)
{
    // first: grau de entrada; second: grau de saida
    ii grau;
    int grau_entrada = 0;
    int grau_saida = 0;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < LA[i].size(); j++) {
        if(i != u) {
            if(LA[i][j] == u) {
            grau_entrada++;
            }
        }else if(i == u) {
            grau_saida++;
        }
        }
    }
    grau.first = grau_entrada;
    grau.second = grau_saida;

    return grau;
}

int main()
{
    int n, m;
    cin >> n >> m;

    // considerando que os índices dos vértices começam de 0 e vão até n-1
    vi* LA = new vi[n];

    // leitura do grafo
    int u, v;
    for(int i = 0; i < m; i++) {
    // lendo as arestas do grafo
    cin >> u >> v; 
    // grafo direcionado
    LA[u].push_back(v); //u -> v
    }

    // escolhe aleatoriamente um vertice de 0 a n-1
    int vertice = rand() % n;
    ii grau = retornaGrau(LA, n, vertice);
    cout << vertice << " " << grau.first << " " << grau.second << endl;

    return 0;
}