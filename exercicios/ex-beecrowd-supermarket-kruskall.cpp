#include <utility>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;

class UFDS {
    public:
        UFDS(int n) {
            rank.assign(n , 0);
            pai.assign(n, 0);
            for(int i = 0; i < n; i++) {
                pai[i] = i;
            }
        }
        int busca(int i) {
            if(pai[i] == i) 
                return i;
            
            pai[i] = busca(pai[i]);
            return pai[i];
        }
        bool mesmo_conjunto(int i, int j) {
            return busca(i) == busca(j);
        }
        void uniao(int i, int j) {
            if(!mesmo_conjunto(i, j)) {
                int c1 = busca(i);
                int c2 = busca(j);

                if(rank[c1] > rank[c2]) 
                    pai[c2] = c1;
                else {
                    pai[c1] = c2;
                    if(rank[c1] == rank[c2]) {
                        rank[c2]++;
                    }
                }
            }
        }
        friend ostream &operator<<(ostream& saida, const UFDS& conjunto)
        { 
          for(int i = 0; i < conjunto.pai.size(); i++)
            saida << i << ": pai(" << conjunto.pai[i] << "), rank(" << conjunto.rank[i] << ")";
          return saida;
        }

    private:
        vi pai;
        vi rank;
};

void kruskall(vector<pair<int, ii>> &arestas, vector<vector<pair<int, int>>> &LA, int n, int m) {
    sort(arestas.begin(), arestas.end(), greater<pair<int, ii>>());

    UFDS ufds(n);

    int u, v;
    pair<int, ii> e;

    int numero_arestas = 0;
    for(int i = 0; i < m; i++) {
        e = arestas[i];
        u = e.second.first;
        v = e.second.second;
        if(!ufds.mesmo_conjunto(u, v)) {
            LA[u].push_back(pair<int,int>(v, e.first));
            LA[v].push_back(pair<int,int>(u, e.first));
            numero_arestas++;
            if(numero_arestas == n-1) break;

            ufds.uniao(u, v);
        }
    }
}

void dfs(int u, int b, vector<vector<pair<int, int>>> &LA, vector<int>& pai, vector<int> &visitado) {
    visitado[u] = 1;

    for(auto it = LA[u].begin(); it != LA[u].end(); it++) {
        int v = it->first;
        if(!visitado[v]) {
            pai[v] = u;
            dfs(v, b, LA, pai, visitado);
        }
    }
}

void dfs_caminho(int u, vector<int> &pai, int& menor, vector<vector<pair<int, int>>> &LA, bool& ok) {
    if(pai[u] == -1) ok = false;

    if(ok) {
        for(int j = 0; j < LA[u].size(); j++) {
            if(LA[u][j].first == pai[u] && LA[u][j].second < menor) {
                menor = LA[u][j].second;
            }
        }
        dfs_caminho(pai[u], pai, menor, LA, ok);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    while(n != 0 or m != 0) {
        vector<vector<pair<int, int>>> LA(n);
        vector<pair<int, ii>> arestas;
        vector<int> pai(n);
        vector<int> visitado(n);
        bool ok = true;

        int u, v, w;
        for(int i = 0; i < m; i++) {
            cin >> u >> v >> w;
            u--;
            v--;
            arestas.push_back(make_pair(w, ii(u, v)));
        }
        
        kruskall(arestas, LA, n, m);

        int a, b, c;
        cin >> a >> b >> c;
        if(a > 0 and b <= n) {
            a--;
            b--;
        
            pai.assign(n, -1);
            visitado.assign(n, 0);

            dfs(a, b, LA, pai, visitado);

            visitado.assign(n, 0);

            int menor = __INT_MAX__;

            dfs_caminho(b, pai, menor, LA, ok);

            if(menor-1 > 0) 
                cout << ceil(c/float(menor-1)) << endl;
            else    
                cout << 0 << endl;
        }

            cin >> n >> m;
    }

    return 0;
}

