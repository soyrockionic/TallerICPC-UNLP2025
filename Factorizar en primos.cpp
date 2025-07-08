/*
Factorizacion con ayuda de la criba (pasos generales):
1 - Genera la lista de primos hasta n con la Criba de Eratostenes.
2 - Para factorizar un numero m, divide sucesivamente por los primos de la lista:
  - - Mientras el primo divide a m, anotalo y divide m por ese primo.
3 - Continua hasta que m = 1 o que el primo sea mayor que raiz cuadrada de m.

Ejemplo con el codigo:
Supongamos que ejecutas el programa e ingresas el numero 30.
El codigo hace esto:
1 - Usa la Criba de Eratostenes para obtener los primos:
    Por ejemplo: {2 3 5 7 11 13 17 19 23 29}
2 - Empieza a dividir 30 por los primos uno por uno:
  - - 30 / 2 = 15 -> agrega 2
  - - 15 / 3 = 5  -> agrega 3
  - - 5 / 5 = 1   -> agrega 5
3 - Factorizacion de 30: 2 3 5
*/

#include <bits/stdc++.h>
using namespace std;
#define FIN ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);

const int MAX = 1e6 + 5;
vector<bool> esPrimo(MAX, true);
vector<int> primos;

void cribaEratostenes(int n) {
    esPrimo[0] = esPrimo[1] = false;

    for (int i = 2; i * i <= n; ++i) {
        if (esPrimo[i]) {
            for (int j = i * i; j <= n; j += i) {
                esPrimo[j] = false;
            }
        }
    }

    for (int i = 2; i <= n; ++i) {
        if (esPrimo[i]) primos.push_back(i);
    }
}

void factorizar(int num) {
    cout << "Factorizacion de " << num << ": ";
    for (int p : primos) {
        if (p * p > num) break;
        while (num % p == 0) {
            cout << p << " ";
            num /= p;
        }
    }
    if (num > 1) cout << num;
    cout << "\n";
}

int main() {
    FIN;
    int n; cin >> n;
    cribaEratostenes(n);
    for (int primo : primos)
        cout << primo << " ";
    cout << "\n";
    int f; cin >> f;
    factorizar(f);
    return 0;
}