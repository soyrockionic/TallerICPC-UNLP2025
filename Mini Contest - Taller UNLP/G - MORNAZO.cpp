#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0);cout.tie(0);cin.tie(0)
using namespace std;
using ll = long long;
 
int main() {
    FIN;
    string codigo; cin >> codigo;
 
    string nro = "";
    int i = 0;
 
    while (i < codigo.size()) {
        if (codigo[i] == '.') {
            nro += '0';
            i++;
        } else if (codigo[i] == '-') {
            if (i + 1 < codigo.size()) {
                if (codigo[i + 1] == '.') {
                    nro += '1';
                    i += 2;
                } else if (codigo[i + 1] == '-') {
                    nro += '2';
                    i += 2;
                }
            }
        }
    }
 
    cout << nro << "\n";
 
    return 0;
}