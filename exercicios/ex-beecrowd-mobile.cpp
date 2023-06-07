#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

void organiza(vector<int>* lista_adj, int u, int& filhos, int* vet_filhos) {
   
    for(auto it = lista_adj[u].begin(); it != lista_adj[u].end(); it++) {
        filhos++;
        organiza(lista_adj, *it, filhos, vet_filhos);
    }
}

bool balanceamento(vector<int>* lista_adj, int n, int* vet_filhos) {
    int i = 0;
    bool teste = true;
    while((i < n+1) and (teste == true)) {
        if(lista_adj[i].size() > 1) {
            for(int j = 0; j < lista_adj[i].size()-1;j++) {
                if(vet_filhos[lista_adj[i][j]] != vet_filhos[lista_adj[i][j+1]]){
                    teste = false;
                }
            }
        }
        i++;
    }
    return teste;
}

int main() {
    int n;
    cin >> n;

    vector<int>* lista_adj = new vector<int>[n+1];
    int* vet_filhos = new int[n+1];

    int u, v;
    for(int i = 0; i < n; i++) {
        cin >> u >> v;
    
        lista_adj[v].push_back(u);
    }
    
    int filhos = 0;
    for(int i = 0; i < n+1; i++) {
        organiza(lista_adj, i, filhos, vet_filhos);
        vet_filhos[i] = filhos;
        filhos = 0;
    }

    bool resultado = balanceamento(lista_adj, n, vet_filhos);

    if(resultado) {
        cout << "bem" << endl;
    }else {
        cout << "mal" << endl;
    }

    delete[] vet_filhos;

    return 0;
}