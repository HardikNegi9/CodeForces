#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<long long> a(n);
        for(int i=0; i<n; i++){
            cin >> a[i];
        }

        long long xor_sum = 0;
        bool checked = false;

        for(int i = 0; i < n; i++){
            xor_sum ^= a[i];
            long long x = 0;
            bool flag = false;

            for(int j = i + 1; j < n; j++){
                x = x ^ a[j];
                if(x == xor_sum){
                    flag = true;
                    x = 0;
                }
            }
            
            if(flag && x == 0){
                checked = true;
                break;
            }
        }

        cout << (checked ? "YES" : "NO") << endl;
        
    }
}