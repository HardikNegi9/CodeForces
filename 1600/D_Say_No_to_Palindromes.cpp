#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n, q; cin >> n >> q;
    string s; cin >> s;
    vector<string> permutations = {"abc", "acb", "bac", "bca", "cab", "cba"};
    vector<vector<int> > dp(6, vector<int>(n + 1, 0));

    for(int i = 0; i < 6; i++){
        for(int j = 0; j < n; j++){
            dp[i][j + 1] = dp[i][j] + (permutations[i][j % 3] != s[j]);
        }
    }

    while(q--){
        int l, r; cin >> l >> r; l--; r--;
        int ans = 1e9;
        for(int i = 0; i < 6; i++){
            ans = min(ans, dp[i][r + 1] - dp[i][l]);
        }
        cout << ans << endl;
    }
}