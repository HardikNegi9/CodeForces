#include<iostream>
#include<vector>
#include<functional>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.size();
        const int mod = 998244353;

        function<long long(int)> fact = [&](int x){
            long long res = 1;
            for(int i = 1; i <= x; i++){
                (res *= i) %= mod;
            }
            return res;
        };

        int count = 1;
        long long ways = 1;
        int dis = 1;

        for(int i = 1; i < n; i++){
            if(s[i - 1] != s[i]){
                (ways *= count) %= mod;
                dis++;
                count = 1;
            }else{
                count++;
            }
        }
        (ways *= count) %= mod;
        (ways *= fact(n - dis)) %= mod;
        cout << n - dis << " " << ways << endl;
    }
}