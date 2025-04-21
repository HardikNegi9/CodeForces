#include<iostream>
#include<vector>
#include<functional>
using namespace std;
int main(){
    long long t; cin >> t;
    while(t--){
        long long n, k; cin >> n >> k;
        const long long mod = 1e9 + 7;

        vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, -1));

        function<long long(long long, long long, long long)> solve = [&](long long forward, long long backward, long long decay) -> long long {
            if(forward == 0 || decay == 1) return dp[forward][decay] = 1;
            if(dp[forward][decay] != -1) return dp[forward][decay];
            
            return dp[forward][decay] = ( solve(backward, forward, decay - 1) + solve(forward - 1, backward + 1, decay) ) % mod;
        };


        cout << solve(n, 0, k) << endl;
    }
}