#include<iostream>
#include<vector>
using namespace std;

typedef vector<int> vi;

// Implemente sua resposta aqui
int centro(vi* LA, int n)
{
  int centro;
  int tam = n;
  int* grau = new int[n];
  for(int i = 0; i < n; i++) {
    grau[i] = LA[i].size();
  }

  while(n > 2) {
    for(int i = 0; i < tam; i++) {
        if(grau[i] == 1) {
            grau[LA[i][0]]--;
            n--;
        }
    }
  }
  for(int i = 0; i < tam; i++) {
    cout << grau[i] << " ";
  }cout << endl;
  int* folhas = new int[2];
  int j = 0;
  for(int i = 0; i < tam; i++) {
    if(grau[i] == 1){
        folhas[j] = i;
        j++;
    }
  }
  
  centro = folhas[0];
  // TO DO

  return centro;
}

int main()
{
  int n, m;
  cin >> n >> m;

  while(!cin.eof())
  {
    // considerando que os índices dos vértices começam de 0 e vão até n-1
    vi* LA = new vector<int>[n];

    // leitura do grafo
    int u, v;
    for(int i = 0; i < m; i++)
    {
      cin >> u >> v; // lendo as arestas do grafo

      // grafo direcionado
      LA[u].push_back(v); //u -> v
      LA[v].push_back(u); //v -> u
    }
    
    cout << centro(LA, n) << endl;
    
  }

  return 0;
}