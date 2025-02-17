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
        int ans = nums[0];
        for(int i = 1; i < n; i++){
            ans &= nums[i];
        }

        cout << ans << endl;

    }
}