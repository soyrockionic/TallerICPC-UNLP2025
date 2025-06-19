#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0);cout.tie(0);cin.tie(0)
using namespace std;
using ll = long long;
 
void linea(int total, int d) {
    int asteriscos = (total - d) / 2;
    cout << string(asteriscos, '*') << string(d, 'D') << string(asteriscos, '*') << '\n';
}
 
int main() {
    int n; cin >> n;
 
    for (int i = 0; i < n; ++i) {
        int d = i <= n / 2 ? 2 * i + 1 : 2 * (n - 1 - i) + 1;
        linea(n, d);
    }
    return 0;
}