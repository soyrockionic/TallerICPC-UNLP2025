#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0);cout.tie(0);cin.tie(0);
using namespace std;

int pintar(const vector<int>& a, int l, int r, int alturaActual) {
    if (l > r) return 0;

    int minAltura = a[l];
    for (int i = l; i <= r; ++i)
        minAltura = min(minAltura, a[i]);
        
    int pinceladas = minAltura - alturaActual;

    int i = l;
    while (i <= r) {
        if (a[i] == minAltura) {
            ++i;
            continue;
        }
        int j = i;
        while (j <= r && a[j] > minAltura) ++j;
        pinceladas += pintar(a, i, j - 1, minAltura);
        i = j;
    }

    return min(pinceladas, r - l + 1);
}

int main() {
    FIN;
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; ++i)
        cin >> a[i];

    cout << pintar(a, 0, n - 1, 0) << endl;

    return 0;
}