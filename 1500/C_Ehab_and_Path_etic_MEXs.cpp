#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    vector<int> res(n, -1);
    int cnt = 0;
    int u, v;
    
    for(int i = 1; i < n; i++){
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(i);
        adj[v].push_back(i);
    }


    for(int i = 0; i < n; i++){
        if(adj[i].size() > 2){
            res[adj[i][0]] = cnt++;
            res[adj[i][1]] = cnt++;
            res[adj[i][2]] = cnt++;
            break;
        }
    }

    for(int i = 1; i < n; i++){
        if(res[i] == -1){
            res[i] = cnt++;
        }
    }

    for(int i = 1; i < n; i++)
        cout << res[i] << endl;
}