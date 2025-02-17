#include<iostream>
using namespace std;

int main(){
    long long n;
    cin >> n;
    if(n == 1){
        cout << 4;
    }else if(n & 1){
        cout << (n + 1ll) * (n + 3ll) / 2;
    }else{
        n = n >> 1;
        cout << (n + 1ll)*(n + 1ll);
    }
}

