    /*
        Luiz Victor Soriano da Conceição 202210420 10A
        Mardem Arantes de Castro 202210086 10A
    */
    #include<iostream>
    #include<vector>
    #include<queue>
    #include<utility>
    #include<functional>
    using namespace std;

    /*
    * Variaveis globais
    */

    // lista de adjacencia
    vector<pair<int, int>>* LA;

    vector<pair<int, int>>* LA_par;

    // numero de vertices do grafo
    int n;

    // numeor de arestas do grafo
    int m;

    // distancia da origem "org" a cada vertice do grafo
    vector<int> d;

    vector<int> visitado;

    void montador(int u) {
        for(auto it = LA[u].begin(); it != LA[u].end(); it++) {
            int v1 = it->first;
            int w1 = it->second;
            for(int j = 0; j < LA[v1].size(); j++) {
                int v2 = LA[v1][j].first;
                int w2 = LA[v1][j].second;
                if(v2 == u) continue;
                LA_par[u].push_back(make_pair(v2, w1+w2));
            }
        }
    }

    int dijkstra(int org)
    {
        d.assign(n, __INT_MAX__);
        
        // a distance da origem "org" eh sempre zero
        d[org] = 0;
        
        // heap que auxilia na obtencao do vertice com maior prioridade, a cada iteracao
        priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > heap;

        // primeiro par inserido na heap: "org" com custo zero
        heap.push(make_pair(0, org));
    
        vector<bool> visitado;
        visitado.assign(n, false);
    
        // o algoritmo para quando a heap estiver vazia
        while(!heap.empty())
        {
            pair<int, int> vertice = heap.top();
            heap.pop();

            int distancia = vertice.first;
            int u = vertice.second;
        
            if(visitado[u]) // "u" jah foi explorado
            continue;
        
            visitado[u] = true;
        
            int custo;
            for(int j = 0; j < LA_par[u].size(); j++)
            {

                    pair<int, int> vizinho = LA_par[u][j];
                    int v = vizinho.first;
                    int peso = vizinho.second;

                    // tentativa de melhorar a estimativa de menor caminho da origem ao vertice v
                    custo = d[u] + peso;
                    if(custo < d[v]) 
                    {
                        d[v] = custo; 
                        heap.push(make_pair(d[v], v)); 
                    }
                }
            }
    }

    int main()
    {
        std::cin >> n >> m;
        int destino = n-1;
    
        LA = new vector<pair<int, int>>[n];
        LA_par = new vector<pair<int, int>>[n];
        int u, v;
        int p;
        for(int i = 0; i < m; i++)
        {
            std::cin >> u >> v; 
            std::cin >> p;
            u--;
            v--;
            LA[u].push_back(make_pair(v, p));
            LA[v].push_back(make_pair(u, p));
        }
        for(int i = 0; i < n; i++) {
            montador(i);
        }

        for(int i = 0; i < n; i++)
        {
            cout << "vertice " << i+1 << ": ";
            for(int j = 0; j < (int) LA_par[i].size(); j++)
            {
                cout << "(" << LA_par[i][j].first+1 << ", " << LA_par[i][j].second << ") ";
            }
            cout << endl;
        }

        dijkstra(0);
        if(d[destino] != __INT_MAX__) {
            cout << d[destino] << endl;
        }else {
            cout << -1 << endl;
        }

        return 0;
    }