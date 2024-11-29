#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int t;
    cin>> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> nums(n);
        for(int i = 0; i < n; i++){
            cin >> nums[i];
        }

        if(is_sorted(nums.begin(), nums.end())){
            cout << 0 << endl;
            continue;
        }
        
        if(nums[n - 1] < nums[n - 2] || nums[n - 1] < 0){
            cout << -1 << endl;
            continue;
        }


        cout << n - 2 << endl;
        for(int i = n - 3; i >= 0; i--){
            cout << i + 1 << " " << n - 1 << " " << n << endl;
        }
    }
}