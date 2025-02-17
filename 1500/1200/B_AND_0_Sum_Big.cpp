#include<iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        long long res = 1;
        int mod = 1e9 + 7;
        for(int i = 0; i < k; i++){
            res *= n;
            res %= mod;
        }
        cout << res << endl;
    }
}