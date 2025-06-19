#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, m, a;
    
    cin >> n >> m >> a;
    
    long long largo = (n + a - 1) / a;
    long long ancho = (m + a - 1) / a;

    cout << largo * ancho << "\n";

    return 0;
}