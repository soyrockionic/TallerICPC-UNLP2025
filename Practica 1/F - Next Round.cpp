#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k, c=0;
    cin >> n >> k;

    int nros[n];

    for(int i=0; i<n; i++)
        cin >> nros[i];

    for(int i=0; i<n; i++)
        if(nros[i] > 0 && nros[i] >= nros[k-1])
            c++;

    cout << c << "\n";

    return 0;
}