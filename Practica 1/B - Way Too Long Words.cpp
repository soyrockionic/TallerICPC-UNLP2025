#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    string p;
    
    cin >> n;
    
    for(int i=0; i<n; i++){
        cin >> p;
        if(p.size() > 10)
            cout << p[0] << p.size() - 2 << p[p.size()-1] << "\n";
        else
            cout << p << "\n";
    }
    
    return 0;
}