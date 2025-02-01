#include<iostream>
using namespace std;

long long solve(long long n){
    long long res = 0;
    while(n > 0){
        res += n;
        n /= 2;
    }
    return res;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;

        cout << solve(n) << endl;
    }
}