#include<iostream>
#include<vector>
using namespace std;

long long solve(vector<int> &nums, int i, bool turn, vector<vector<int>> &dp){
    if(i >= nums.size()) return 0;
    if(dp[i][turn] != -1) return dp[i][turn];
    
    long long res = LLONG_MAX;
    if(turn){
        // 2 step
        if(i+1 < nums.size()){
            res = solve(nums, i+2, !turn, dp) + nums[i] + nums[i+1];
        }
        res = min(solve(nums, i+1, !turn, dp) + nums[i], res);
    }else{
        res = min(solve(nums, i+1, !turn, dp), solve(nums, i+2, !turn, dp));
    }

    return dp[i][turn] = res;
}



int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        vector<int> nums(n);
        for(int i=0; i<n; i++){
            cin >> nums[i];
        }

        vector<vector<int>> dp(n + 1, vector<int> (2, -1));


        cout << solve(nums, 0, true, dp) << endl;
    }
}