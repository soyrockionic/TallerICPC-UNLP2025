#include <bits/stdc++.h>
using namespace std;
#define FIN ios::sync_with_stdio(0);cout.tie(0);cin.tie(0);

int main(){
     FIN;
     int w; cin >> w;
     
     if((w % 2 == 0)&&(w > 2))
       cout << "YES" << "\n";
     else
       cout << "NO" << "\n";
    
    return 0;   
}	