#include<iostream>
#include<string>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        bool res = true;

        int zeros = 0;
        int ones = 0;
        
        for(int i = 0; i < k; i++){
            char prev = '?';
            for(int j = i; j < n; j += k){
                if(s[j] != '?'){
                    if(prev == '?'){
                        prev = s[j];
                    }else if(prev != s[j]){
                        cout << "NO" << endl;
                        res = false;
                        break;
                    }
                }
            }

            if(!res) break;

            if(prev == '1') ones++;
            else if(prev == '0') zeros++;
        }

        if(!res) continue;
        
        if(ones > k/2 || zeros > k/2){
            cout << "NO" << endl;
        }else{
            cout << "YES" << endl;
        }
    }
}