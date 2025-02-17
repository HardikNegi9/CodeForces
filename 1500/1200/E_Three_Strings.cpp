#include<iostream>
#include<string>
#include<functional>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string a, b, c;
        cin >> a >> b >> c;
        int n = a.size();
        int m = b.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        function<int(int ,int)> solve = [&] (int i, int j){
            if(i == n && j == m) return 0;
            if(dp[i][j] != -1) return dp[i][j];

            //take from a
            int ans_a = 1e9; 
            if(i < n) ans_a = solve(i + 1, j) + (a[i] != c[i + j]);

            //take from b
            int ans_b = 1e9; 
            if(j < m) ans_b = solve(i, j + 1) + (b[j] != c[i + j]);

            return dp[i][j] = min(ans_a, ans_b);

        };

        cout << solve(0, 0) << endl;
    }
}