#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0);cout.tie(0);cin.tie(0)
using namespace std;
using ll = long long;
 
int main() {
    FIN;
    int n, m; cin >> n >> m;
 
    unordered_map<string, string> mono;
 
    for (int i = 0; i < n; ++i) {
        string si, ti; cin >> si >> ti;
        mono[si] = ti;
    }
 
    vector<string> frase;
    for (int i = 0; i < m; ++i) {
        string pal; cin >> pal;
        frase.push_back(mono[pal]);
    }
 
    for (int i = 0; i < m; ++i) {
        cout << frase[i];
        if (i < m - 1) cout << " ";
    }
    cout << "\n";
    return 0;
}