/*
Exponenciacion modular:

Su tarea consiste en calcular eficientemente los valores a^b modulo 10^9 + 7.

Tenga en cuenta que en esta tarea asumimos que 0^0 = 1.

Entrada
La primera linea de entrada contiene un entero n: el numero de calculos.
Despues, hay n lineas, cada una con dos enteros a y b.

Salida
Imprima cada valor a^b modulo 10^9 + 7.

Restricciones
1 <= n <= 2 * 10^5
0 <= a,b <= 10^9

Ejemplo
Entrada:
3
3 4
2 8
123 123

Salida:
81
256
921450052
*/

#include <bits/stdc++.h>
using namespace std;
#define FIN ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);
typedef long long ll;

const ll MOD = 1e9 + 7;

int potencia(int a, int b, int m) {
    if(b == 0) return 1;

    int ans = 1;
    if(b % 2 == 1) ans = a;

    int potmedia = potencia(a, b/2, m);
    potmedia = ((long long)potmedia * potmedia) % m;

    ans = ((long long)ans * potmedia) % m;

    return ans;
}

int main(){  
    FIN;
    int n; cin >> n;
    while(n--) {
        int a,b; cin >> a >> b;
        int ans = potencia(a,b,MOD);
        cout << ans << "\n";
    }

    return 0;
}
