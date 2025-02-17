#include<iostream>
#include<vector>
using namespace std;

long long solve(int i, vector<long long> &a, vector<long long> &dp, int n){
    if(i > n) return 0;
    if(dp[i] != -1) return dp[i];
    long long res = 1;
    for(int j = i + i; j <= n; j += i){
        if(a[i] < a[j]) res = max(solve(j, a, dp, n) + 1, res);
    }

    return dp[i] = res;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<long long> a(n + 1);
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }

        vector<long long> dp(n + 1, -1);
        long long res = 1;

        for(int i = 1; i < n; i++) res = max(res, solve(i, a, dp, n));
        cout << res << endl;    
    }
}