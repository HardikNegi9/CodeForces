#include<iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        long long a = 1;
        for(long long i = 2; i*i <= n; i++){
            if(n % i == 0){
                a = n / i;
                break;
            }
        }

        cout << a << " " << n - a << endl;
    }
}