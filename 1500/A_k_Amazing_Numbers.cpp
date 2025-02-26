#include<iostream>
#include<vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<vector<int>> pos(n+1);
    
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        pos[a[i]].push_back(i);
    }
    
    vector<int> ans(n+1, -1);
    
    for(int num = 1; num <= n; num++) {
        int sz = (int)pos[num].size();
        if(!sz) continue;
        
        int mx = pos[num][0] + 1;
        
        for(int j = 0; j < sz - 1; j++) {
            mx = max(mx, pos[num][j+1] - pos[num][j]);
        }
        
        mx = max(mx, n - pos[num][sz-1]);
        
        if(ans[mx] == -1 || num < ans[mx]) {
            ans[mx] = num;
        }
    }
    
    int mn = 1e9;
    for(int k = 1; k <= n; k++) {
        if(ans[k] != -1) {
            mn = min(mn, ans[k]);
        }
        ans[k] = (mn == 1e9) ? -1 : mn;
        cout << ans[k] << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}