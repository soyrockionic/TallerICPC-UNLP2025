#include <bits/stdc++.h>
using namespace std;
#define FIN ios::sync_with_stdio(0);cout.tie(0);cin.tie(0)

void DFS(int act, vector<vector<int>> &g, vector<bool> &visto) {
    visto[act] = true;
    for(int sig : g[act]) {
        if(!visto[sig]) DFS(sig,g,visto);
    }
}

vector<int> BFS(int start, vector<vector<int>> &g, int n) {
    vector<int> dist(n,-1);
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    while(q.size() > 0) {
        int act = q.front();
        q.pop();
        for(int sig : g[act]) {
            if(dist[sig] == -1) {
                q.push(sig);
                dist[sig] = dist[act]+1;
            }
        }
    }
    return dist;
}

int main() {
    FIN;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<bool> visto(n,false);
    vector<int> caciques;
    for(int i = 0; i < n; i++) {
        if(visto[i] == false) {
            DFS(i,g,visto);
            caciques.push_back(i);
        }
    }
    cout << caciques.size()-1 << "\n";
    for(int i = 1; i < caciques.size(); i++) {
        cout << caciques[0]+1 << " " << caciques[i]+1 << "\n";
    }
    return 0;
}