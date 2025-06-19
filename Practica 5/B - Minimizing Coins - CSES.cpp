#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0); cout.tie(0); cin.tie(0)
using namespace std;

const int INF = 1e9;

int main() {
    FIN;
    int n, x; cin >> n >> x;

    vector<int> valores(n);
    for (int i = 0; i < n; i++)
        cin >> valores[i];

    vector<int> dp(x + 1, INF);
    dp[0] = 0;

    for (int i = 1; i <= x; i++) {
        for (int c : valores) {
            if (i - c >= 0) {
                dp[i] = min(dp[i], dp[i - c] + 1);
            }
        }
    }

    if (dp[x] == INF)
        cout << -1 << "\n";
    else
        cout << dp[x] << "\n";

    return 0;
}