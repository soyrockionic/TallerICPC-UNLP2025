#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;

    vector<pair<int, int>> eventos;

    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        eventos.push_back({a, 1});
        eventos.push_back({b, -1});
    }

    sort(eventos.begin(), eventos.end());

    int clientes = 0, maxClientes = 0;

    for (int i = 0; i < eventos.size(); ++i) {
        int tipo = eventos[i].second;
        clientes += tipo;
        maxClientes = max(maxClientes, clientes);
    }

    cout << maxClientes << "\n";

    return 0;
}