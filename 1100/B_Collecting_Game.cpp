#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
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

        map<long long, int> map;
        vector<long long> b(a.begin(), a.end());
        sort(b.begin(), b.end());
        vector<long long> pre(n);
        pre[0] = b[0];
        for(int i = 1; i < n; i++){
            pre[i] = pre[i-1] + b[i];
        }

        map[b[n-1]] = n - 1;
        for(int i = n - 2; i >= 0; i--){
            map[b[i]] = pre[i] >= b[i + 1] ? map[b[i + 1]] : i;
        }

        for(int i = 0; i < n; i++){
            cout << map[a[i]] << " ";
        }
        cout << endl;
    }
}