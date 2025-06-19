#include <bits/stdc++.h>
using namespace std;
 
int main() {
    double c;
    cin >> c;
    double l = 0, r = c, m;
    for (int i = 0; i < 100; ++i) {
        m = (l + r) / 2;
        (m * m + sqrt(m) < c) ? l = m : r = m;
    }
    cout << fixed << setprecision(10) << (l + r) / 2 << '\n';
    return 0;
}