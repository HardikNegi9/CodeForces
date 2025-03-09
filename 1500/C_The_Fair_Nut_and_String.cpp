#include<iostream>
using namespace std;

int main(){
    string s;
    cin >> s;

    long long pre = 0, res = 0;
    int mod = 1e9 + 7;

    for(char c : s){
        if(c == 'a'){
            res += pre + 1;
            res %= mod;
        }else if(c == 'b'){
            pre = res;
        }
    }

    cout << res << endl;
    
}