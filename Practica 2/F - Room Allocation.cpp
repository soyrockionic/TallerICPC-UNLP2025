#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;

    vector<tuple<int, int, int>> clientes(n);
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        clientes[i] = {a, b, i};
    }

    sort(clientes.begin(), clientes.end());

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> habitaciones;
    vector<int> resultado(n);
    int total = 0;

    for (auto [a, b, idx] : clientes) {
        if (!habitaciones.empty() && habitaciones.top().first < a) {
            int hab = habitaciones.top().second;
            habitaciones.pop();
            resultado[idx] = hab;
            habitaciones.push({b, hab});
        } else {
            total++;
            resultado[idx] = total;
            habitaciones.push({b, total});
        }
    }

    cout << total << "\n";
    for (int x : resultado) cout << x << " ";
    cout << "\n";

    return 0;
}