#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0);cout.tie(0);cin.tie(0)
using namespace std;

long long n_of_inversion = 0;  // Inversiones
long long movimientos = 0;     // Copias
long long comparaciones = 0;   // Comparaciones

void mergesort(vector<int> &a) {
    if (a.size() <= 1) return;

    int n = int(a.size());
    vector<int> l, r;

    for (int i = 0; i < n / 2; i++) l.push_back(a[i]);
    for (int i = n / 2; i < n; i++) r.push_back(a[i]);

    a.clear();

    mergesort(l);
    mergesort(r);

    int posl = 0, posr = 0;
    while (posl < l.size() && posr < r.size()) {
        comparaciones++; // Comparación entre l[posl] y r[posr]

        if (l[posl] <= r[posr]) {
            a.push_back(l[posl]);
            movimientos++;  // Movimiento de datos
            posl++;
        } else {
            n_of_inversion += l.size() - posl;  // Cuenta de inversiones
            a.push_back(r[posr]);
            movimientos++;
            posr++;
        }
    }

    // Copia lo que queda de cada sub-arreglo
    for (int i = posl; i < l.size(); i++) {
        a.push_back(l[i]);
        movimientos++;
    }

    for (int i = posr; i < r.size(); i++) {
        a.push_back(r[i]);
        movimientos++;
    }

    return;
}

int main() {
    FIN;

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    mergesort(v);

    // Dependiendo de lo que te pidan, descomentas las lineas necesarias
    cout << "Inversiones: " << n_of_inversion << "\n";   // Si se piden inversiones
    cout << "Movimientos: " << movimientos << "\n";     // Si se piden movimientos
    cout << "Comparaciones: " << comparaciones << "\n";  // Si se piden comparaciones

    return 0;
}