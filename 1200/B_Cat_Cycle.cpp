#include<iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        long long n , k;
        cin >> n >> k;
        
        if(n & 1){
            long long col_diff = n / 2;
            int coll = (k - 1) / col_diff;
            long long res = (coll + k - 1) % n + 1;
            cout << res << endl;
        }else{
            cout << (k - 1) % n + 1 << endl;
        }
    }
}