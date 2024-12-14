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
        for(int i = 0; i < n; i++){
            cin >> nums[i];
        }

        map<int, int> cnt;
        for(int num : nums){
            for(int i = 2; i*i <= num; i++){
                while(num % i == 0){
                    cnt[i]++;
                    num /= i;
                }
            }
            if(num > 1){
                cnt[num]++;
            }
        }

        bool flag = true;
        for(auto [p, freq] : cnt){
            if(freq % n != 0){
                flag = false;
                break;
            }
        }

        if(flag){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}