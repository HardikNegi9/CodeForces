#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; 
    cin >> t;

    vector<int> nums;
    
    for(int i = 1; i <= 40004; i++){
        string s = to_string(i);
        bool isPalindrome = true;
        for(int i = 0, j = s.size()-1; i < j; i++, j--){
            if(s[i] != s[j]){
                isPalindrome = false;
                break;
            }
        }
        if(isPalindrome){
            nums.push_back(i);
        }
    }

    int n = nums.size();
    const int mod = 1e9 + 7;

    vector<vector<long long>> dp(n + 1, vector<long long> (40005, 0));
    dp[0][0] = 1;

    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= 40004; j++){
            dp[i][j] = dp[i-1][j];
            if(j >= nums[i-1]){
                dp[i][j] = (dp[i][j] + dp[i][j - nums[i-1]]) % mod;
            }
        }
    }

    while(t--){
        int num; 
        cin >> num;
        cout << dp[n][num] << '\n';
    }
    
    return 0;
}