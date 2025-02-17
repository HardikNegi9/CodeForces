#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> nums(n);

        long long count_0 = 0;
        long long count_1 = 0;
        for(int i = 0; i < n; i++){
            cin >> nums[i];
            if(nums[i] == 1) count_1++;
            if(nums[i] == 0) count_0++;
        }
        if(count_1 == 0) cout << 0 << endl;
        else{
            cout << count_1 * (1ll << count_0) << endl;
        }

    }
}