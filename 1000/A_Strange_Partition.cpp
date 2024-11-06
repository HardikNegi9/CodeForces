#include<iostream>
#include<vector>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        long long n, x;
        cin >> n >> x;
        vector<long long> nums(n);
        for(long long i = 0; i < n; i++){
            cin >> nums[i];
        }

        long long mx = 0;
        long long mn = 0;
        for(int i : nums){
            mx += (i + x - 1) / x;
            mn += i;
        }

        cout << (mn + x - 1) / x << " " << mx << endl;
    }
}
