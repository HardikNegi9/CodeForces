#include<iostream>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        long long n, x;
        cin >> n >> x;
        
        long long mx = LLONG_MAX, mn = n;
        bool flag = false;

        for(int i = 0; i < 64; i++){
            long long bit = (1LL << i);


            if(!(n & bit) && (x & bit)){ // 0 1
                flag = true;
                break;
            }
            if((n & bit) && !(x & bit)){ // 1 0
                mn = max(mn,((n >> i) << i) + bit);
            }
            if((n & bit) && (x & bit)){ // 1 1
                mx = min(mx, ((n >> i) << i) + bit - 1);
            }
        }

        if(flag || mn > mx){
            cout << -1 << endl;
        } else {
            cout << mn << endl;
        }
    }
}