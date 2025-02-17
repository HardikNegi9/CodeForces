#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, l, r;
        cin >> n >> l >> r;
        vector<long long> res;
        for(int i = 1; i <= n; i++){
            long long a = ((l - 1) / i + 1) * i;
            if(a > r){
                break;
            }
            res.push_back(a);
        }
        if(res.size() == n) {
            cout << "YES" << endl;
            for(int i = 0; i < n; i++){
                cout << res[i] << " ";
            }
            cout << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}