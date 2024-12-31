#include<iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        long long n, k;
        cin >> n >> k;
        long long res = n;
        for(long long i = 1; i * i <= n; i++){
            if(n % i == 0){
                if(i <= k) res = min(res, n / i);
                if(n / i <= k) res = min(res, i);
            }
        }
        cout << res << endl;
    }    
}

