#include<iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        int left = 0, right = 0;
        int b = 0, w = 0;

        while(right < k){
            if(s[right++] == 'W') w++;
            else b++;
        }
        int res = k - b;
        while(right < n){
            if(s[right++] == 'W') w++;
            else b++;
            if(s[left++] == 'W') w--;
            else b--;

            res = min(res, k - b);
        }
        
        cout << res << endl;
        
    }
}