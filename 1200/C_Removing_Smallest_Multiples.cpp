#include<iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;
        string s;
        cin >> s;
        string mark(n, '0');
        long long res = 0;
        for(long long i = 0; i < n; i++){
            if(s[i] == '0'){
                for(long long j = i + 1; j <= n; j += i + 1){
                    if(s[j - 1] == '1') break;
                    if(mark[j - 1] == '1') continue;

                    mark[j - 1] = '1';
                    res += i + 1;
                }
            }
        }

        cout << res << endl;
    }
}