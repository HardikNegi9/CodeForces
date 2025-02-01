#include<iostream>
#include<vector>
using namespace std;


long long solve(int n, int i, vector<int> a, int prev, vector<vector<long long>> &dp){
    if(i == n) return 0;
    if(dp[i][prev + 1] != -1) return dp[i][prev + 1];
    
    int not_take = solve(n, i + 1, a, prev, dp);
    int take = 0;
    if(prev == -1 || a[i] % a[prev] == 0) take = solve(n, i + 1, a, i, dp) + 1;

    return dp[i][prev + 1] = max(take, not_take);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<long long> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }

        vector<vector<long long>> dp(n, vector<long long>(n + 1, -1));

        int res = solve(n, 0, a, -1, dp);

        cout << res << endl;

    }
}