#include <iostream>
#include <vector>   
#include <queue>
using namespace std;

void BFS(int u, vector<int>* LA, int* dist, bool* visitado) {
    int s = u;
    queue<int> fila;
    fila.push(s);
    
    while(!fila.empty()) {
        
        int u = fila.front();
        fila.pop();
        visitado[u] = 1;

        for(auto it = LA[u].begin(); it != LA[u].end(); it++) {
            if(visitado[*it] == 0) {
                visitado[*it] = 1;
                dist[*it] = dist[u] + 1;
                fila.push(*it);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m; 
    while(n != 0 and m != 0) {
        int tam = (n*m); 
        
        vector<int>* LA = new vector<int>[tam];
        char** matriz = new char*[n];
        for(int i = 0; i < n; i++) {
            matriz[i] = new char[n];
            for(int j = 0;j < n; j++) {
                cin >> matriz[i][j];
            }
        }
        int cont = 0;
        int vertice_teste;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matriz[i][j] == '.') {    
                    if(i != 0 && matriz[i-1][j] == '.') {
                        LA[cont].push_back(cont-m);
                    }
                    if(j != 0 && matriz[i][j-1] == '.') {
                        LA[cont].push_back(cont-1);
                    }
                    if(j != m-1 && matriz[i][j+1] == '.') {
                        LA[cont].push_back(cont+1);
                    }
                    if(i != m-1 && matriz[i+1][j] == '.') {
                        LA[cont].push_back(cont+m);
                    }
                    vertice_teste = cont;
                }
                cont++;
            }
        }

        int* dist = new int[tam];
        bool* visitado = new bool[tam];

        for(int i = 0; i < tam; i++) {
            dist[i] = 0;
            visitado[i] = 0;
        }

        BFS(vertice_teste, LA, dist, visitado);

        int maior = 0;
        int posicao;
        for(int k = 0; k < tam; k++) {
            if(dist[k] > maior) {
                maior = dist[k];
                posicao = k;
            }
        }
        for(int i = 0; i < tam; i++) {
            visitado[i] = 0;
            dist[i] = 0;
        }

        BFS(posicao, LA, dist, visitado);

        for(int k = 0; k < tam; k++) {
            if(dist[k] > maior) {
                maior = dist[k];
                posicao = k;
            }
        }

        cout << maior << endl;
        cin >> n >> m;
    }


    return 0;
}