#include<iostream>
#include<vector>

using namespace std;

int solve(int i, vector<int> &nums, vector<int> &dp){
    if(i >= nums.size()) return i == nums.size() ? 0 : 1e9;
    if(dp[i] != -1) return dp[i];

    int notTake = solve(i + 1, nums, dp) + 1;

    int take = 1e9;

    if(nums[i] + i + 1<= nums.size()){
        take = solve(nums[i] + i + 1, nums, dp);
    }

    return dp[i] = min(take, notTake);

}

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;

        vector<int> nums(n);
        for(int i = 0; i < n; i++){
            cin >> nums[i];
        }

        vector<int> dp(n, -1);
        
        int res = solve(0, nums, dp);
        cout << (res >= 1e9 ? -1 : res) << endl;

    }
}