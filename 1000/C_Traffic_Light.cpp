#include<iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        char c;
        cin >> c;
        string s;
        cin >> s;
        s += s;

        int res = -1e9;
        int prev = -1;

        for(int i = n*2 - 1; i >= 0; i--){
            if(s[i] == 'g'){
                prev = i;
            }
            if(s[i] == c){
                res = max(res, prev - i);
            }
        }
        cout << res << endl;
    }
}