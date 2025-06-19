#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0); cout.tie(0); cin.tie(0)
using namespace std;
 
int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
 
int dfs(int i, int j, vector<vector<int>> &a, vector<vector<bool>> &v) {
    int n = a.size(), m = a[0].size();
    v[i][j] = true;
    int res = a[i][j];
    for(int d = 0; d < 4; d++) {
        int ni = i + dx[d], nj = j + dy[d];
        if(ni >= 0 && ni < n && nj >= 0 && nj < m && a[ni][nj] > 0 && !v[ni][nj])
            res += dfs(ni, nj, a, v);
    }
    return res;
}
 
int main() {
    FIN;
    int t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cin >> a[i][j];
 
        vector<vector<bool>> v(n, vector<bool>(m, false));
        int maxVol = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(a[i][j] > 0 && !v[i][j])
                    maxVol = max(maxVol, dfs(i, j, a, v));
        cout << maxVol << '\n';
    }
}