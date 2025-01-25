#include<iostream>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        long long n, x, y;
        cin >> n >> x >> y;
        long long sum = 0;
        for(int i = 0; i < n; i++){
            long long t;
            cin >> t;
            sum += t;
        }

        if((sum + x) % 2 == (y%2)) {
            cout<<"Alice"<<endl;
        } else {
            cout<<"Bob"<<endl;
        }


    }
}