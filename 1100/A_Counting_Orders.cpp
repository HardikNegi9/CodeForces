#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n), b(n);
        for(int i = 0; i < n; i++){
            cin>>a[i];
        }
        for(int i = 0; i < n; i++){
            cin>>b[i];
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        long long res = 1;
        const int mod = 1e9 + 7;

        for(int i = 0; i < n; i++){
            res = (res * (lower_bound(b.begin(), b.end(), a[i]) - b.begin() - i)) % mod;
        }

        cout << res << endl;
    }
}