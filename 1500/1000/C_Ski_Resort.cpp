#include<iostream>
#include<vector>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        long long n, k, q;
        cin >> n >> k >> q;
        vector<int> nums(n);
        for(int i = 0; i < n; i++){
            cin >> nums[i];
        }
        long long res = 0;
        long long count = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] <= q){
                count++;
            }else{
                if(count >= k){
                    long long subarr_k = (count*1ll*(count + 1)) /2;
                    long long subarr_kn = (k - 1)*count - ((k - 2)*(k - 1))/2;
                    res += subarr_k - subarr_kn;
                }
                count = 0;
            }
        }
        if(count >= k){
            long long subarr_k = (count*1ll*(count + 1)) /2;
            long long subarr_kn = (k - 1)*count - ((k - 2)*(k - 1))/2;
            res += subarr_k - subarr_kn;
        }
        cout <<  res << endl;
    }
}