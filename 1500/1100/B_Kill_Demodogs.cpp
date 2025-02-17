#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;
        int mod = 1e9 + 7;

        long long res = 2022 / 6;
        res *= n;
        res %= mod;
        res *= (n + 1);
        res %= mod;
        res *= ((4*n) - 1);
        res %= mod;
        cout << res << endl;
    }
}