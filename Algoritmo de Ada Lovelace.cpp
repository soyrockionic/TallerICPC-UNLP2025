#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0); cout.tie(0); cin.tie(0)
using namespace std;

// Procedimiento para calcular los numeros de Bernoulli al estilo de Ada Lovelace
void calcularNrosBernoulliAda(vector<double>& B, int n) {
    B.assign(n + 1, 0.0); // Inicializar todo a 0
    B[0] = 1.0; // B[0] = 1
    
    // Tabla para coeficientes binomiales y calculos intermedios
    vector<vector<double>> tabla(n + 2, vector<double>(n + 2, 0.0));

    // Inicializar tabla de coeficientes binomiales (Triangulo de Pascal)
    for (int i = 0; i <= n + 1; ++i) {
        tabla[i][0] = 1.0;
        for (int j = 1; j <= i; ++j) {
            tabla[i][j] = tabla[i - 1][j - 1] + tabla[i - 1][j];
        }
    }

    // Calcular los numeros de Bernoulli usando la tabla
    for (int m = 1; m <= n; ++m) {
        double suma = 0.0;
        for (int k = 0; k < m; ++k) {
            suma += tabla[m + 1][k] * B[k];
        }
        B[m] = -suma / (m + 1);
    }

    // Ajustar a cero los Bernoulli impares mayores que 1
    for (int i = 3; i <= n; i += 2) {
        B[i] = 0.0;
    }
}

int main() {
    FIN;
    int n; cin >> n;
    vector<double> B(n + 1);

    calcularNrosBernoulliAda(B, n);

    // Mostrar resultados con 5 cifras decimales
    cout << fixed << setprecision(5);
    for (int i = 0; i <= n; ++i) {
        cout << "B[" << i << "] = " << B[i] << "\n";
    }

    return 0;
}

/*
ALGORITMO Calcular_Numeros_Bernoulli_Ada
ENTRADA: Un numero entero N (nivel maximo de Bernoulli)
SALIDA: Un arreglo B[0..N] con los numeros de Bernoulli

1. Crear un arreglo B[0..N] y asignar B[0] <- 1
2. Para cada indice i desde 1 hasta N:
      B[i] <- 0

3. Crear una tabla TABLA[0..N+1][0..N+1] para coeficientes binomiales

4. Para i desde 0 hasta N+1 hacer:
      TABLA[i][0] <- 1
      Para j desde 1 hasta i hacer:
          TABLA[i][j] <- TABLA[i-1][j-1] + TABLA[i-1][j]

5. Para m desde 1 hasta N hacer:
      SUMA <- 0
      Para k desde 0 hasta m-1 hacer:
          SUMA <- SUMA + TABLA[m+1][k] * B[k]
      B[m] <- (-1 * SUMA) / (m + 1)

6. Para cada i impar desde 3 hasta N hacer:
      B[i] <- 0

7. IMPRIMIR todos los B[0..N]
*/