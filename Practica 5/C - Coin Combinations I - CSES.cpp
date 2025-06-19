#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0); cout.tie(0); cin.tie(0)
using namespace std;
 
const int MOD = 1e9 + 7;
 
int main() {
    FIN;
    int n, x; cin >> n >> x;
 
    vector<int> monedas(n);
    for (int i = 0; i < n; i++)
        cin >> monedas[i];
 
    vector<int> dp(x + 1, 0);
    dp[0] = 1;
 
    for (int i = 1; i <= x; i++) {
        for (int c : monedas) {
            if (i - c >= 0) {
                dp[i] = (dp[i] + dp[i - c]) % MOD;
            }
        }
    }
 
    cout << dp[x] << "\n";
    return 0;
}
