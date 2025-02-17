#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(m + 1);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        for(int i = 1; i <= m; i++){
            cin >> b[i];
        }

        sort(a.rbegin(), a.rend());
        long long res = 0;

        int j = 1;
        for(int i : a){
            int val = min(b[i], b[j]);
            if(val == b[j] && i != j) j++;
            res += val;
        }

        cout << res << endl;
    }
}