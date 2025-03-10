#include<iostream>
#include<vector>
using namespace std;


int dfs(vector<vector<int>> &adj, int u, vector<bool> &visted, int &res){
    visted[u] = true;
    int cnt = 1;
    for(int v : adj[u]){
        if(!visted[v]){
            cnt += dfs(adj, v, visted, res);
        }
    }

    if(cnt % 2 == 0){
        res++;
    }

    return cnt;
}




int main(){
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);

    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if(n & 1){
        cout << -1 << endl;
    }else{
        vector<bool> visted(n + 1, false);
        int res = 0;
        for(int i = 1; i < n; i++){
            dfs(adj, i, visted, res);
        }

        cout << res - 1 << endl;
    }
}