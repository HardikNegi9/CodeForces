#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> nums(n + 1);
        for(int i = 1; i <= n; i++){
            cin >> nums[i];
        }

        vector<bool> dp(n + 1, false);
        dp[0] = true; // Base case: sum of 0 is always possible

        for(int i = 1; i <= n; i++){
            if(nums[i] + i <= n && dp[i - 1]){
                dp[nums[i] + i] = true;
            }
            if(i - nums[i] - 1 >= 0 && dp[i - nums[i] - 1]){
                dp[i] = true;
            }
        }


        cout << (dp[n] ? "YES" : "NO") << endl;
    }
}