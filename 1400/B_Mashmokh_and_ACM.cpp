#include<iostream>
#include<vector>

using namespace std;

int solve(int n, int k, vector<vector<int>>& dp, int prev){
    
    if(k <= 0) return k == 0;
    if(dp[k][prev] != -1) return dp[k][prev];

    int mod = 1e9 + 7;

    long long res = 0;
    for(int i = prev; i <= n; i += prev){
        res = (res + solve(n, k - 1, dp, i)) % mod;
    }

    return dp[k][prev] = res;
}

int main(){
    int n, k;
    cin >> n >> k;

    vector<vector<int>> dp(k + 1, vector<int>(n + 1, -1));
    int mod = 1e9 + 7;


    long long res = 0;
    for(int i = 1; i <= n; i++){
        res = (res + solve(n, k - 1, dp, i)) % mod;
    }

    cout << res;
}