#include <iostream>
using namespace std;

int** mult_matrix(int** matrix_original,int** matrix_resultado, int k, int n) {
    int** matrix_aux = new int*[n];
    for(int i = 0; i < n; i++) {
        matrix_aux[i] = new int[n];
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int resultado = 0;
            for(int k = 0; k < n; k++) {
                resultado = resultado + matrix_original[i][k] * matrix_resultado[k][j];
            }
            matrix_aux[i][j] = resultado; 
        }
    }
    return matrix_aux;
}

int main() {
    int n, m;
    cin >> n;
    do{
        cin >> m;
        int** resultado = new int*[n];
        int** MA = new int*[n];
        for(int i = 0; i < n; i++) {
            MA[i] = new int[n];
            resultado[i] = new int[n];
            for(int j = 0; j < n; j++) {
                MA[i][j] = 0;
                resultado[i][j] = 0;
            }
        }

        int u, v;
        for(int i = 0; i < m; i++) {
            cin >> u >> v;

            resultado[u][v] = 1;
            resultado[v][u] = 1;
            MA[u][v] = 1;
            MA[v][u] = 1;
        }

        int iteracoes, k;

        cin >> iteracoes >> k;
        for(int i = 0; i < k-1; i++) {
            resultado = mult_matrix(MA, resultado, k, n);
        }

        int a, b;
        for(int i = 1; i < iteracoes; i++) {
            cin >> a >> b;
            cout << resultado[a][b] << endl;
        }

        cin >> a >> b;
        cout << resultado[a][b];

        delete[] resultado;
        delete[] MA;


        cin >> n;
        if(n != -1) {
            cout << endl;
        }

    }while(n != -1);

    return 0;
}