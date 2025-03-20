#include<iostream>
#include<vector>
#include<functional>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<long long> nums(n);
        long long mx = -1;
        for(int i = 0; i < n; i++){
            cin >> nums[i];
            mx = max(mx, nums[i]);
        }

        
        function <bool(long long)> solve = [&] (long long mid) -> bool{
            if(mid <= mx) return true;
            
            for(int i = 0; i < n - 1; i++){

                long long tempK = k;
                long long target = mid;
                long long idx = i;
                
                while(tempK >= 0 && idx < n){
                    if(nums[idx] >= target) return true;
                    tempK -= (target - nums[idx]);
                    target--;
                    idx++;
                }
            }
            return false;
        };
        
        
        
        long long res = 0;
        long long left = 0, right = 1e9;
        while(left <= right){
            int mid = left + (right - left) / 2;

            if(solve(mid)){
                res = mid;
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }


        cout << res << endl;

    }
}