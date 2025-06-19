#include <bits/stdc++.h> 
using namespace std;

int main() {
    int n; cin >> n; 
    vector<long long> nros(n);

    for (int i = 0; i < n; i++) {
        cin >> nros[i];
    }

    long long actual_sum = nros[0];
    long long max_sum = nros[0];

    for (int i = 1; i < n; i++) {
        actual_sum = max(nros[i], actual_sum + nros[i]);
        max_sum = max(max_sum, actual_sum);
    }

    cout << max_sum << "\n";

    return 0;
}