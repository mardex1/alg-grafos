    /* Mardem Arantes de Castro 202210086 Luiz Victor Soriano da Conceição 202210420*/
    #include <iostream>
    #include <queue>
    #include <climits>
    #include <cstring>   
    using namespace std;
    
    vector<int>* LA;

    int n;

    int m;
    
    bool bfs(int** MA, int s, int t, int parent[])
    {
        bool visited[2*n+2];
        memset(visited, 0, sizeof(visited));
    
        queue<int> q;
        q.push(s);
        visited[s] = true;
        parent[s] = -1;
    
        while (!q.empty()) {
            int u = q.front();
            q.pop();
    
            for (int v = 0; v < 2*n+2; v++) {
                if (visited[v] == false && MA[u][v] > 0) {
                    if (v == t) {
                        parent[v] = u;
                        return true;
                    }
                    q.push(v);
                    parent[v] = u;
                    visited[v] = true;
                }
            }
        }
        return false;
    }
    
    int fordFulkerson(int** MA, int s, int t)
    {
        int u, v;
    
        int** MAR = new int*[2*n+2];
        for(int i = 0; i < 2*n+2; i++) {
            MAR[i] = new int[2*n+2];
            for(int j = 0; j < 2*n+2; j++) {
                MAR[i][j] = 0;
            }
        }
        for (u = 0; u < 2*n+2; u++)
            for (v = 0; v < 2*n+2; v++)
                MAR[u][v] = MA[u][v];


        int parent[2*n+2];
    
        int max_flow = 0;

        while (bfs(MAR, s, t, parent)) {
            int path_flow = INT_MAX;
            for (v = t; v != s; v = parent[v]) {
                u = parent[v];
                path_flow = min(path_flow, MAR[u][v]);
            }
    
            for (v = t; v != s; v = parent[v]) {
                u = parent[v];
                MAR[u][v] -= path_flow;
                MAR[v][u] += path_flow;
            }
    
            max_flow += path_flow;
        }
    
        return max_flow;
    }

    int main() {
        while(cin >> n, n != -1){
            int cap[n+1];
            for(int i = 1; i < n+1; i++) {
                cin >> cap[i];  
            }
            int** MA = new int*[2*n+2];
            for(int i = 0; i < 2*n+2; i++) {
                MA[i] = new int[2*n+2];
                for(int j = 0; j < 2*n+2; j++) {
                    MA[i][j] = 0;
                }
            }

            for(int i = 1; i < n+1; i++) {
                MA[i][n+i] = cap[i];
            }

            cin >> m;
    
            int s = 0;
            int t = 2*n+1;

            int u, v, p;
            for(int i = 1; i <= m; i++) {
                cin >> u >> v >> p;

                MA[n+u][v] = p;
            }

            int u1, u2;
            cin >> u1 >> u2;
            int vert;
            for(int i = 0; i < u1; i++) {
                cin >> vert;
                MA[s][vert] = __INT_MAX__;
            }
            for(int i = 0; i < u2; i++) {
                cin >> vert;
                MA[vert+n][t] = __INT_MAX__;
            }

            /* for(int i = 0; i < 2*n+2;i++) {
                for(int j = 0; j < 2*n+2;j++) {
                    cout << MA[i][j] << " ";
                }cout << endl;
            } */

            cout << fordFulkerson(MA, s, t) << endl;
        }
        return 0;

    }