#include<iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s, r;
        cin >> s >> r;
        int n = s.size();
        int m = r.size();

        int res = n + m;

        for(int i = 0; i < n; i++){
            for(int j = 1; j <= n - i; j++){
                string sub = s.substr(i, j);
                if(r.find(sub) != string::npos){
                    res = min(res, n + m - 2*j);
                }
            }
        }
        cout << res << endl;
    }
}