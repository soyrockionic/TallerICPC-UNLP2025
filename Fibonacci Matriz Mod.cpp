#include <bits/stdc++.h>
using namespace std;
#define FIN ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);

const long long MOD = 1e9+7;

struct Matriz {
    long long m[2][2];
};

Matriz multiplicar(Matriz a, Matriz b) {
    Matriz res;
    res.m[0][0] = (a.m[0][0]*b.m[0][0] + a.m[0][1]*b.m[1][0]) % MOD;
    res.m[0][1] = (a.m[0][0]*b.m[0][1] + a.m[0][1]*b.m[1][1]) % MOD;
    res.m[1][0] = (a.m[1][0]*b.m[0][0] + a.m[1][1]*b.m[1][0]) % MOD;
    res.m[1][1] = (a.m[1][0]*b.m[0][1] + a.m[1][1]*b.m[1][1]) % MOD;
    return res;
}

Matriz potencia(Matriz a, long long n) {
    Matriz res = {{{1,0},{0,1}}};
    while(n) {
        if(n & 1) res = multiplicar(res, a);
        a = multiplicar(a, a);
        n >>= 1;
    }
    return res;
}

long long fibonacci(long long n) {
    if(n == 0) return 0;
    Matriz M = {{{1,1},{1,0}}};
    Matriz res = potencia(M, n-1);
    return res.m[0][0];
}

int main() {
    FIN;
    long long n; cin >> n;
    cout << fibonacci(n) << "\n";
    return 0;
}