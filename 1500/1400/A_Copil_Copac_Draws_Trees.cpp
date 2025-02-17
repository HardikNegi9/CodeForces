#include <iostream>
#include <vector>
using namespace std;

void dfs(int u, int p, vector<vector<pair<int, int>>>& edges, int& res, int idx, int itr) {
    res = max(res, itr);
    for(auto [v, id] : edges[u]) {
        if(v == p) {
            continue;
        }
        dfs(v, u, edges, res, id, itr + (id < idx));
    }
}



int solve() {
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> edges(n);
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        edges[u].push_back({v, i});
        edges[v].push_back({u, i});
    }
    
    int res = 1;
    dfs(0, -1, edges, res, -1, 1);
    
    return res;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        cout << solve() << endl;
    }
    return 0;
}