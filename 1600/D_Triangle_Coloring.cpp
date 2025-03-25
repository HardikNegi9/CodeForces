#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long nCr(int n, int r){
    if(r > n - r) r = n - r;
    long long res = 1;
    for(int i = 0; i < r; i++){
        res = res * (n - i) / (i + 1);
    }
    return res;
}


int main(){
    int n;
    cin >> n;
    long long res = 1;
    const int mod = 998244353;
    for(int i = 0; i < n / 3; i++){
        int a, b, c;
        cin >> a >> b >> c;
        vector<int> v = {a, b, c};
        sort(v.begin(), v.end());
        
        if(v[0] == v[2]){
            res = (res * 3) % mod;
        } else if(v[0] == v[1] || v[1] == v[2]){
            res = (res * 2) % mod;
        }
    }

    res = nCr(n / 3, n / 6) * res % mod;

    cout << res / 2 << endl;
}