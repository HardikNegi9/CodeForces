#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

long long _gcd(long long a, long long b){
    if(b == 0){
        return a;
    }
    return _gcd(b, a%b);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<long long> vec(n);
        for(int i=0; i<n; i++){
            cin >> vec[i];
        }

        long long prefix = accumulate(vec.begin(), vec.end(), 0ll);
        long long res = 1;
        long long suffix = 0;

        for(int i = n - 1; i > 0; i--){
            suffix += vec[i];
            prefix -= vec[i];
            res = max(res, _gcd(prefix, suffix));
        }

        cout << res << endl;
    }
}