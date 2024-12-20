#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        vector<int> bits(32, 0);
        for(int i = 0; i < n; i++){
            cin >> a[i];
            for(int j = 0; j < 31; j++){
                if(a[i] & (1 << j)){
                    bits[j]++;
                }
            }
        }

        long long res = 0;
        for(int i = 30; i >= 0; i--){
            int bits_to_set = n - bits[i];
            if(bits_to_set <= k){
                k -= bits_to_set;
                res += (1ll << i);
            }
        }
        cout << res << endl;
    }
}