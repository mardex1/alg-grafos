#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int** MA = new int*[n];
    for(int i = 0; i < n; i++) {
        MA[i] = new int[n];
        for(int j = 0; j < n; j++) {
            MA[i][j] = 0;
        }
    }

    int u, v;
    for(int i = 0; i < m; i++) {
        cin >> u >> v;

        MA[u][v] = 1;//direcionado
        //MA[v][u] = 1;//não direcionado
    }

    return 0;
}