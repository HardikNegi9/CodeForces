#include<iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        long long a,b;
        cin >> a >> b;
        if(a == b) cout << 0 << " "<< 0 << endl;
        else{
            long long diff = abs(a - b);
            long long diff1 = b % diff;
            long long diff2 = diff - diff1;
            cout << diff << " " << min(diff1, diff2) << endl;
        }
    }
}



// 8 - 5  = 3;
// 5 % 3 = 2;
// 