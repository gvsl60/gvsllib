#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    
    int n,m; cin >> n >> m;
    vector<vector<int>> adj(n + 1);

    for (int i = 1; i <= m; i++){
        int v1,v2; cin >> v1 >> v2;
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);

    }
    vector<bool> visited(n + 1);
    queue<int> q;
    int ans = 0;
    
    for (int i = 1; i <= n; i++){
        if (q.empty() && visited[i] == false){
            ans++;
            q.push(i);
            visited[i] = true;

        }
    while(!q.empty()){
        int atual = q.front();
        q.pop();
        for (int num : adj[atual]){
            if (!visited[num]){
                visited[num] = true;
                q.push(num);
            }
        }
    }
}
cout << ans << '\n';
    return 0;


}
