#include<iostream>
using namespace std;

bool isprime(int n){
    for(int i = 2; i*i <= n; i++){
        if(n % i == 0) return false;
    }
    return true;
}

int findprime(int n){
    for(int i = n;; i++){
        if(isprime(i)) return i;
    }
    return 1e9;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int d;
        cin >> d;
        long long p = findprime(d + 1);
        long long q = findprime(p + d);

        cout << min(1ll*p*p*p, 1ll*p*q) << endl;
    }
}