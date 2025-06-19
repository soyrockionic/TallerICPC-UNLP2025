/*
  Problema: Guess the K-th Zero (version interactiva)

  Descripcion:
  Dado un arreglo binario oculto de longitud 'n', con ceros y unos,
  hay que encontrar la posición del k-esimo cero (de izquierda a derecha).
  No se accede directamente al arreglo, sino que se puede hacer consultas del tipo:

      ? l r

  La respuesta es la cantidad de unos en el rango [l, r].

  Despues de determinar la posicion del k-esimo cero, se debe responder con:

      ! posicion

  Restricciones:
  - 1 ≤ k ≤ numero total de ceros
  - Las consultas son limitadas, por lo tanto se debe usar busqueda binaria.

  Estrategia:
  - Usar busqueda binaria sobre las posiciones del arreglo.
  - En cada mitad, calcular cuantos ceros hay con:
      ceros = (tamaño del rango) - (cantidad de unos)
  - Reducir el rango segun si ya encontramos suficientes ceros o no.

*/

#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0);cout.tie(0);cin.tie(0)
using namespace std;

int preguntar(int l, int r) {
    cout << "? " << l << " " << r << "\n";
    cout.flush();
    int suma; cin >> suma;
    if (suma == -1) exit(0);
    return suma;
}

int main() {
    FIN;
    int n, t;
    cin >> n >> t;

    while (t--) {
        int k; cin >> k;

        int l = 1, r = n;
        while (l < r) {
            int mid = (l + r) / 2;

            int unos = preguntar(l, mid);
            int total = mid - l + 1;
            int ceros = total - unos;

            if (ceros >= k)
                r = mid;
            else {
                k -= ceros;
                l = mid + 1;
            }
        }

        cout << "! " << l << "\n";
        cout.flush();
    }
    return 0;
}

/* Usamos busqueda binaria porque es la forma mas eficiente y estandar en competencias
   para encontrar el k-esimo elemento desconocido en problemas interactivos. */