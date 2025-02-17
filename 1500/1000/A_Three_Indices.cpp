#include<iostream>
#include<vector>
#include<stack>

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
        int i;
        for(i = 1; i < n - 1; i++){
            if(nums[i - 1] < nums[i] && nums[i] > nums[i + 1]){
                cout << "YES" << endl;
                cout << i << " " << i + 1 << " " << i + 2 << endl;
                break;
            }
        }
        if(i == n - 1){
            cout << "NO" << endl;
        }
    }
}