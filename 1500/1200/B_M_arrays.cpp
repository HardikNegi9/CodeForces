#include<iostream>
#include<vector>
#include<map>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }

        map<int, long long> mp;
        for(int i = 0; i < n; i++){
            mp[(a[i] % k)]++;
        }

        int res = 0;
        for(auto [num, freq] : mp){
            int rem = (k - num) % k;
            
            if(num == 0 && freq > 0){
                res++;
            }
            else if(num * 2 == k && freq > 0){
                res++;
            }
            else if(mp.count(rem) == 0){
                res += freq;
            }
            else if(num < rem){
                int diff = abs(mp[num] - mp[rem]);
                if(diff <= 1){
                    res++;
                }else{
                    res += diff;
                }
            }
        }

        cout << res << endl;
    }
    return 0;
}