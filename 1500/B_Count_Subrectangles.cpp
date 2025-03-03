#include<iostream>
#include<vector>
using namespace std;


vector<long long> solve(vector<int> a){
    int n = a.size();
    vector<long long> cnt(n + 1, 0);
    
    int r = 0;

    while(r < n){
        while(a[r] == 0){
            r++;
            continue;
        }

        int l = r;

        while(l < n && a[l] == 1){
            l++;
        }

        int len = l - r;
        for(int i = 1; i <= len; i++){
            cnt[i] += len - i + 1;
        }
        r = l;
    }

    return cnt;
} 


int main(){
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n), b(m);

    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < m; i++)
        cin >> b[i];

    
    vector<long long> cnt1, cnt2;

    cnt1 = solve(a);
    cnt2 = solve(b);

    long long ans = 0;
    for(int i = 1; i <= n; i++){
        if(k % i == 0 && k / i <= m){
            ans += cnt1[i] * cnt2[k / i];
        }
    }

    cout << ans << endl;


}