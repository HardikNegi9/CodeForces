#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void dfs(vector<vector<int>> &adj, int node, vector<long long> &cnt, int parent, int depth){
    cnt[depth % 2]++;
    for(int i = 0; i < adj[node].size(); i++){
        if(adj[node][i] != parent){
            dfs(adj, adj[node][i], cnt, node, depth + 1);
        }
    }
}


int main(){
    long long n;
    cin >> n;
    vector<vector<int>> adj(n);
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<long long> cnt(2, 0);

    dfs(adj, 0, cnt, 0, 0);

    long long ans = cnt[0] * cnt[1] - (n - 1);

    cout << ans << endl;
    
}