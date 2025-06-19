#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;

    vector<int> numeros(n);

    for (int i = 0; i < n; ++i) {
        cin >> numeros[i];
    }

    sort(numeros.begin(), numeros.end());

    int distintos = 1;

    for (int i = 1; i < n; ++i) {
        if (numeros[i] != numeros[i - 1]) {
            distintos++;
        }
    }

    cout << distintos << "\n";

    return 0;
}