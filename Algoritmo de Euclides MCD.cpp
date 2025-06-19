/*
Algoritmo de Euclides para calcular el maximo comun divisor (MCD)

Descripcion clasica del algoritmo:

Para dos enteros positivos a y b, tal que a >= b:
1 - Si b = 0, entonces el MCD es a.
2 - Si no, reemplazar a por b y b por a mod b.
3 - Repetir hasta que b = 0.

Ejemplo manual:

Calcular MCD(1071, 462):
- 1071 mod 462 = 147 -> (1071, 462) -> (462, 147)
- 462 mod 147 = 21 -> (462, 147)-> (147, 21)
- 147 mod 21 = 0-> (147, 21) -> (21, 0)
- Resultado: MCD = 21
*/

#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0); cout.tie(0); cin.tie(0)
using namespace std;

int mcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}
 
int main() {
    FIN;
    int a, b;
    cin >> a >> b;
    cout << mcd(a, b) << "\n";
    return 0;
}

/*
ALGORITMO Euclides MCD

ENTRADA: Dos enteros positivos A y B, con A >= B
SALIDA: El maximo comun divisor de A y B

MIENTRAS B != 0 HACER
    R <- A MOD B
    A <- B
    B <- R
FIN MIENTRAS

RETORNAR A
*/