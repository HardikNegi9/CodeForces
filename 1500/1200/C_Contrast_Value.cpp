#include<iostream>
#include<vector>
#include <algorithm>
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

        nums.resize(unique(nums.begin(), nums.end()) - nums.begin());
        int res = 0;
        n = nums.size();
        for(int i = 0; i < n; i++){

            if(i == 0 || i == n - 1 ||
            (nums[i - 1] > nums[i] && nums[i] < nums[i + 1])
            || (nums[i - 1] < nums[i] && nums[i] > nums[i + 1])){
                res++;
            }
        }

        cout << res << endl;
    }
}