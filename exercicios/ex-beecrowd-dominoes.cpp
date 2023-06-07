#include <iostream>
#include <vector>
using namespace std;

void DFS(int u, vector<int>* LA, int& dist, int& maior_dist, bool* visitado, int* pai) {
    visitado[u] = 1;
    for(auto it = LA[u].begin(); it != LA[u].end(); it++) {
        if(u == *it) {
            dist++;
        }else if(u != *it && visitado[*it] == 0){
            pai[*it] = u;
            dist++;
            DFS(*it, LA, dist, maior_dist, visitado, pai);
        }else if(pai[*it] != u) {
            dist++;
        } 
      
    }
    if(dist > maior_dist) {
        maior_dist = dist;
    }
}

int main() {
    while(!cin.eof()) {
        int m;
        cin >> m;
        
        vector<int>* LA = new vector<int>[10];
        bool* visitado = new bool[10];
        int* pai = new int[10];
        
        int a, b;
        for(int i = 0; i < m; i++) {
            cin >> a >> b;

            LA[a].push_back(b);
        }
    
        int maior_dist = 0;
        int dist = 0;

        for(int i = 0; i < 10; i++) {
            for(int j = 0; j < 10; j++) {
                visitado[j] = 0;
                pai[j] = 0;
            }
            DFS(i, LA, dist, maior_dist, visitado, pai);
            dist = 0;
        }

        cout << maior_dist << endl;

    }
}