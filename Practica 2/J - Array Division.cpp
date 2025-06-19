#include <bits/stdc++.h>
using namespace std;
 
bool sePuedeDividir(const vector<int>& nros, int k, long long maxSum) {
    long long suma = 0;
    int partes = 1;
 
    for (int x : nros) {
        if (x > maxSum) return false;
        if (suma + x > maxSum) {
            partes++;
            suma = x;
        } else {
            suma += x;
        }
    }
 
    return partes <= k;
}
 
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nros(n);
 
    for (int i = 0; i < n; i++)
        cin >> nros[i];
 
    long long izq = 0, der = 1e15, res = der;
 
    while (izq <= der) {
        long long mid = (izq + der) / 2;
        if (sePuedeDividir(nros, k, mid)) {
            res = mid; 
            der = mid - 1;
        } else {
            izq = mid + 1;
        }
    }
 
    cout << res << "\n";
    return 0;
}