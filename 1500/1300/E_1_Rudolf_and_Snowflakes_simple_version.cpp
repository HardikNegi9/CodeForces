#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n = 1e6 + 1;
    vector<bool> valid(n, false);

    for(long long i = 2;; i++){
        long long val = 1 + i + i * i;
        long long x = i * i;
        if(val > n){
            break;
        }
        while(val <= n){
            valid[val] = true;
            val += x*i;
            x *= i;
        }
    }

    int t;
    cin >> t;
    while(t--){
        int x;
        cin >> x;
        cout << (valid[x] ? "YES" : "NO") << endl;
    }
}