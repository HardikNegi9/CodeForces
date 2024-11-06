#include<iostream>
using namespace std;

bool solve(long long n){
    string s = to_string(n);

    for(char c : s){
        if(c != '0' && n % (c - '0') != 0){
            return true;
        }
    }
    return false;
}



int main(){
    int t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;
        
        while(solve(n)){
            n++;
        }

        cout << n << endl;
    }
}