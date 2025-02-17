#include<iostream>
#include<vector>
#include<algorithm>

long long fac(int n){
    const int mod = 1e9 + 7;
    
    if(n == 0){
        return 1;
    }
    return (n * fac(n - 1)) % mod;
}   


using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        const int mod = 1e9 + 7;

        for(int i = 0; i < n; i++){
            cin >> a[i];
        }

        int ele = a[0];
        for(int i = 1; i < n; i++){
            ele &= a[i];
        }

        long long cnt = count(a.begin(), a.end(), ele);

        cnt = (cnt * (cnt - 1)) % mod;

        cout << (cnt * fac(n - 2)) % mod << endl;
        
    }
}