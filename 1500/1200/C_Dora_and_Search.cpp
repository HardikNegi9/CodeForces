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

        for(int i = 0; i < n; i++){
            cin >> nums[i];
        }

        int left = 0;
        int right = n - 1;

        int mn = 1;
        int mx = n;

        while(left < right){
            if(nums[left] == mn || nums[left] == mx){
                if(nums[left] == mn) mn++;
                else mx--;
                left++;
            }
            if(nums[right] == mx || nums[right] == mn){
                if(nums[right] == mx) mx--;
                else mn++;
                right--;
            }
            if(nums[left] != mn && nums[left] != mx &&
            nums[right] != mn && nums[right] != mx){
                break;
            }
        }

        if(left < right) cout << left + 1 << " " << right + 1 << endl;
        else cout << "-1" << endl;
    }
}