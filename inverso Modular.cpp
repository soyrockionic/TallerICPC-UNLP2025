/*
Inverso modular

Dado un numero a y un modulo m, el inverso modular de a (llamemoslo x)
es un numero tal que:

a * x % m == 1

Esto solo tiene solucion si a y m son coprimos, es decir, si gcd(a, m) = 1.

Euclides extendido

El algoritmo de Euclides extendido no solo halla el MCD, tambien encuentra 
los coeficientes x y y que satisfacen:

a * x + m * y = gcd(a,m)

Y si ese MCD es 1, entonces:

a * x % m == 1

Donde x es el inverso modular
*/

#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int euclidesExtendido(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1; y = 0;
        return a;
    }
    int x1, y1;
    int d = euclidesExtendido(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return d;
}

int inversoModular(int a, int m) {
    int x, y;
    int g = euclidesExtendido(a, m, x, y);
    if (g != 1) return -1;
    return (x % m + m) % m;
}

int main() {
    int a, m; cin >> a >> m;
    int inv = inversoModular(a, m);
    if (inv == -1)
        cout << 0 << "\n";
    else
        cout << inv << "\n";
    return 0;
}