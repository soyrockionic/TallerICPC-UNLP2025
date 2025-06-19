#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int main() {
    FIN;
    int t; cin >> t;

    for(int i=0; i<t; i++) {
        int n, k_op;
        cin >> n >> k_op;

        string s; cin >> s;

        vector<long long> penalty(n);
        long long maxi = 0;
        for (int i = 0; i < n; ++i) {
            cin >> penalty[i];
            maxi = max(maxi, penalty[i]);
        }

        long long l = 0, r = maxi;
        while (l < r) {
            long long mid = (l + r) / 2;
            int ops = 0;

            for (int i = 0; i < n && ops <= k_op;) {
                if (s[i] == 'B' && penalty[i] > mid) {
                    ++ops;
                    while (i < n && !(s[i] == 'R' && penalty[i] > mid))
                        ++i;
                } else {
                    ++i;
                }
            }

            if (ops <= k_op)
                r = mid;
            else
                l = mid + 1;
        }

        cout << l << "\n";
    }

    return 0;
}