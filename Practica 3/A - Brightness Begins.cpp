#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0);cout.tie(0);cin.tie(0);
using namespace std;
 
int main() {
    FIN;   
    int t; cin >> t;
	
    for(int i=0; i<t; i++) {
        long long k, l = 1, r = 2e18; 
        cin >> k;
        while (l < r) {
            long long mid = (l + r) / 2;
            long long n = mid - (long long)sqrtl(mid);
            if (n >= k)
                r = mid;
            else
                l = mid + 1;
        }
        cout << l << "\n";
    }
	
    return 0;
}

/*
¿Como funciona la busqueda binaria aqui?
1- Busca entre un rango enorme: desde l = 1 hasta r = 2 * 10^18.
2- En cada paso:
   - Toma el numero del medio: mid = (l + r) / 2.
   - Calcula cuantas bombillas NO son cuadrados perfectos con la formula:
     n = mid - sqrt(mid)
     Eso es porque solo las bombillas en posiciones de
     cuadrados perfectos (1, 4, 9...) quedan encendidas.
3- Si ese numero n es mayor o igual que k, entonces quizas ya es suficiente
    o puede ser mas pequeño, así que baja el rango.
4- Si n < k, necesitas mas bombillas, entonces sube el rango.
- Cuando termina, te da el n mas pequeño que sirve.

Resumen para elegir la cota:
Limite inferior l = 1 (empezamos desde 1 bombilla).
Limite superior r = 2e18 porque cubre de sobra cualquier posible n necesario,
sin salirse de long long.
Como usamos busqueda binaria, no importa que sea muy grande: se reduce rapidamente.
*/