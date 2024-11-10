#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<long long> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }

        int left = 0, right = n - 1;
        sort(a.begin(), a.end());
        vector<long long> pre(n + 1);

        pre[0] = 0;
        for(int i = 1; i <= n; i++){
            pre[i] = a[i - 1] + pre[i - 1];
        }
        long long res = 0;
        for(int i = 0; i <= k; i++){
            res = max(res, pre[n - i] - pre[2*(k - i)]);
        }
        cout << res << endl;
    }
}