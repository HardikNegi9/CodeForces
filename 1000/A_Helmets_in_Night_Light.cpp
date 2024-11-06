#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;

        vector<pair<long long, long long>> a(n + 1);
        a[n] = {k, n + 1};
        for(int i = 0; i < n; i++){
            cin >> a[i].second;
        }
        for(int i = 0; i < n; i++){
            cin >> a[i].first;
        }
        sort(a.begin(), a.end());

        long long ans = k;
        int i = 0;
        int total = 1;

        while(total < n){
            long long cost = a[i].first;
            long long count = a[i].second;
            i++;
            int rem = n - total;
            
            if(count <= rem){
                total += count;
                ans += cost * count * 1ll;
            }else{
                ans += cost * rem * 1ll;
                total += rem;
            }
        }
        cout << ans << endl;
    }
}