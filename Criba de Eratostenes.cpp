/*
Que es la Criba de Eratostenes:
Es un algoritmo eficiente para encontrar todos los numeros primos hasta 
un numero n dado.

Como funciona:
- Se crea una lista o array que marca todos los numeros desde 2 hasta 
  n como "posibles primos".
- Se comienza por el primer numero primo (2).
- Se "eliminan" (marcan como no primos) todos los multiplos de ese numero.
- Se pasa al siguiente numero que aun este marcado como primo 
   y se repite el proceso.
- Al finalizar, los números que no fueron eliminados son primos.

Ejemplo rapido:
Para n = 10:
- Lista inicial: 2, 3, 4, 5, 6, 7, 8, 9, 10
- Primero, p = 2, eliminamos multiplos: 4, 6, 8, 10
- p = 3, eliminamos multiplos: 9
- p = 5, pero 5^2 = 25 > 10, paro aqui- Numeros que quedan: 2, 3, 5, 7 -> primos
*/

#include <bits/stdc++.h>
using namespace std;
#define FIN ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);

const int MAXN = 1e6 + 5;
vector<bool> esPrimo(MAXN, true);
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

int main() {
    FIN;
    int n; cin >> n;
    cribaEratostenes(n);
    for (int primo : primos)
        cout << primo << " ";
    cout << "\n";
    return 0;
}