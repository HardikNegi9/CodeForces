#include<iostream>
#include<vector>

using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> nums(n*k);
        for(int i = 0; i < n*k; i++){
            cin >> nums[i];
        }
        int i = n*k;
        long long sum = 0;
        while(k--){
            i -= n/2 + 1;
            sum += nums[i];
        }
        cout << sum << endl;
    }
}