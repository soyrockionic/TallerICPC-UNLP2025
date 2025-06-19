#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
 
vector<vector<int>> grafo;
vector<bool> visitado;
 
void dfs(int nodo, vector<int>& componente) {
    visitado[nodo] = true;
    componente.push_back(nodo);
    for (int vecino : grafo[nodo]) {
        if (!visitado[vecino]) {
            dfs(vecino, componente);
        }
    }
}
 
int main() {
    FIN;
    int n, m;
    cin >> n >> m;
 
    grafo.assign(n + 1, {});
    visitado.assign(n + 1, false);
 
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        grafo[u].push_back(v);
        grafo[v].push_back(u);
    }
 
    int ciclos = 0;
 
    for (int i = 1; i <= n; ++i) {
        if(!visitado[i]) {
            vector<int> componente;
            dfs(i, componente);
 
            bool esCiclo = true;
            if(componente.size() < 3) esCiclo = false;
 
            for (int nodo : componente) {
                if(grafo[nodo].size() != 2) {
                    esCiclo = false;
                    break;
                }
            }
 
            if(esCiclo) ciclos++;
        }
    }
 
    cout << ciclos << "\n";
    return 0;
}