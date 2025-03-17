#include<iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;

        long long res = 1;
        for(char c : s){
            int d = c - '0' + 1;
            res *= (d * (d + 1)) / 2;

        }

        cout << res << endl;
    }
}