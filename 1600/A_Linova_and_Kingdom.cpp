#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

int solve(int n, vector<vector<int>>& a, vector<int>& cnt, vector<int>& visted, int depth){
    if(visted[n]) return 0;
    visted[n] = 1;
    int child = 0;
    for(int neb : a[n]){
        if(!visted[neb]){
            child += solve(neb, a, cnt, visted, depth + 1);
        }
    }
    cnt[n] = depth - child;
    return child + 1;
}



int main(){
    int n, k;
    cin >> n >> k;
    vector<vector<int>> a(n);
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    vector<int> cnt(n, 0), visted(n, 0);
    solve(0, a, cnt, visted, 0);
    sort(cnt.begin(), cnt.end(), greater<int>());
    cout << accumulate(cnt.begin(), cnt.begin() + k, 0ll) << endl;
}