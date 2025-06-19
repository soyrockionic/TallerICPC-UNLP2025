#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0);cout.tie(0);cin.tie(0)
using namespace std;
using ll = long long;
 
int main() {
    FIN;
    int n;
    ll p;
    cin >> n >> p;
 
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i] >> b[i];
 
    ll consumoTotal = accumulate(a.begin(), a.end(), 0LL);
    if (consumoTotal <= p) {
        cout << -1 << "\n";
        return 0;
    }
 
    double l = 0, r = 1e12;
    for (int j = 0; j < 100; ++j) {
        double mid = (l + r) / 2;
 
        double totalNecesaria = 0;
        for (int i = 0; i < n; ++i) {
            double falta = a[i] * mid - b[i];
            if (falta > 0) totalNecesaria += falta;
        }
 
        if (totalNecesaria <= p * mid) {
            l = mid;
        } else {
            r = mid;
        }
    }
 
    cout << fixed << setprecision(10) << l << "\n";
    return 0;
}