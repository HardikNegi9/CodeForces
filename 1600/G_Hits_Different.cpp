#include<iostream>
#include<vector>
using namespace std;
int main(){

    long long curr = 1;
    vector<vector<long long>> dp(1500, vector<long long> (1500, 0));
    vector<long long> res(2e6 + 7);
    
    for(int i = 1; i < 1500; i++){
        for(int j = i - 1; j >= 1; j--){
            dp[j][i - j] = dp[j - 1][i - j] + dp[j][i - j - 1] - dp[j - 1][i - j - 1] + curr * curr;
            res[curr] = dp[j][i - j];
            curr++;
        }
    }


    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << res[n] << endl;
    }
}