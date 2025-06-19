#include <bits/stdc++.h>
using namespace std;
#define FIN ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);

const int LOG = 20;

int log2_floor(int x) {
    int res = 0;
    while ((1 << (res + 1)) <= x) res++;
    return res;
}

struct SparseTable {
    vector<vector<int>> s;
    int n;
    SparseTable(vector<int> &v, int _n) {
        n = _n;
        s.resize(n);
        for (int i = 0; i < n; i++) s[i].resize(LOG);
        for (int j = 0; j < LOG; j++) {
            for (int i = 0; i < n; i++) {
                if (j == 0) {
                    s[i][j] = v[i];
                    continue;
                }
                s[i][j] = s[i][j - 1];
                if (i + (1 << (j - 1)) < n) {
                    s[i][j] = min(s[i][j], s[i + (1 << (j - 1))][j - 1]);
                }
            }
        }
    }

    int query(int l, int r) {
        int length = r - l + 1;
        int j = log2_floor(length);
        return min(s[l][j], s[r - (1 << j) + 1][j]);
    }
};

int main() {
    FIN;

    int n, t;
    cin >> n >> t;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    SparseTable s(v, n);

    while (t--) {
        int l, r;
        cin >> l >> r;
        l--; r--; 
        cout << s.query(l, r) << "\n";
    }

    return 0;
}