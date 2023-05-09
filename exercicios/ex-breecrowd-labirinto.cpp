#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    char** matriz = new char*[n];
    for(int i = 0; i < n; i++) {
        matriz[i] = new char[n];
        for(int j = 0;j < n; j++) {
            cin >> matriz[i][j];
        }
    }   

    return 0;
}