#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x; cin >> n;
    unordered_set<int> valores;

    for (int i = 0; i < n; ++i) {
        cin >> x;
        valores.insert(x);
    }

    cout << valores.size() << "\n";
    return 0;
}