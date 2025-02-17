#include<iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        long long res = 1e9;
        for(int i = 0; i < 10; i++){
            if(b + i == 1) continue;
            long long cnt = i;
            long long x = a;
            while(x){
                x /= (b + i);
                cnt++;
            }
            res = min(res, cnt);
        }
        cout << res << endl;
    }
}