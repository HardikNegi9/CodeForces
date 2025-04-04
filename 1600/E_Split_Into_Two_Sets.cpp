#include<iostream>
#include<vector>
using namespace std;


int dfs(int node, vector<vector<int>>& adj, vector<int>& vis){
    vis[node] = 1;
    for(auto it : adj[node]){
        if(vis[it] == 0){
            return 1 + dfs(it, adj, vis);
        }
    }

    return 1;
}




int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<int>> adj(n + 1);
        bool flag = false;

        for(int i = 1; i <= n; i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            
            if(u == v || adj[u].size() > 2 || adj[v].size() > 2){
                flag = true;
            }
        }

        if(flag){
            cout << "NO" << endl;
            continue;
        }

        vector<int> vis(n + 1, 0);

        for(int i = 1; i <= n; i++){
            if(vis[i]) continue;
            if(dfs(i, adj, vis) & 1){
                flag = true;
                break;
            }
        }

        if(flag){
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
}