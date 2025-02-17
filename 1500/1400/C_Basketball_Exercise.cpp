#include<iostream>
#include<vector>
using namespace std;

long long solve(vector<int> &a, vector<int> &b, int i, bool turn, int n, vector<vector<long long>> &dp){
    if(i == n) return 0;
    if(dp[i][turn] != -1) return dp[i][turn];

    long long take = solve(a, b, i + 1, !turn, n, dp) + (turn ? a[i] : b[i]);
    long long leave = solve(a, b, i + 1, turn, n, dp);

    return dp[i][turn] = max(take, leave);

}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    vector<vector<long long>> dp(n, vector<long long>(2, -1));
    long long res = solve(a, b, 0, true, n, dp);
    res = max(res, solve(a, b, 0, false, n, dp));

    cout << res << endl;

}