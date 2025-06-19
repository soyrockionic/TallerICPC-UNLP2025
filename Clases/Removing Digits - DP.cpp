/*
Problem E - Removing Digits - CSES

Dado un numero entero positivo n, tu tarea es eliminar digitos uno por uno
para llegar a 0. En cada paso, puedes restar uno de los digitos de n
(por ejemplo, si n = 27,podes restar 2 o 7, quedando 25 o 20).

Queres minimizar el numero de pasos necesarios para reducir n a cero.

Input
Un entero n tal que:
- 1 <= n <= 10^6

Output
Un solo entero: la minima cantidad de pasos para llegar a 0.

Ejemplo
Entrada
27
Salida
5

27 - 7 = 20 -> dp=1; 20 - 2 = 18 -> dp=2; 18 - 8 = 10 -> dp=3;
10 - 1 = 9 -> dp=4; 9 - 6 = 0 -> dp=5
*/

#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0); cout.tie(0); cin.tie(0)
using namespace std;

const int INF = 1e9;

int main() {
    FIN;
    int n; cin >> n;

    vector<int> dp(n + 1, INF);
    dp[0] = 0;

    for (int i = 1; i <= n; ++i) {
        int x = i;
        while (x > 0) {
            int digit = x % 10;
            x /= 10;
            if (digit != 0)
                dp[i] = min(dp[i], dp[i - digit] + 1);
        }
    }

    cout << dp[n] << '\n';
    return 0;
}