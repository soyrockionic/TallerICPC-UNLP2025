/* 
Problema -> G - interview
El problema consiste en identificar una pila que contiene una piedra especial de 2 gramos,
mientras que el resto de las piedras pesan 1 gramo. Para hacerlo, se pueden hacer preguntas
al director, donde se eligen un conjunto de pilas y se obtiene la suma de sus pesos.

Enfoque:
- Utilizamos busqueda binaria para dividir el rango de pilas en mitades y preguntamos por la suma
  de las pilas en cada mitad.
- Si la suma total de una mitad es mayor que la suma esperada (sumando solo los pesos de 1 gramo por pila),
  sabemos que la piedra especial esta en esa mitad.
- Repetimos este proceso, reduciendo el rango hasta encontrar la pila que contiene la piedra especial.

Pasos del algoritmo:
1. Se divide el rango de pilas en dos mitades.
2. Se pregunta por el peso total de las pilas en la primera mitad.
3. Si la suma obtenida es mayor que la suma esperada, la piedra especial esta en esa mitad, de lo contrario,
    esta en la otra mitad.
4. El proceso se repite hasta identificar la pila con la piedra especial.

*/

#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0);cout.tie(0);cin.tie(0)
using namespace std;

long long preguntar(int l, int r) {
    cout << "? " << (r - l);
    for (int i = l+1; i <= r; i++) cout << " " << i;
    cout << "\n" << flush;
    long long suma; cin >> suma;
    return suma;
}

int main() {
    FIN;
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        int l = 0, r = n-1;
        while (l < r) {
            int mid = (l + r) / 2;
            long long espe = 0;
            for (int i = l; i <= mid; i++)
                espe += a[i];
            if (preguntar(l, mid+1) > espe)
                r = mid;
            else
                l = mid+1;
        }
        cout << "! " << l+1 << "\n" << flush;
    }
    return 0;
}