#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
 
int n, m;
vector<string> mapa;
vector<vector<bool>> visitado;
 
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
 
bool dentro(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}
 
void dfs(int x, int y) {
    visitado[x][y] = true;
    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (dentro(nx, ny) && !visitado[nx][ny] && mapa[nx][ny] == '.') {
            dfs(nx, ny);
        }
    }
}
 
int main() {
    FIN;
    cin >> n >> m;
    mapa.resize(n);
    visitado.assign(n, vector<bool>(m, false));
 
    for (int i = 0; i < n; i++)
        cin >> mapa[i];
 
    int habitaciones = 0;
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visitado[i][j] && mapa[i][j] == '.') {
                dfs(i, j);
                habitaciones++;
            }
        }
    }
 
    cout << habitaciones << "\n";
    return 0;
}