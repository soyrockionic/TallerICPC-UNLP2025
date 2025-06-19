#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    int nro, par=0, impar=0, posPar, posImpar;

    for(int i=0; i<n; i++){
        cin >> nro;
        if(nro % 2 == 0){
          par++;
          posPar = i+1;
        }
        else{
          impar++;
          posImpar = i+1;
        }
    }

    if(par == 1)
        cout << posPar << "\n";
    else
        cout << posImpar << "\n";
        
    return 0;
}