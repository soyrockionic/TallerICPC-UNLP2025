#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
 
void DFS(int v, vector<vector<int>>& g, vector<bool>& visitado, vector<int>& componente) {
    visitado[v] = true;
    componente.push_back(v);
    for (int u : g[v]) {
        if (!visitado[u]) {
            DFS(u, g, visitado, componente);
        }
    }
}
 
int main() {
    FIN;
    int n, m; cin >> n >> m;
    
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    vector<bool> visitado(n, false);
    vector<vector<int>> componentes;
    
    for (int i = 0; i < n; i++) {
        if (!visitado[i]) {
            vector<int> componente;
            DFS(i, g, visitado, componente);
            componentes.push_back(componente);
        }
    }
    
    vector<pair<int, int>> nuevaRutas;
    for (int i = 1; i < componentes.size(); i++) {
        nuevaRutas.push_back({componentes[0][0] + 1, componentes[i][0] + 1});
    }
    
    cout << nuevaRutas.size() << "\n";
    for (auto& ruta : nuevaRutas) {
        cout << ruta.first << " " << ruta.second << "\n";
    }
    
    return 0;
}