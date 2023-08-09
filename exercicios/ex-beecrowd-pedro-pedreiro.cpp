#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int>* LA;

vector<int> visitado;

vector<int> pai;

stack<int> pilha;

bool ok = true;

void DFS(int u) {
    visitado[u] = 1;

    for(auto it = LA[u].begin(); it != LA[u].end(); it++) {
        if(visitado[*it] == 0) {
            pai[*it] = u;
            DFS(*it);
        }
        if(pai[*it] != u and visitado[*it] == 1) {
            ok = false;
        }
    }
    pilha.push(u);
    visitado[u] = 2;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    while(n != 0 and m != 0) {
        LA = new vector<int>[n];
        int u, v;
        for(int i = 0; i < m; i++) {
            cin >> u >> v;

            LA[u].push_back(v);
        }
    
        visitado.assign(n, 0);
        pai.assign(n, -1);

        for(int i = 0; i < n; i++){
            if(visitado[i] == 0) {
                DFS(i);
            }
        }        

        if(ok == false) {
            cout << -1 << endl;
            while(!pilha.empty()) {
                int u = pilha.top();
                pilha.pop();
            }
        }else {
            while(!pilha.empty()) {
                int u = pilha.top();
                pilha.pop();
                cout << u << " ";
            }
            cout << endl;
        }
        ok = true;

        cin >> n >> m;
    }
    return 0;
}