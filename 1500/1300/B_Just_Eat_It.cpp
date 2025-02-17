#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> nums(n);
        for(int i = 0; i < n; i++) cin >> nums[i];

        long long sum = 0;
        long long res = 0;
        long long curr_sum = 0;
        for(int i = 0; i < n - 1; i++){
            sum += nums[i];
            curr_sum += nums[i];
            if(curr_sum < 0) curr_sum = 0;
            res = max(res, curr_sum);
        }

        sum += nums[n - 1];
        curr_sum = 0;
        for(int i = 1; i < n; i++){
            curr_sum += nums[i];
            if(curr_sum < 0) curr_sum = 0;
            res = max(res, curr_sum);
        }

        if(res < sum) cout << "YES" << endl;
        else cout << "NO" << endl;

    }
}
 
