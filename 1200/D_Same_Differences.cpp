#include<iostream>
#include<vector>
#include<map>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<long long> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        map<long long, long long> mp;
        long long res = 0;

        for(int i = 0; i < n; i++){
            res += mp[a[i] - i];
            mp[a[i] - i]++;
        }

        cout << res << endl;

    }
}