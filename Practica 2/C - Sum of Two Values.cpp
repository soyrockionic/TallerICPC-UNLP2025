#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long x;
    cin >> n >> x;

    vector<long long> a(n);
    unordered_map<long long, int> mapa;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n; ++i) {
        long long complemento = x - a[i];
        if (mapa.count(complemento)) {
            cout << mapa[complemento] + 1 << " " << i + 1 << "\n";
            return 0;
        }
        mapa[a[i]] = i;
    }

    cout << -1 << "\n";
    return 0;
}