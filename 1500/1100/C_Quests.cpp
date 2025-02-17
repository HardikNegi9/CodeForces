#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        vector<int> b(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        for(int i = 0; i < n; i++){
            cin >> b[i];
        }

        int res = 0;
        int prev = 0;
        int mx = 0;
        for(int i = 0; i < min(k, n); i++){
            mx = max(mx, b[i]);
            prev += a[i];
            res = max(res, prev + mx*(k-i-1));
        }
        cout << res << endl;
    }
}