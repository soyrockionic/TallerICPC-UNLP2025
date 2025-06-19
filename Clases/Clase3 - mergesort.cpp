#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0);cout.tie(0);cin.tie(0)
using namespace std;

long long n_of_inversion = 0;

void mergesort(vector <int> &a) {
    if(a.size() <= 1) return;
	
    int n = int(a.size());
    vector <int> l, r;
    for(int i = 0; i < n/2; i++) l.push_back(a[i]);
    for(int i = n/2; i < n; i++) r.push_back(a[i]);
	
    vector <int> copia = a;
	
    a.clear();
	
    mergesort(l);
    mergesort(r);
	
    int posl = 0, posr = 0;
    while(posl < l.size() and posr < r.size()) {
        if(l[posl] <= r[posr]) {
            a.push_back(l[posl]);
            posl += 1;
        } else {
            n_of_inversion += l.size() - posl;
            a.push_back(r[posr]);
            posr += 1;
        }
    }
 
    for(int i = posl; i < l.size(); i++) a.push_back(l[i]);
    for(int i = posr; i < r.size(); i++) a.push_back(r[i]);
	
    // for(int u : copia) cout << u << " "; cout << "\n";
    // for(int u : a) cout << u << " "; cout << "\n";
    // cout << "========================================" << "\n";
	
    return;
}

int main() {
    FIN;

    int n; cin >> n;
    vector <int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
	
    mergesort(v);
	
    cout << n_of_inversion << "\n";
	
    return 0;
}