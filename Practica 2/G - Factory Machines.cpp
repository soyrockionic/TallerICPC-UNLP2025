#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    ll t;
    cin >> n >> t;

    vector<ll> k(n);
    for (int i = 0; i < n; ++i) cin >> k[i];

    ll l = 1, r = 1e18;
    while (l < r) {
        ll m = (l + r) / 2;
        ll productos = 0;
        for (ll tiempo : k) {
            productos += m / tiempo;
            if (productos >= t) break;
        }
        if (productos >= t)
            r = m;
        else
            l = m + 1;
    }

    cout << l << "\n";
    return 0;
}