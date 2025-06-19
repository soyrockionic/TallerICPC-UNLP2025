/*
Problema: F - Longest Common Subsequence - CSES

Dadas dos cadenas de texto a y b, encontrar la longitud de la subsecuencia comun
mas larga entre ambas.

Una subsecuencia es una secuencia que puede obtenerse eliminando (o no) algunos
caracteres sin cambiar el orden relativo.

Ejemplo
Input
a = "ABCBDAB"
b = "BDCAB"
Ouput
4

Explicacion:
Una LCS posible es "BCAB", "BDAB" o "BCAB" -> todas de longitud 4.
*/

#include <bits/stdc++.h>
using namespace std;
#define FIN ios::sync_with_stdio(0); cout.tie(0); cin.tie(0)
 
int main() {
    FIN;
    string a, b;
    cin >> a >> b;

    int n = a.size();
    int m = b.size();

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i-1] == b[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    cout << dp[n][m] << "\n";
}