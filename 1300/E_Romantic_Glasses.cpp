#include<iostream>
#include<vector>
#include<map>
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

        map<long long, int> mp;
        long long sum = 0;
        bool flag = false;
        mp[0] = -1;
        for(int i = 0; i < n; i++){
            if(i&1){
                sum -= nums[i];
            }else{
                sum += nums[i];
            }
            if(mp.count(sum)){
                flag = true;
                break;
            }
            mp[sum] = i;
        }

        if(flag){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}
