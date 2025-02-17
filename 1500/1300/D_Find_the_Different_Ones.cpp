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
        for(int i=0; i<n; i++){
            cin >> nums[i];
        }

        vector<int> next(n);
        next[n - 1] = n;
        for(int i=n-2; i>=0; i--){
            if(nums[i] == nums[i+1]){
                next[i] = next[i+1];
            }else{
                next[i] = i+1;
            }
        }

        int q;
        cin >> q;
        while(q--){
            int l, r;
            cin >> l >> r;
            l--; r--;
            if(next[l] <= r){
                cout << l + 1 << " " << next[l] + 1 << endl;
            }else{
                cout << -1 << " " << -1 << endl;
            }
        }
        cout << endl;   
    }
}