#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        vector<int> dp(a.begin(), a.end());

        for(int i = n - 2; i >= 0; i--){
            int ele = abs(a[i]);
            int next = abs(a[i + 1]);
            if((next&1 && !(ele&1)) 
            || (!(next&1) && ele&1)){
                dp[i] = max(dp[i + 1] + a[i], a[i]);
            }
        }

        int res = dp[0];
        for(int i = 1; i < n; i++){
            res = max(res, dp[i]);
        }
        cout << res << endl;
    }
}
