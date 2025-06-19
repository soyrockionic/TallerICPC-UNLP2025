#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> nros(n);
    
    for (int i = 0; i < n; i++) {
        cin >> nros[i];
    }

    stack<int> s;
    for (int i = 0; i < n; i++) {
        while (!s.empty() && nros[s.top()] >= nros[i]) {
            s.pop();
        }

        if (s.empty()) {
            cout << 0 << " ";
        } else {
            cout << s.top() + 1 << " ";
        }

        s.push(i);
    }

    cout << "\n";
    return 0;
}