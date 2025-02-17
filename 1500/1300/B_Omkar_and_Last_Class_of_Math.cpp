#include<iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        if(n & 1){
            bool flag = true;
            for(int i = 2; i * i <= n; i++){
                if(n % i == 0){
                    flag = false;
                    cout << n / i << " " << n - n / i << endl;
                    break;
                }
            }
            if(flag) cout << n - 1 << " " << 1 << endl;
        }else{
            cout << n / 2 << " " << n / 2 << endl;
        }
    }
}