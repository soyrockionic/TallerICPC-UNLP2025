#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n; cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    map<ll, ll> count;
    count[0] = 1;
    
    ll sum = 0;
    ll res = 0;

    for (int i = 0; i < n; ++i) {
        sum += a[i];
        ll mod = ((sum % n) + n) % n;
        res += count[mod];
        count[mod]++;
    }

    cout << res << "\n";
    return 0;
}