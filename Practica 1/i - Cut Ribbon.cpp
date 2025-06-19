#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n, a, b, c;
    cin >> n >> a >> b >> c;
 
    int maximo = 0;
 
    for(int i = 0; i <= n / a; ++i) {
        for(int j = 0; j <= n / b; ++j) {
            int rem = n - (i * a + j * b);
            if (rem >= 0 && rem % c == 0) {
                int k = rem / c;
                maximo = max(maximo, i + j + k);
            }
        }
    }
 
    cout << maximo << "\n";

    return 0;
}