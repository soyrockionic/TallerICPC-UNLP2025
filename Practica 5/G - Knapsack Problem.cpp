#include <bits/stdc++.h>
using namespace std;
#define FIN ios::sync_with_stdio(0); cout.tie(0); cin.tie(0)
 
int main() {
    FIN;
    int n, x;
    cin >> n >> x;

    vector<int> p(n), v(n);
    for(int i=0; i<n; i++)
        cin >> p[i];
    for(int j=0; j<n; j++)
        cin >> v[j];

    vector<int> dp(x + 1, 0);

    for (int i = 0; i < n; ++i) {
        for (int w = x; w >= p[i]; --w) {
            dp[w] = max(dp[w], dp[w - p[i]] + v[i]);
        }
    }

    cout << dp[x] << "\n";

    return 0;
}