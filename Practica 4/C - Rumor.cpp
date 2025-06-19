#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0); cout.tie(0); cin.tie(0)
using namespace std;
 
const int MAXN = 100005;
vector<int> adj[MAXN];
bool visitado[MAXN];
long long costo[MAXN];
 
long long dfs(int u) {
    visitado[u] = true;
    long long mn = costo[u];
    for (int v : adj[u]) {
        if (!visitado[v]) {
            mn = min(mn, dfs(v));
        }
    }
    return mn;
}
 
int main() {
    FIN;
    int n, m;
    cin >> n >> m;
 
    for (int i = 1; i <= n; ++i)
        cin >> costo[i];
 
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    long long total = 0;
    for (int i = 1; i <= n; ++i) {
        if (!visitado[i]) {
            total += dfs(i);
        }
    }
 
    cout << total << '\n';
    return 0;
}