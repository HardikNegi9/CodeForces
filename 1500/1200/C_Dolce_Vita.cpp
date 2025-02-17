#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main(){
    int t;
    cin>> t;
    while(t--){
        int n, x;
        cin >> n >> x;
        vector<int> nums(n);
        for(int i = 0; i < n; i++){
            cin >> nums[i];
        }

        sort(nums.begin(), nums.end());
        vector<long long> pre(n);
        pre[0] = nums[0];
        for(int i = 1; i < n; i++){
            pre[i] = pre[i-1] + nums[i];
        }

        // tn = a + (n - 1)*d;
        // (tn - a)/d + 1 = n;

        long long res = 0;
        for(int i = 0; i < n; i++){
            long long diff = x - pre[i];
            long long d = i + 1;
            if(diff >= 0) res += diff/d + 1;
        }
        
        cout << res << endl;
    }
}