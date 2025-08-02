#include <bits/stdc++.h>
using namespace std;

vector<bool> visited;
vector<vector<int>> adj;

void dfs(int v){
    visited[v] = true;
    for (int i : adj[v]){
        if(!visited[i]){
            dfs(i);
        }
    }
}

int main (){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m; cin >> n >> m;
    adj.resize(n + 1);
    visited.resize(n + 1);
    for (int i = 0; i < m; i++){
        int v1,v2; cin >> v1 >> v2;
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++){
        if (!visited[i]){
            dfs(i);
            ans++;
        }
    }

    cout << ans << '\n';
    return 0;
}
    
        
        
        
     
        
        
    

