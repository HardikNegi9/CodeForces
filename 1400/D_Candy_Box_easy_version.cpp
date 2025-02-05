#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for(int i = 0; i < n; i++){
            int x; cin >> x;
            a[x]++;
        }

        sort(a.begin(), a.end(), greater<int>());

        int val = a[0] - 1;
        long long res = a[0];
        for(int i = 1; i < n; i++){
            val = min(a[i], val) - 1;
            res += val + 1;
            if(val <= 0) break;
        }

        cout << res << endl;
    }
}