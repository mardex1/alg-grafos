/*#include <iostream>
#include <vector>
#include <map>

using namespace std;

void DFS(string u, map<string, string> LA, map<string, int> &d, map<string, string> &pai, int &casamentos)
{
    d[u]++;
    string v = LA[u];
    if (d[v] == 0)
    {
        pai[v] = u;
        DFS(v, LA, d, pai, casamentos);
    }
    if (pai[v] == u && pai[u] == v)
    {
        casamentos++;
        d[v]++;
    }
    else
    {   
        while(pai[u] != "noname"){
            if(pai[u] == v){
                casamentos++;
                break;
            }
            else{
                u = pai[u];
            }
        }
    }
}

int main()
{
    map<string, string> LA;
    map<string, string> pai;
    map<string, int> d;

    string pessoa1, pessoa2;
    int casamentos = 0;
    while (cin >> pessoa1 >> pessoa2)
    {
        LA.insert(make_pair(pessoa1, pessoa2));
        pai.insert(make_pair(pessoa1, "noname"));
        d.insert(make_pair(pessoa1, 0));

    }
    for (auto it = LA.begin(); it != LA.end(); it++)
    {
        if (d[it->first] == 0)
        {
            DFS(it->first, LA, d, pai, casamentos);
        }
    }
    cout << casamentos;
    return 0;
}*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

typedef vector<int> vi; 
#define NAO_VISITADO -1

unordered_map<string, int> mapa;
vector<int>* LA;
vector<int>* TP;
int visitado[100000];
// tempo de descoberta atual da DFS 
int tempo = 0;

// pilha: pilha de vertices descobertos pela DFS
vi pilha;

// low[v]: tempo de descoberta do ancestral do vertice v descoberto "mais cedo" na DFS 
vi low;

// d[v]: tempo de descoberta pre-ordem do vertice v
vi d;

int conta = -1;

int casamentos = 0;

bool teste = false;

void tarjanCFC(int u)
{
    low[u]= d[u] = tempo++;
 
    // insercao na pilha de vertices descobertos
    pilha.push_back(u);

    visitado[u] = 1;
    for(int j = 0; j < LA[u].size(); j++)
    {
        int v = LA[u][j];

        if(d[v] == NAO_VISITADO)
          tarjanCFC(v);

        if(visitado[v])
          low[u] = min(low[u], low[v]);
    }
 
    if(low[u] == d[u]) {
        int cont = 0;
        while(true) {
            int vtx = pilha.back();
            pilha.pop_back();
            cont++;
            // atribuimos para zero para que o low do vizinho de vtx nao seja mais atualizado
            visitado[vtx] = 0; 


            if(u == vtx && cont > 1) {
                casamentos++;
                break;
            }

        }
    }
}

int main() {
    string A, B;
    LA = new vector<int>[10000];
    TP = new vector<int>[10000];
    while(cin >> A >> B) {
        if(!mapa.count(A)) {
            mapa[A] = conta++;
        }
        if(!mapa.count(B)) {
            mapa[B] = conta++;
        }
        int cod1 = mapa[A];
        int cod2 = mapa[B];
        LA[cod1].push_back(cod2);
        TP[cod2].push_back(cod1);
    }

    int casamentos = 0;

    for(int i = 0; i < conta; i++) {
        if(visitado[i] == 0) {
            tarjanCFC(i);
        }
    }

    cout << casamentos << endl;

    return 0;
}