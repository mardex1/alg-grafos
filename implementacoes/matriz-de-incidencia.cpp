#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int** M = new int*[m+1]; // matriz de incidencia
      for(int i = 1; i <= m; i++)
          M[i] = new int[n+1];
  
      for(int i = 1; i <= m; i++)
          for(int v = 1; v <= n; v++)
              M[i][v] = 0;
     
      // leitura do grafo
      int u, v;
      for(int i = 1; i <= m; i++)
      {
        cin >> u >> v; // lendo as arestas do grafo
        M[i][u] = M[i][v] = 1;
      }

      for(int i = 1; i <= m; i++)
      {
          for(int v = 1; v <= n; v++)
              cout << M[i][v] << " ";
          cout << endl;
      }
}