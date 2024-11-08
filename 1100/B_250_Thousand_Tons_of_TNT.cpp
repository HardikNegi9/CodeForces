#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

int main(){
    int n = 150001;
    vector<vector<int>> div(n);
    
    for(int i = 1; i < n; i++){
        for(int j = 2*i; j < n; j += i){
            div[j].push_back(i);
        }
    }

    int t;
    cin >> t;
    while(t--){
        cin >> n;
        vector<long long> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }

        long long res = 0;
        for(int i : div[n]){
            long long mn = 1e18, mx = -1e18;
            long long sum;
            for(int j = 0; j < n; j+=i){
                sum = accumulate(a.begin() + j, a.begin() + j + i, 0ll);
                mn = min(mn, sum);
                mx = max(mx, sum);
            }
            res = max(res, mx - mn);
        }

        cout << res << endl;
    }    
}