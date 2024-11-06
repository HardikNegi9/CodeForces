#include<iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        long long x, y, k;
        cin >> x >> y >> k;

        long long trades = k + y*k - 1;
        long long sticks = x - 1;
        
        if(trades % sticks == 0) cout << trades/sticks + k << endl;
        else cout << trades/sticks + k + 1ll << endl;
    }
}