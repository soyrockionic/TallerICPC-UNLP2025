#include <bits/stdc++.h>
using namespace std;
 
int main() { 

    int n, X = 0;  cin >> n;
    
    string sentencia;
    for(int i=0; i<n; i++){
        cin >> sentencia;
        if(sentencia[1] == '+')
            X++;
        else
            X--;
    }
    
    cout << X << "\n";
 
    return 0;
}