#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0);cout.tie(0);cin.tie(0)
using namespace std;
 
long long n_of_inversion = 0;
 
void mergesort(vector<int> &a, int l, int r, vector<int> &aux) {
    if (r - l <= 1) return;
 
    int m = (l + r) / 2;
    mergesort(a, l, m, aux);
    mergesort(a, m, r, aux);
 
    int i = l, j = m, k = l;
    while (i < m && j < r) {
        if (a[i] <= a[j]) {
            aux[k++] = a[i++];
        } else {
            n_of_inversion += m - i;
            aux[k++] = a[j++];
        }
    }
 
    while (i < m) aux[k++] = a[i++];
    while (j < r) aux[k++] = a[j++];
 
    for (int p = l; p < r; ++p) a[p] = aux[p];
}
 
int main() {
    FIN;
    int n;
    cin >> n;
    vector<int> a(n), aux(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
 
    mergesort(a, 0, n, aux);
 
    cout << n_of_inversion << "\n";
    return 0;
}
