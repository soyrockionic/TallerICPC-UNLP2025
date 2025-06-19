#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0); cout.tie(0); cin.tie(0)
using namespace std;
 
int main() {
    FIN;
    int n; cin >> n;
 
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
 
    vector<int> dp;
 
    for (int i = 0; i < n; i++) {
        auto pos = lower_bound(dp.begin(), dp.end(), a[i]);
        if (pos == dp.end()) {
            dp.push_back(a[i]);
        } else {
            *pos = a[i];
        }
    }
 
    cout << dp.size() << "\n";
    
    return 0;
}
