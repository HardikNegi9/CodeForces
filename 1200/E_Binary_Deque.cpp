#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for(int i = 0; i < n; i++){
            cin >> nums[i];
        }

        int left = 0;
        int count = 0;
        int res = -1;
        for(int right = 0; right < n; right++){
            count += nums[right];

            while(count > k){
                count -= nums[left];
                left++;
            }

            if(count == k) res = max(res, right - left + 1);

        }
        if(res == -1) cout << -1 << endl;
        else cout << n - res << endl;
    }

}